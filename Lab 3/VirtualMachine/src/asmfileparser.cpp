#include <QRegExp>
#include <QDebug>

#include "asmfileparser.h"

AsmFileParser::AsmFileParser(QFile& file)
    : fileAsm(file) { }

void AsmFileParser::parseFile() {
    QString line, cmd, argLeft, argRight, label;

    while (!fileAsm.atEnd()) {
        // read all lines from file

        line = fileAsm.readLine();
        line = removeEndl(line);
        if (line.isEmpty()) {
            continue;
        }

        bool c = parseLine(line, cmd, argLeft, argRight, label);
        if (!c) {
            qWarning() << "Wrong syntax:";
            qWarning() << line;

            return;
        }

        if (!label.isEmpty()) {
            label = label.replace(":", "");
            labelMap.insert(label, commandList.size());

        } else {
            commandList.append(Command(cmd, argLeft, argRight));
        }
    }

    /* now in commands like [JMP label]
       we shoul change [lable] to number instruction
       (take it from labelMap */

    int i = 1;
    for (Command& command : commandList) {
        if (command.instruction == "JMP"
            || command.instruction == "JE"
            || command.instruction == "JNE"
            || command.instruction == "JG"
            || command.instruction == "JL"
            || command.instruction == "JGE"
            || command.instruction == "JLE") {

            command.argLeft = QString::number(labelMap.value(command.argLeft));
        }

        ++i;
    }
}


bool AsmFileParser::parseLine(
        QString& src,
        QString& cmd,
        QString& argLeft,
        QString& argRight,
        QString& label) {
    static QRegExp rxLabel(R"((\s*)(\w+)(\s*):(\s*))");
    static QRegExp rxUnaryCommand(R"((\s*)(\w+)(\s+)(\w+)(\s*))");
    static QRegExp rxBinaryCommand(R"((\s*)(\w+)(\s+)(\w+)(\s*),(\s*)(\w+)(\s*))");

    cmd.clear();
    argLeft.clear();
    argRight.clear();
    label.clear();

    src = src.replace("\t", " ");

    if ((-1 == rxUnaryCommand.indexIn(src))
        && (-1 == rxLabel.indexIn(src))) {
        return false;
    }

    if ((rxUnaryCommand.matchedLength() != src.size())
            && (-1 == rxBinaryCommand.indexIn(src))
            && (-1 == rxLabel.indexIn(src))) {
        return false;
    }

    src = src.replace(" ", ",");
    QStringList list = src.split(",");
    list.removeAll(QString(""));

    if (list.size() == 1) {
        label = *list.begin();
        return true;
    }

    cmd = list[0];
    argLeft = list[1];

    if (list.size() > 2) {
        argRight = list[2];
    }

    return true;
}

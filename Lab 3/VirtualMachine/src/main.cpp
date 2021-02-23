#include <QString>
#include <QFile>

#include <QDebug>

#include "asmfileparser.h"

int main(int argc, char** argv)
{
    if (2 != argc) {
        qWarning() << "Incorrect arguments";
        qWarning() << "Usage: ./VMachine [path asm]";

        return -1;
    }

    QString pathAsm = argv[1];
    QFile fileAsm(pathAsm);

    fileAsm.open(QIODevice::ReadOnly);
    if (!fileAsm.exists()) {
        qWarning() << "No such file: " << pathAsm;

        return -1;
    }

    AsmFileParser parser(fileAsm);
    parser.parseFile();

    fileAsm.close();

    CommandList commandList = parser.getCommandList();
    commandList.run();

    return 0;
}

#ifndef VIRTUAL_MACHINE_ASMCOMMANDHANDLER_H
#define VIRTUAL_MACHINE_ASMCOMMANDHANDLER_H

#include <QFile>
#include <QMap>

#include "commandlist.h"

class AsmFileParser {
public:
    explicit AsmFileParser(QFile& file);

    void parseFile();

    inline CommandList getCommandList() {
        return std::move(commandList);
    }

private:
    bool parseLine(QString& src,
                   QString& cmd,
                   QString& argLeft,
                   QString& argRight,
                   QString& label);

    inline QString removeEndl(QString& line) {
        return line.replace("\r", "").replace("\n", "");
    }

private:
    QFile& fileAsm;
    CommandList commandList;

    // key = label name; value = instruction number
    QMap<QString, int> labelMap;
};


#endif //VIRTUAL_MACHINE_ASMCOMMANDHANDLER_H

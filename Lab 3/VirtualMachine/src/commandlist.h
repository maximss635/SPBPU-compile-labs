#ifndef COMMANDLIST_H
#define COMMANDLIST_H

#include <QString>
#include <QList>
#include <QMap>

struct Command {
    QString instruction;
    QString argLeft;
    QString argRight;

    Command(const QString& instruction,
            const QString& argLeft,
            const QString& argRight)
        : instruction(instruction)
        , argLeft(argLeft)
        , argRight(argRight) { }
};


class CommandList : public QList<Command> {
public:
    CommandList();

    void run();

private:
    int EIP;
    int flag;   // for commands like JNE

    bool exit;

    // key = var name; value = var value
    QMap<QString, int> varsMap;


    int registers[32];

private:
    void runCommand(Command& command);

    bool jmpHandle(Command& command);

    int getValue(QString& from);

    inline bool isRegister(QString& s) {
        static QRegExp rxRegister(R"(R(\d+))");
        return rxRegister.indexIn(s) != -1;
    }

    inline bool isNum(QString& s) {
        static QRegExp rxNum(R"(\d+)");
        return rxNum.indexIn(s) != -1;
    }

    inline void setRegister(int regNum, int newValue) {
        registers[regNum - 1] = newValue;
    }

    inline int getRegister(int regNum) {
        return registers[regNum - 1];
    }
};

#endif // COMMANDLIST_H

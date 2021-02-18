#include "commandlist.h"

#include <QDebug>

CommandList::CommandList()
    : exit(false) { }

void CommandList::run() {
    EIP = 0;
    int lastInstructionNum = this->size();

    while (EIP < lastInstructionNum || !exit) {
        try {
            runCommand((*this)[EIP]);
        }  catch (QString& e) {
            qWarning() << e;
            return;
        }

        ++EIP;
    }

}

void CommandList::runCommand(Command& command) {
//    qDebug() << command.instruction << command.argLeft << command.argRight;

    bool c = jmpHandle(command);
    if (c)
        return;

    if (command.instruction == "MOV" || command.instruction == "LDI") {
        if (isRegister(command.argLeft)) {
            setRegister(command.argLeft.mid(1).toInt(),
                        getValue(command.argRight));
        }
        else {
            // this is var
            if (varsMap.contains(command.argLeft)) {
                // var is defined
                varsMap[command.argLeft] = getValue(command.argRight);
            } else {
                // this is var definition
                // insert new element to map
                varsMap.insert(command.argLeft,
                               getValue(command.argRight));
            }

        }
    }

    else if (command.instruction == "CMP") {
        flag = getValue(command.argLeft) - getValue(command.argRight);
        return;
    }

    else if (command.instruction == "CALL") {
        if (command.argLeft == "print") {
            printf("[VM] %d\n", getRegister(1));
        }
    }

    else if (command.instruction == "ADD") {
        int regNum = command.argLeft.midRef(1).toInt();
        int oldValue = getRegister(regNum);
        int newValue = oldValue + getValue(command.argRight);
        setRegister(regNum, newValue);
    }

    else if (command.instruction == "SUB") {
        int regNum = command.argLeft.midRef(1).toInt();
        int oldValue = getRegister(regNum);
        int newValue = oldValue - getValue(command.argRight);
        setRegister(regNum, newValue);
    }

    else if (command.instruction == "MUL") {
        int regNum = command.argLeft.midRef(1).toInt();
        int oldValue = getRegister(regNum);
        int newValue = oldValue * getValue(command.argRight);
        setRegister(regNum, newValue);
    }

    else if (command.instruction == "DIV") {
        int regNum = command.argLeft.midRef(1).toInt();
        int oldValue = getRegister(regNum);
        int newValue = oldValue / getValue(command.argRight);
        setRegister(regNum, newValue);
    }

    else if (command.instruction == "AND") {
        int regNum = command.argLeft.midRef(1).toInt();
        int oldValue = getRegister(regNum);
        int newValue = oldValue & getValue(command.argRight);
        setRegister(regNum, newValue);
    }

    else if (command.instruction == "OR") {
        int regNum = command.argLeft.midRef(1).toInt();
        int oldValue = getRegister(regNum);
        int newValue = oldValue | getValue(command.argRight);
        setRegister(regNum, newValue);
    }

    else if (command.instruction == "XOR") {
        int regNum = command.argLeft.midRef(1).toInt();
        int oldValue = getRegister(regNum);
        int newValue = oldValue ^ getValue(command.argRight);
        setRegister(regNum, newValue);
    }

    else if (command.instruction == "LS") {
        int regNum = command.argLeft.midRef(1).toInt();
        int oldValue = getRegister(regNum);
        int newValue = oldValue << getValue(command.argRight);
        setRegister(regNum, newValue);
    }

    else if (command.instruction == "RS") {
        int regNum = command.argLeft.midRef(1).toInt();
        int oldValue = getRegister(regNum);
        int newValue = oldValue >> getValue(command.argRight);
        setRegister(regNum, newValue);
    }

    else if (command.instruction == "MOD") {
        int regNum = command.argLeft.midRef(1).toInt();
        int oldValue = getRegister(regNum);
        int newValue = oldValue % getValue(command.argRight);
        setRegister(regNum, newValue);
    }

    else if (command.instruction == "INC") {
        int regNum = command.argLeft.midRef(1).toInt();
        int oldValue = getRegister(regNum);
        int newValue = ++oldValue;
        setRegister(regNum, newValue);
    }

    else if (command.instruction == "DEC") {
        int regNum = command.argLeft.midRef(1).toInt();
        int oldValue = getRegister(regNum);
        int newValue = --oldValue;
        setRegister(regNum, newValue);
    }

    else if (command.instruction == "RET") {
        int exitCode = getValue(command.argLeft);
        printf("[VM] Programm exit with code %d\n", exitCode);
        exit = true;
    }

    else {
        throw QString("Unknown command: " + command.instruction);
    }
}

bool CommandList::jmpHandle(Command& command) {
    if (command.instruction == "JMP") {
        EIP = getValue(command.argLeft) - 1;
        return true;
    }

    if (command.instruction == "JE") {
        if (flag == 0) {
            EIP = getValue(command.argLeft) - 1;
        }
        return true;
    }

    if (command.instruction == "JNE") {
        if (flag != 0) {
            EIP = getValue(command.argLeft) - 1;
        }
        return true;
    }

    if (command.instruction == "JG") {
        if (flag > 0) {
            EIP = getValue(command.argLeft) - 1;
        }
        return true;
    }

    if (command.instruction == "JGE") {
        if (flag >= 0) {
            EIP = getValue(command.argLeft) - 1;
        }
        return true;
    }

    if (command.instruction == "JL") {
        if (flag < 0) {
            EIP = getValue(command.argLeft) - 1;
        }
        return true;
    }

    if (command.instruction == "JLE") {
        if (flag <= 0) {
            EIP = getValue(command.argLeft) - 1;
        }
        return true;
    }

    return false;
}


int CommandList::getValue(QString& from) {
    if (isRegister(from)) {
        return getRegister(from.mid(1).toInt());
    }

    if (isNum(from)) {
        return from.toInt();
    }

    // this is var

    if (!varsMap.contains(from)) {
        throw QString("Var " + from + "wasn't define");
    }

    return varsMap.value(from);
}

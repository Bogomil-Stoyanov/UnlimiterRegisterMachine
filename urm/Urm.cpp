#include "Urm.h"
#include "operations/Operation.h"
#include "tokenizer/Tokenizer.h"
#include "operations/commands/CopyCmd.h"
#include "operations/commands/SetCmd.h"
#include "operations/commands/MemCmd.h"
#include "util/FileReader.h"
#include "operations/commands/LoadCmd.h"
#include "operations/instructions/ZeroInst.h"
#include "operations/instructions/IncInst.h"
#include "operations/instructions/MoveInst.h"
#include "operations/instructions/JumpInst.h"
#include "operations/commands/QuoteCmd.h"
#include "operations/commands/AddCmd.h"

Urm::~Urm() {
    clear();
}

Urm *Urm::getInstance() {
    static Urm instance;
    return &instance;
}

void Urm::start() {
    bool isRunning = true;

    while (isRunning) {
        std::string line;
        std::getline(std::cin, line);

        if (line == "/stop") {
            isRunning = false;
        } else {
            Operation *operation = Tokenizer::tokenize(line);
            readOperation(operation);
        }
    }
    clear();
}

void Urm::readOperation(Operation *operation) {
    if (operation->getType() == ERROR){
        operation->print();
        delete operation;
        return;
    }
    if (operation->getType() == COMMAND) {
        //switch all the commands
        switch (operation->getName()) {
            case ADD_CMD:
                delete operation;
                break;
            case LOAD_CMD: {
                loadCmd(((LoadCmd *) operation)->getFilename());
                delete operation;
                break;
            }
            case RUN_CMD:{
                run();
                delete operation;
                break;
            }
            case CODE_CMD: {
                codeCmd();
                delete operation;
                break;
            }
            case MEM_CMD: {
                auto *mem = (MemCmd *) operation;
                memCmd(mem->getX(), mem->getY());
                delete operation;
                break;
            }
            case COMMENT_CMD:
            case QUOTE_CMD: {
                operations.push_back(operation);
                break;
            }
            case COPY_CMD: {
                auto *copy = (CopyCmd *) operation;
                copyCmd(copy->getX(), copy->getY(), copy->getZ());
                delete operation;
                break;
            }
            case SET_CMD: {
                auto *set = (SetCmd *) operation;
                setCmd(set->getX(), set->getY());
                delete operation;
                break;
            }
            case ZERO_CMD: {
                auto *zero = (ZeroCmd *) operation;
                zeroCmd(zero->getX(), zero->getY());
                delete operation;
                break;
            }
        }
    } else {
        std::cout << "Instructions are only allowed in files." << std::endl;
        delete operation;
    }
}

void Urm::zero(int n) {
    memory.set(n, 0);
}

void Urm::inc(int n) {
    memory.set(n, memory.get(n) + 1);
}

void Urm::move(int x, int y) {
    memory.set(y, memory.get(x));
}

void Urm::zeroCmd(int x, int y) {
    for (int i = x; i <= y; i++) {
        zero(i);
    }
}

void Urm::setCmd(int x, int y) {
    memory.set(x, y);
}

void Urm::copyCmd(int x, int y, int z) {
    for (int i = 0; i < z; i++) {
        memory.set(y + i, memory.get(x + i));
    }
}

void Urm::memCmd(int x, int y) {
    for (int i = x; i <= y; i++) {
        std::cout << memory.get(i) << " ";
    }
    std::cout << std::endl;
}

void Urm::codeCmd() {
    for (auto &operation: operations) {
        operation->print();
    }
}

void Urm::loadCmd(const std::string &path) {
    clear();
    std::vector<Operation *> newOperations = FileReader::read(path);

    for (auto &operation: newOperations) {
        if (operation->getType() == INSTRUCTION) {
            operations.push_back(operation);
            instructions.insert(std::pair<int, int>(instructions.size(), operations.size() - 1));

            //changes the range
            if (operation->getName() == ZERO_INST) {
                auto *zeroInst = (ZeroInst *) operation;
                if(zeroInst->getN() > rangeTo){
                    rangeTo = zeroInst->getN();
                }
            } else if (operation->getName() == INC_INST) {
                auto *incInst = (IncInst *) operation;
                if(incInst->getN() > rangeTo){
                    rangeTo = incInst->getN();
                }
            } else if (operation->getName() == MOVE_INST) {
                auto *moveInst = (MoveInst *) operation;
                if(moveInst->getX() > rangeTo){
                    rangeTo = moveInst->getX();
                }
                if(moveInst->getY() > rangeTo){
                    rangeTo = moveInst->getY();
                }
            } else if (operation->getName() == JUMP_INST) {
                auto *jumpInst = (JumpInst *) operation;
                if(jumpInst->getX() > rangeTo){
                    rangeTo = jumpInst->getX();
                }
                if(jumpInst->getY() > rangeTo){
                    rangeTo = jumpInst->getY();
                }
            }

        } else if (operation->getType() == COMMAND) {
            switch (operation->getName()) {
                case COMMENT_CMD:
                case COPY_CMD:
                case QUOTE_CMD:
                case SET_CMD:
                case ZERO_CMD:
                    operations.push_back(operation);
                    break;
            }

            if(operation->getName() == ADD_CMD){
                auto *add = (AddCmd *) operation;
                addCmd(add->getFilename());
            }
        }
    }

    while(!subProgramsOperations.empty()){
        std::vector<Operation *> subprograms = subProgramsOperations.top(); subProgramsOperations.pop();
        for(auto& operation : subprograms){
            if(operation->getType() == INSTRUCTION){
                operations.push_back(operation);
                instructions.insert(std::pair<int, int>(instructions.size(), operations.size() - 1));
            }else if(operation->getType() == COMMAND){
                switch (operation->getName()) {
                    case COMMENT_CMD:
                    case COPY_CMD:
                    case QUOTE_CMD:
                    case SET_CMD:
                    case ZERO_CMD:
                        operations.push_back(operation);
                        break;
                }
            }
        }
    }
}

void Urm::clear() {
    for (auto &operation: operations) {
        delete operation;
    }
    rangeTo = 0;
    operations.clear();
    memory.removeAll();
    instructions.clear();
}

void Urm::run() {
    int currentLine = 0;

    while(currentLine < operations.size()){

        Operation* operation = operations[currentLine];
        if(operation->getName()!=COMMENT_CMD){
            //memCmd(0,7);
            //operation->print();
        }else{
            currentLine++;
            continue;
        }
        if(operation->getType() == INSTRUCTION){
            applyInstruction(operation, currentLine);
            continue;
        }else if(operation->getType() == COMMAND){
            switch (operation->getName()) {
                case COPY_CMD:{
                    auto *copy = (CopyCmd *) operation;
                    copyCmd(copy->getX(), copy->getY(), copy->getZ());
                    currentLine++;
                    break;
                }
                case QUOTE_CMD:{
                    auto *quote = (QuoteCmd *) operation;
                    Operation* operationInQuote = quote->getOperation();
                    applyInstruction(operationInQuote, currentLine);
                    continue;
                }
                case SET_CMD: {
                    auto *set = (SetCmd *) operation;
                    setCmd(set->getX(), set->getY());
                    currentLine++;
                    break;
                }
                case ZERO_CMD: {
                    auto *zero = (ZeroCmd *) operation;
                    zeroCmd(zero->getX(), zero->getY());
                    currentLine++;
                    break;
                }
                case COMMENT_CMD: {
                    currentLine++;
                    break;
                }
            }
        }


    }
}

void Urm::applyInstruction(Operation *operation, int &line) {
    switch (operation->getName()) {
        case ZERO_INST: {
            auto *zeroInst = (ZeroInst *) operation;
            zero(zeroInst->getN());
            line++;
            break;
        }
        case INC_INST: {
            auto *incInst = (IncInst *) operation;
            inc(incInst->getN());
            line++;
            break;
        }
        case MOVE_INST: {
            auto *moveInst = (MoveInst *) operation;
            move(moveInst->getX(), moveInst->getY());
            line++;
            break;
        }
        case JUMP_INST: {
            auto *jumpInst = (JumpInst *) operation;
            if(memory.get(jumpInst->getX()) == memory.get(jumpInst->getY())){
                if(jumpInst->getZ() >= instructions.size()){
                   line = operations.size();
                }else{
                    line = instructions[jumpInst->getZ()];
                }
            }else{
                line++;
            }
            break;
        }
    }
}

void Urm::addCmd(const std::string &path) {
    std::vector<Operation *> newOperations = FileReader::read(path);
    addSubprogram(newOperations);
}

void Urm::addSubprogram(std::vector<Operation *> &subprogram) {
    int oldRangeTo = rangeTo;
    int oldInstructionSize = instructions.size();

    std::vector<Operation *> newOperations;

    for(auto& operation: subprogram){
        if(operation->getType() == INSTRUCTION){

            //changes the range
            if (operation->getName() == ZERO_INST) {
                auto *zeroInst = (ZeroInst *) operation;
                zeroInst->changeRange(oldRangeTo);
                if(zeroInst->getN() > rangeTo){
                    rangeTo = zeroInst->getN();
                }
            } else if (operation->getName() == INC_INST) {
                auto *incInst = (IncInst *) operation;
                incInst->changeRange(oldRangeTo);
                if(incInst->getN() > rangeTo){
                    rangeTo = incInst->getN();
                }
            } else if (operation->getName() == MOVE_INST) {
                auto *moveInst = (MoveInst *) operation;
                moveInst->changeRange(oldRangeTo);
                if(moveInst->getX() > rangeTo){
                    rangeTo = moveInst->getX();
                }
                if(moveInst->getY() > rangeTo){
                    rangeTo = moveInst->getY();
                }
            } else if (operation->getName() == JUMP_INST) {
                auto *jumpInst = (JumpInst *) operation;
                jumpInst->changeRange(oldRangeTo, oldInstructionSize);
                if(jumpInst->getX() > rangeTo){
                    rangeTo = jumpInst->getX();
                }
                if(jumpInst->getY() > rangeTo){
                    rangeTo = jumpInst->getY();
                }
            }

            newOperations.push_back(operation);

        } else if (operation->getType() == COMMAND) {
            switch (operation->getName()) {
                case ADD_CMD:
                case COMMENT_CMD:
                case COPY_CMD:
                case QUOTE_CMD:
                case SET_CMD:
                case ZERO_CMD:
                    newOperations.push_back(operation);
                    break;
            }

            if(operation->getName() == ADD_CMD){
                auto *add = (AddCmd *) operation;
                addCmd(add->getFilename());
            }
        }

    }
        subProgramsOperations.push(newOperations);
}



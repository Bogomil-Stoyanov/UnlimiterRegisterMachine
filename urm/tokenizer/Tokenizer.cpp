#include <sstream>
#include <vector>
#include "Tokenizer.h"
#include "../operations/Error.h"
#include "../operations/commands/ZeroCmd.h"
#include "../operations/commands/SetCmd.h"
#include "../operations/commands/CopyCmd.h"
#include "../operations/commands/MemCmd.h"
#include "../operations/commands/LoadCmd.h"
#include "../operations/commands/RunCmd.h"
#include "../operations/commands/AddCmd.h"
#include "../operations/commands/QuoteCmd.h"
#include "../operations/commands/CodeCmd.h"
#include "../operations/commands/CommentCmd.h"
#include "../operations/instructions/ZeroInst.h"
#include "../operations/instructions/IncInst.h"
#include "../operations/instructions/MoveInst.h"
#include "../operations/instructions/JumpInst.h"

// Converts a string to an Operation
Operation *Tokenizer::tokenize(const std::string& line) {

    std::vector<std::string> args;

    std::istringstream iss(line);
    std::string word;
    while (iss >> word) {
        args.push_back(word);
    }

    if (args.empty()) {
        return new Error("No arguments supplied");
    }

    try {
        std::string invalidNumberOfArguments = "Invalid number of arguments, please use /help for a list of operations";
        if (args[0][0] == '/') {
            //probably a command
            if (args[0] == "/zero") {
                if(args.size() != 3) return new Error(invalidNumberOfArguments);
                int x = std::stoi(args[1]);
                int y = std::stoi(args[2]);
                return new ZeroCmd(x, y);
            } else if (args[0] == "/set" ) {
                if(args.size() != 3) return new Error(invalidNumberOfArguments);
                int x = std::stoi(args[1]);
                int y = std::stoi(args[2]);
                return new SetCmd(x, y);
            } else if (args[0] == "/copy" ) {
                if(args.size() != 4) return new Error(invalidNumberOfArguments);
                int x = std::stoi(args[1]);
                int y = std::stoi(args[2]);
                int z = std::stoi(args[3]);
                return new CopyCmd(x, y, z);
            } else if (args[0] == "/mem" ) {
                if(args.size() != 3) return new Error(invalidNumberOfArguments);
                int x = std::stoi(args[1]);
                int y = std::stoi(args[2]);
                return new MemCmd(x, y);
            } else if (args[0] == "/load") {
                if(args.size() != 2) return new Error(invalidNumberOfArguments);
                return new LoadCmd(args[1]);
            } else if (args[0] == "/run") {
                if(args.size() != 1) return new Error(invalidNumberOfArguments);
                return new RunCmd();
            } else if (args[0] == "/add") {
                if(args.size() != 2) return new Error(invalidNumberOfArguments);
                if (args[1].substr(args[1].size() - 4) == ".urm") {
                    return new AddCmd(args[1]);
                } else {
                    return new Error("File must be a .urm file");
                }
            } else if (args[0] == "/quote") {
                std::string quote;
                for (int i = 1; i < args.size(); ++i) {
                    quote += args[i];
                    if (i != args.size() - 1)
                        quote += " ";
                }
                Operation *operation = Tokenizer::tokenize(quote);

                if (dynamic_cast<Error *>(operation) != nullptr) {
                    delete operation;
                    return new Error("Invalid quote");
                }

                return new QuoteCmd(operation);
            } else if (args[0] == "/code") {
                if(args.size() != 1) return new Error(invalidNumberOfArguments);
                return new CodeCmd();
            } else if (args[0] == "/comment") {
                if(args.size() == 1) return new Error(invalidNumberOfArguments);
                std::string comment;
                for (int i = 1; i < args.size(); ++i) {
                    comment += args[i] + " ";
                }
                return new CommentCmd(comment);
            } else {
                return new Error("Unknown command, please use /help for a list of operations");
            }

        } else {
            //probably an instruction
            if (args[0] == "ZERO" && args.size() == 2) {
                int x = std::stoi(args[1]);
                return new ZeroInst(x);
            } else if (args[0] == "INC" && args.size() == 2) {
                int x = std::stoi(args[1]);
                return new IncInst(x);
            } else if (args[0] == "MOVE" && args.size() == 3) {
                int x = std::stoi(args[1]);
                int y = std::stoi(args[2]);
                return new MoveInst(x, y);
            } else if (args[0] == "JUMP") {
                if (args.size() == 2) {
                    int z = std::stoi(args[1]);
                    return new JumpInst(0, 0, z);
                } else if (args.size() == 4) {
                    int x = std::stoi(args[1]);
                    int y = std::stoi(args[2]);
                    int z = std::stoi(args[3]);
                    return new JumpInst(x, y, z);
                }
            }

            return new Error("Unknown instruction, please use /help for a list of operations");
        }
    }catch (std::invalid_argument &e) {
        return new Error("Invalid arguments, please use /help for a list of operations");
    }
}
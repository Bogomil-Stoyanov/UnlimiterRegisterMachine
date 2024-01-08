#define DOCTEST_CONFIG_IMPLEMENT

#include "doctest.h"
#include "urm/tokenizer/Tokenizer.h"
#include "urm/operations/commands/CommentCmd.h"
#include "urm/operations/commands/CodeCmd.h"
#include "urm/operations/commands/RunCmd.h"
#include "urm/operations/commands/AddCmd.h"
#include "urm/operations/commands/QuoteCmd.h"
#include "urm/operations/commands/ZeroCmd.h"
#include "urm/operations/commands/SetCmd.h"
#include "urm/operations/commands/CopyCmd.h"
#include "urm/operations/commands/MemCmd.h"
#include "urm/operations/commands/LoadCmd.h"
#include "urm/operations/instructions/ZeroInst.h"
#include "urm/operations/instructions/IncInst.h"
#include "urm/operations/instructions/MoveInst.h"
#include "urm/operations/instructions/JumpInst.h"
#include "urm/operations/Error.h"
#include "urm/Urm.h"

// Tokenizer tests

TEST_CASE("Tokenize ZeroCmd") {
    std::string input = "/zero 1 2";
    Operation *result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<ZeroCmd *>(result) != nullptr);
    delete result;

    input = "/zero 1";
    result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<Error *>(result) != nullptr);
    delete result;

    input = "/zero";
    result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<Error *>(result) != nullptr);
    delete result;
}

TEST_CASE("Tokenize SetCmd") {
    std::string input = "/set 3 4";
    Operation *result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<SetCmd *>(result) != nullptr);
    delete result;

    input = "/set 3";
    result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<Error *>(result) != nullptr);
    delete result;
}

TEST_CASE("Tokenize CopyCmd") {
    std::string input = "/copy 1 2 3";
    Operation *result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<CopyCmd *>(result) != nullptr);
    delete result;

    input = "/copy 3";
    result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<Error *>(result) != nullptr);
    delete result;
}

TEST_CASE("Tokenize ZeroInst") {
    std::string input = "ZERO 5";
    Operation *result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<ZeroInst *>(result) != nullptr);
    delete result;
}

TEST_CASE("Tokenize IncInst") {
    std::string input = "INC 6";
    Operation *result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<IncInst *>(result) != nullptr);
    delete result;
}

TEST_CASE("Tokenize MoveInst") {
    std::string input = "MOVE 7 8";
    Operation *result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<MoveInst *>(result) != nullptr);
    delete result;
}

TEST_CASE("Tokenize Error") {
    std::string input = "";
    Operation *result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<Error *>(result) != nullptr);
    delete result;
}

TEST_CASE("Tokenize MemCmd") {
    std::string input = "/mem 1 2";
    Operation *result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<MemCmd *>(result) != nullptr);
    delete result;
}

TEST_CASE("Tokenize LoadCmd") {
    std::string input = "/load filename.urm";
    Operation *result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<LoadCmd *>(result) != nullptr);
    delete result;
}

TEST_CASE("Tokenize RunCmd") {
    std::string input = "/run";
    Operation *result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<RunCmd *>(result) != nullptr);
    delete result;
}

TEST_CASE("Tokenize AddCmd") {
    std::string input = "/add filename.urm";
    Operation *result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<AddCmd *>(result) != nullptr);
    delete result;

    input = "/add filename.txt";
    result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<Error *>(result) != nullptr);
    delete result;
}

TEST_CASE("Tokenize QuoteCmd") {
    std::string input = "/quote INC 1";
    Operation *result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<QuoteCmd *>(result) != nullptr);
    delete result;

    input = "/quote INVALID";
    result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<Error *>(result) != nullptr);
    delete result;
}

TEST_CASE("Tokenize CodeCmd") {
    std::string input = "/code";
    Operation *result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<CodeCmd *>(result) != nullptr);
    delete result;
}

TEST_CASE("Tokenize CommentCmd") {
    std::string input = "/comment This is a comment";
    Operation *result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<CommentCmd *>(result) != nullptr);
    delete result;
}

TEST_CASE("Tokenize Invalid Command") {
    std::string input = "/invalid";
    Operation *result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<Error *>(result) != nullptr);
    delete result;
}

TEST_CASE("Tokenize Invalid Instruction") {
    std::string input = "INVALID 1";
    Operation *result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<Error *>(result) != nullptr);
    delete result;
}

TEST_CASE("Tokenize Invalid Arguments") {
    std::string input = "/zero";
    Operation *result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<Error *>(result) != nullptr);
    delete result;
}

TEST_CASE("Tokenize JumpInst with 1 argument") {
    std::string input = "JUMP 5";
    Operation *result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<JumpInst *>(result) != nullptr);
    delete result;
}

TEST_CASE("Tokenize JumpInst with 3 arguments") {
    std::string input = "JUMP 1 2 3";
    Operation *result = Tokenizer::tokenize(input);
    CHECK(result != nullptr);
    CHECK(dynamic_cast<JumpInst *>(result) != nullptr);
    delete result;
}

// Urm tests

TEST_CASE("Load program test containing /add") {
    Urm::getInstance()->readSingleCommand("/load add.urm");
    Urm::getInstance()->readSingleCommand("/code");
    Urm::getInstance()->readSingleCommand("/run");
    Urm::getInstance()->readSingleCommand("/mem 0 4");

    Urm::getInstance()->clear();
}

TEST_CASE("LOAD program test"){
    Urm::getInstance()->readSingleCommand("/load add2.urm");
    Urm::getInstance()->readSingleCommand("/set 0 5");
    Urm::getInstance()->readSingleCommand("/set 1 6");
    Urm::getInstance()->readSingleCommand("/run");
    Urm::getInstance()->readSingleCommand("/mem 0 4");
    Urm::getInstance()->clear();
}


TEST_CASE("Test with /stop command") {
    std::istringstream input("/stop\n");
    Urm::getInstance()->start(input);
    Urm::getInstance()->clear();
}

TEST_CASE("Urm readSingleCommand Method") {
    SUBCASE("Test with valid commands") {
        Urm::getInstance()->readSingleCommand("/zero 1 5");
        Urm::getInstance()->readSingleCommand("/set 2 8");
        Urm::getInstance()->readSingleCommand("/copy 1 3 5");
        Urm::getInstance()->readSingleCommand("/mem 2 4");
        Urm::getInstance()->readSingleCommand("/load file.urm");
        Urm::getInstance()->readSingleCommand("/run");
        Urm::getInstance()->readSingleCommand("/add file.urm");
        Urm::getInstance()->readSingleCommand("/quote /zero 1 2");
        Urm::getInstance()->readSingleCommand("/quote INC 1");
        Urm::getInstance()->readSingleCommand("/code");
    }

    SUBCASE("Test with invalid commands") {
        Urm::getInstance()->readSingleCommand("INVALID_COMMAND");
        Urm::getInstance()->readSingleCommand("INC 5");
        Urm::getInstance()->readSingleCommand("/set");
        Urm::getInstance()->readSingleCommand("/copy 1 2");
        Urm::getInstance()->readSingleCommand("/quote invalid_quote");
        Urm::getInstance()->readSingleCommand("/invalid_command");
        Urm::getInstance()->readSingleCommand("/quote INC");
        Urm::getInstance()->readSingleCommand("/quote INVALID");
    }

}

// SparseArray tests

TEST_CASE("SparsedArray Basic Operations") {
    SparsedArray arr;

    SUBCASE("Set and Get Values") {
        arr.set(0, 10);
        arr.set(3, 30);
        arr.set(5, 50);

        CHECK(arr.get(0) == 10);
        CHECK(arr.get(3) == 30);
        CHECK(arr.get(5) == 50);
        CHECK(arr.get(1) == 0);
    }

    SUBCASE("Remove Values") {
        arr.set(2, 20);
        arr.set(4, 40);

        arr.remove(2);
        CHECK(arr.get(2) == 0);
        CHECK(arr.get(4) == 40);

        arr.remove(4);
        CHECK(arr.get(4) == 0);
    }


    SUBCASE("Remove All Values") {
        arr.set(1, 10);
        arr.set(3, 30);
        arr.set(5, 50);

        arr.removeAll();

        CHECK(arr.get(1) == 0);
        CHECK(arr.get(3) == 0);
        CHECK(arr.get(5) == 0);
    }
}


int main() {

    Urm::getInstance()->start(std::cin);
    //doctest::Context().run();

    return 0;
}

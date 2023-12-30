cmake_minimum_required(VERSION 3.25)
project(URM)

set(CMAKE_CXX_STANDARD 17)

add_executable(URM main.cpp urm/Urm.h urm/Urm.cpp urm/sparsedarray/SparsedArray.h urm/sparsedarray/SparsedArray.cpp urm/operations/Operation.h urm/operations/instructions/ZeroInst.h urm/operations/instructions/IncInst.h urm/operations/instructions/MoveInst.h urm/operations/instructions/JumpInst.h urm/operations/commands/ZeroCmd.h urm/operations/commands/SetCmd.h urm/operations/commands/CopyCmd.h urm/operations/commands/MemCmd.h urm/operations/commands/LoadCmd.h urm/operations/commands/RunCmd.h urm/operations/commands/AddCmd.h urm/operations/commands/QuoteCmd.h urm/operations/commands/CodeCmd.h urm/operations/commands/CommentCmd.h urm/tokenizer/Tokenizer.cpp urm/tokenizer/Tokenizer.h urm/operations/Error.h urm/util/FileReader.cpp urm/util/FileReader.h doctest.h)

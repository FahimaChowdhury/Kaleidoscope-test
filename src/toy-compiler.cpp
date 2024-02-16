//===- toyc.cpp - The Kelidoscop Compiler ----------------------------------------===//
//
//===----------------------------------------------------------------------===//
//
// This file implements the entry point for the Kelidoscop compiler.
//
//===----------------------------------------------------------------------===//


// "Parser.h" is calling "AST.h"
// "AST.h" is calling "Lexer.h"
// "Lexer.h" is top and calling no one.


#ifndef INCLUDE_PARSER_H
#define INCLUDE_PARSER_H


#include "include/Parser.h"



int main() {

    // Prime the first token.
    fprintf(stderr, "ready> ");

    getNextToken();

    // Make the module, which holds all the code.
    InitializeModule();

    // Run the main "interpreter loop" now.
    MainLoop();

    // Print out all of the generated code.
    TheModule->print(errs(), nullptr);


    return 0;


}


#endif






































// /// our compiler take an input filename (i.e. filename.toy).
// static cl::opt<std::string> inputFilename(
//     cl::Positional,
//     cl::desc("<input toy file>"),
//     cl::init("-"),
//     cl::value_desc("filename")
// );


// namespace {
// enum Action { None, DumpAST };
// } // namespace

// /// This declaration defines a variable “emitAction” of the “Action” enum type.
// /// For more - https://llvm.org/docs/CommandLine.html#selecting-an-alternative-from-a-set-of-possibilities
// static cl::opt<enum Action> emitAction(
//     "emit",
//     cl::desc("Select the kind of output desired"),
//     cl::values(
//         clEnumValN(DumpAST, "ast", "output the AST dump")
//     )
// );


// /// Returns a Toy AST resulting from parsing the file or a nullptr on error.
// std::unique_ptr<toy::ModuleAST> parseInputFile(llvm::StringRef filename) {
    
//     llvm::ErrorOr<std::unique_ptr<llvm::MemoryBuffer>> fileOrErr =
//         llvm::MemoryBuffer::getFileOrSTDIN(filename);
    
//     if (std::error_code ec = fileOrErr.getError()) {
//         llvm::errs() << "Could not open input file: " << ec.message() << "\n";
//         return nullptr;
//     }

//     auto buffer = fileOrErr.get()->getBuffer();
//     LexerBuffer lexer(buffer.begin(), buffer.end(), std::string(filename));
//     Parser parser(lexer);
    
//     return parser.parseModule();
// }




// int main(int argc, char **argv) {

//     // Parse the command line arguments & flags
//     cl::ParseCommandLineOptions(argc, argv, "toy compiler\n");
    
//     // Parse code file (i.e. code into LLVM module)
//     // Lexer & Parser are called inside
//     auto moduleAST = parseInputFile(inputFilename);
    

//     if (!moduleAST)
//         return 1;


//     switch (emitAction) {

//         // Then Dump the AST, if -emit=ast argument is passed
//         case Action::DumpAST:
//             dump(*moduleAST);
//             return 0;
        
//         default:
//             llvm::errs() << "No action specified (parsing only?), use -emit=<action>\n";
//     }

//     return 0;
// }

cmake_minimum_required (VERSION 3.0)
project (test_lexer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Run FA2LEXER to generate the lexer
add_custom_command (
  OUTPUT lexer.cpp
  COMMAND fa2lexer --hdr tokens.h --src lexer.cpp --tpl ${PROJECT_SOURCE_DIR}/../fa/const_lexer.fa2l
  MAIN_DEPENDENCY ${PROJECT_SOURCE_DIR}/../fa/const_lexer.fa2l
  DEPENDS ${PROJECT_SOURCE_DIR}/../fa/start.jff
          ${PROJECT_SOURCE_DIR}/../fa/Cblock.jff
          ${PROJECT_SOURCE_DIR}/../fa/Cline.jff
	 
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/../)
  
add_executable(${PROJECT_NAME}  lexer.cpp
                                test_lexer.cpp)

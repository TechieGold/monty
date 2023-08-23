cmake_minimum_required(VERSION 3.26)
project(monty-cli)


add_executable(monty)

set_target_properties(monty
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

FILE(GLOB MONTY_SOURCES *.c)

target_sources(monty PUBLIC ${MONTY_SOURCES})

set_target_properties(monty PROPERTIES
  COMPILE_FLAGS "-Wall -Werror -pedantic -Wextra -std=c89 -fsanitize=address"
  LINK_FLAGS "-fsanitize=address"
)

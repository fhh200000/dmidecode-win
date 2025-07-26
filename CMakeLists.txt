# @file CMakeLists.txt
#
# CMake scripts for building dmidecode in a modern way.
# SPDX-License-Identifier: WTFPL

cmake_minimum_required (VERSION 3.16)

# For MSVC
if (POLICY CMP0141)
  cmake_policy (SET CMP0141 NEW)
  set (CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (dmidecode)

if (WIN32)
link_libraries(Ws2_32.lib)
endif()
add_executable (dmidecode dmidecode.c dmioem.c dmiopt.c dmioutput.c util.c)

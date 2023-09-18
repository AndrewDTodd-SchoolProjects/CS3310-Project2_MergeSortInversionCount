# CMakeList.txt : CMake project for Project2_InversionsCount, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Project2_InversionsCount")

#set minimum c++ version to 20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source to this project's BruteForce executable
add_executable (BruteForce "SimpleCounter.cpp"  "InversionCounter.h" "InversionCounter.cpp" "ArrayGen.h" "ArrayGen.cpp" "Project2_InversionsCountConstDeff.h" "ArrayFromFile.h" "ArrayFromFile.cpp")

#Add source to this project's MergeSortCounter executable
add_executable(MergeSortCount "MergeSortCounter.cpp" "MergeSortCount.h" "MergeSortCount.cpp" "ArrayGen.h" "ArrayGen.cpp" "Project2_InversionsCountConstDeff.h" "ArrayFromFile.h" "ArrayFromFile.cpp")

# TODO: Add tests and install targets if needed.

# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/arseniy/Projects/Geekbrains/cpp_education/cpp_init_cource/testThread

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/arseniy/Projects/Geekbrains/cpp_education/cpp_init_cource/testThread/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/testThread.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testThread.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testThread.dir/flags.make

CMakeFiles/testThread.dir/main.cpp.o: CMakeFiles/testThread.dir/flags.make
CMakeFiles/testThread.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arseniy/Projects/Geekbrains/cpp_education/cpp_init_cource/testThread/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testThread.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testThread.dir/main.cpp.o -c /Users/arseniy/Projects/Geekbrains/cpp_education/cpp_init_cource/testThread/main.cpp

CMakeFiles/testThread.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testThread.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/arseniy/Projects/Geekbrains/cpp_education/cpp_init_cource/testThread/main.cpp > CMakeFiles/testThread.dir/main.cpp.i

CMakeFiles/testThread.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testThread.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/arseniy/Projects/Geekbrains/cpp_education/cpp_init_cource/testThread/main.cpp -o CMakeFiles/testThread.dir/main.cpp.s

# Object files for target testThread
testThread_OBJECTS = \
"CMakeFiles/testThread.dir/main.cpp.o"

# External object files for target testThread
testThread_EXTERNAL_OBJECTS =

testThread: CMakeFiles/testThread.dir/main.cpp.o
testThread: CMakeFiles/testThread.dir/build.make
testThread: CMakeFiles/testThread.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/arseniy/Projects/Geekbrains/cpp_education/cpp_init_cource/testThread/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testThread"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testThread.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testThread.dir/build: testThread

.PHONY : CMakeFiles/testThread.dir/build

CMakeFiles/testThread.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testThread.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testThread.dir/clean

CMakeFiles/testThread.dir/depend:
	cd /Users/arseniy/Projects/Geekbrains/cpp_education/cpp_init_cource/testThread/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/arseniy/Projects/Geekbrains/cpp_education/cpp_init_cource/testThread /Users/arseniy/Projects/Geekbrains/cpp_education/cpp_init_cource/testThread /Users/arseniy/Projects/Geekbrains/cpp_education/cpp_init_cource/testThread/cmake-build-debug /Users/arseniy/Projects/Geekbrains/cpp_education/cpp_init_cource/testThread/cmake-build-debug /Users/arseniy/Projects/Geekbrains/cpp_education/cpp_init_cource/testThread/cmake-build-debug/CMakeFiles/testThread.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testThread.dir/depend

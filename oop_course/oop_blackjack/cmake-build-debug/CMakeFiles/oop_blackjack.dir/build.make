# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = /Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/oop_blackjack.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/oop_blackjack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/oop_blackjack.dir/flags.make

CMakeFiles/oop_blackjack.dir/main.cpp.o: CMakeFiles/oop_blackjack.dir/flags.make
CMakeFiles/oop_blackjack.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/oop_blackjack.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/oop_blackjack.dir/main.cpp.o -c /Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack/main.cpp

CMakeFiles/oop_blackjack.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/oop_blackjack.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack/main.cpp > CMakeFiles/oop_blackjack.dir/main.cpp.i

CMakeFiles/oop_blackjack.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/oop_blackjack.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack/main.cpp -o CMakeFiles/oop_blackjack.dir/main.cpp.s

CMakeFiles/oop_blackjack.dir/card.cpp.o: CMakeFiles/oop_blackjack.dir/flags.make
CMakeFiles/oop_blackjack.dir/card.cpp.o: ../card.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/oop_blackjack.dir/card.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/oop_blackjack.dir/card.cpp.o -c /Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack/card.cpp

CMakeFiles/oop_blackjack.dir/card.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/oop_blackjack.dir/card.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack/card.cpp > CMakeFiles/oop_blackjack.dir/card.cpp.i

CMakeFiles/oop_blackjack.dir/card.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/oop_blackjack.dir/card.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack/card.cpp -o CMakeFiles/oop_blackjack.dir/card.cpp.s

CMakeFiles/oop_blackjack.dir/game.cpp.o: CMakeFiles/oop_blackjack.dir/flags.make
CMakeFiles/oop_blackjack.dir/game.cpp.o: ../game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/oop_blackjack.dir/game.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/oop_blackjack.dir/game.cpp.o -c /Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack/game.cpp

CMakeFiles/oop_blackjack.dir/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/oop_blackjack.dir/game.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack/game.cpp > CMakeFiles/oop_blackjack.dir/game.cpp.i

CMakeFiles/oop_blackjack.dir/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/oop_blackjack.dir/game.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack/game.cpp -o CMakeFiles/oop_blackjack.dir/game.cpp.s

CMakeFiles/oop_blackjack.dir/player.cpp.o: CMakeFiles/oop_blackjack.dir/flags.make
CMakeFiles/oop_blackjack.dir/player.cpp.o: ../player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/oop_blackjack.dir/player.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/oop_blackjack.dir/player.cpp.o -c /Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack/player.cpp

CMakeFiles/oop_blackjack.dir/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/oop_blackjack.dir/player.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack/player.cpp > CMakeFiles/oop_blackjack.dir/player.cpp.i

CMakeFiles/oop_blackjack.dir/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/oop_blackjack.dir/player.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack/player.cpp -o CMakeFiles/oop_blackjack.dir/player.cpp.s

# Object files for target oop_blackjack
oop_blackjack_OBJECTS = \
"CMakeFiles/oop_blackjack.dir/main.cpp.o" \
"CMakeFiles/oop_blackjack.dir/card.cpp.o" \
"CMakeFiles/oop_blackjack.dir/game.cpp.o" \
"CMakeFiles/oop_blackjack.dir/player.cpp.o"

# External object files for target oop_blackjack
oop_blackjack_EXTERNAL_OBJECTS =

oop_blackjack: CMakeFiles/oop_blackjack.dir/main.cpp.o
oop_blackjack: CMakeFiles/oop_blackjack.dir/card.cpp.o
oop_blackjack: CMakeFiles/oop_blackjack.dir/game.cpp.o
oop_blackjack: CMakeFiles/oop_blackjack.dir/player.cpp.o
oop_blackjack: CMakeFiles/oop_blackjack.dir/build.make
oop_blackjack: CMakeFiles/oop_blackjack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable oop_blackjack"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/oop_blackjack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/oop_blackjack.dir/build: oop_blackjack

.PHONY : CMakeFiles/oop_blackjack.dir/build

CMakeFiles/oop_blackjack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/oop_blackjack.dir/cmake_clean.cmake
.PHONY : CMakeFiles/oop_blackjack.dir/clean

CMakeFiles/oop_blackjack.dir/depend:
	cd /Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack /Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack /Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack/cmake-build-debug /Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack/cmake-build-debug /Users/arseniy/Projects/Geekbrains/cpp_education/oop_course/oop_blackjack/cmake-build-debug/CMakeFiles/oop_blackjack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/oop_blackjack.dir/depend


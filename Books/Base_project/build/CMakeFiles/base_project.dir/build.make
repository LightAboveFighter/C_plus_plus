# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project/build

# Include any dependencies generated for this target.
include CMakeFiles/base_project.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/base_project.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/base_project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/base_project.dir/flags.make

CMakeFiles/base_project.dir/main.cpp.o: CMakeFiles/base_project.dir/flags.make
CMakeFiles/base_project.dir/main.cpp.o: ../main.cpp
CMakeFiles/base_project.dir/main.cpp.o: CMakeFiles/base_project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/base_project.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/base_project.dir/main.cpp.o -MF CMakeFiles/base_project.dir/main.cpp.o.d -o CMakeFiles/base_project.dir/main.cpp.o -c /home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project/main.cpp

CMakeFiles/base_project.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base_project.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project/main.cpp > CMakeFiles/base_project.dir/main.cpp.i

CMakeFiles/base_project.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base_project.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project/main.cpp -o CMakeFiles/base_project.dir/main.cpp.s

CMakeFiles/base_project.dir/Channel.cpp.o: CMakeFiles/base_project.dir/flags.make
CMakeFiles/base_project.dir/Channel.cpp.o: ../Channel.cpp
CMakeFiles/base_project.dir/Channel.cpp.o: CMakeFiles/base_project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/base_project.dir/Channel.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/base_project.dir/Channel.cpp.o -MF CMakeFiles/base_project.dir/Channel.cpp.o.d -o CMakeFiles/base_project.dir/Channel.cpp.o -c /home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project/Channel.cpp

CMakeFiles/base_project.dir/Channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base_project.dir/Channel.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project/Channel.cpp > CMakeFiles/base_project.dir/Channel.cpp.i

CMakeFiles/base_project.dir/Channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base_project.dir/Channel.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project/Channel.cpp -o CMakeFiles/base_project.dir/Channel.cpp.s

CMakeFiles/base_project.dir/Terminal.cpp.o: CMakeFiles/base_project.dir/flags.make
CMakeFiles/base_project.dir/Terminal.cpp.o: ../Terminal.cpp
CMakeFiles/base_project.dir/Terminal.cpp.o: CMakeFiles/base_project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/base_project.dir/Terminal.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/base_project.dir/Terminal.cpp.o -MF CMakeFiles/base_project.dir/Terminal.cpp.o.d -o CMakeFiles/base_project.dir/Terminal.cpp.o -c /home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project/Terminal.cpp

CMakeFiles/base_project.dir/Terminal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base_project.dir/Terminal.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project/Terminal.cpp > CMakeFiles/base_project.dir/Terminal.cpp.i

CMakeFiles/base_project.dir/Terminal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base_project.dir/Terminal.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project/Terminal.cpp -o CMakeFiles/base_project.dir/Terminal.cpp.s

CMakeFiles/base_project.dir/enums.cpp.o: CMakeFiles/base_project.dir/flags.make
CMakeFiles/base_project.dir/enums.cpp.o: ../enums.cpp
CMakeFiles/base_project.dir/enums.cpp.o: CMakeFiles/base_project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/base_project.dir/enums.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/base_project.dir/enums.cpp.o -MF CMakeFiles/base_project.dir/enums.cpp.o.d -o CMakeFiles/base_project.dir/enums.cpp.o -c /home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project/enums.cpp

CMakeFiles/base_project.dir/enums.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base_project.dir/enums.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project/enums.cpp > CMakeFiles/base_project.dir/enums.cpp.i

CMakeFiles/base_project.dir/enums.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base_project.dir/enums.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project/enums.cpp -o CMakeFiles/base_project.dir/enums.cpp.s

# Object files for target base_project
base_project_OBJECTS = \
"CMakeFiles/base_project.dir/main.cpp.o" \
"CMakeFiles/base_project.dir/Channel.cpp.o" \
"CMakeFiles/base_project.dir/Terminal.cpp.o" \
"CMakeFiles/base_project.dir/enums.cpp.o"

# External object files for target base_project
base_project_EXTERNAL_OBJECTS =

base_project: CMakeFiles/base_project.dir/main.cpp.o
base_project: CMakeFiles/base_project.dir/Channel.cpp.o
base_project: CMakeFiles/base_project.dir/Terminal.cpp.o
base_project: CMakeFiles/base_project.dir/enums.cpp.o
base_project: CMakeFiles/base_project.dir/build.make
base_project: CMakeFiles/base_project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable base_project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/base_project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/base_project.dir/build: base_project
.PHONY : CMakeFiles/base_project.dir/build

CMakeFiles/base_project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/base_project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/base_project.dir/clean

CMakeFiles/base_project.dir/depend:
	cd /home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project /home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project /home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project/build /home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project/build /home/alexunder/Documents/MIPT/C_plus_plus/Books/Base_project/build/CMakeFiles/base_project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/base_project.dir/depend

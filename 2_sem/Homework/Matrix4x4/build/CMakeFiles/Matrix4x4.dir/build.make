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
CMAKE_SOURCE_DIR = /media/alexunder/09C1B27DA5EB573A/MIPT/C_plus_plus/2_sem/Homework/Matrix4x4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/alexunder/09C1B27DA5EB573A/MIPT/C_plus_plus/2_sem/Homework/Matrix4x4/build

# Include any dependencies generated for this target.
include CMakeFiles/Matrix4x4.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Matrix4x4.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Matrix4x4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Matrix4x4.dir/flags.make

CMakeFiles/Matrix4x4.dir/main.cpp.o: CMakeFiles/Matrix4x4.dir/flags.make
CMakeFiles/Matrix4x4.dir/main.cpp.o: ../main.cpp
CMakeFiles/Matrix4x4.dir/main.cpp.o: CMakeFiles/Matrix4x4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/alexunder/09C1B27DA5EB573A/MIPT/C_plus_plus/2_sem/Homework/Matrix4x4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Matrix4x4.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Matrix4x4.dir/main.cpp.o -MF CMakeFiles/Matrix4x4.dir/main.cpp.o.d -o CMakeFiles/Matrix4x4.dir/main.cpp.o -c /media/alexunder/09C1B27DA5EB573A/MIPT/C_plus_plus/2_sem/Homework/Matrix4x4/main.cpp

CMakeFiles/Matrix4x4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Matrix4x4.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/alexunder/09C1B27DA5EB573A/MIPT/C_plus_plus/2_sem/Homework/Matrix4x4/main.cpp > CMakeFiles/Matrix4x4.dir/main.cpp.i

CMakeFiles/Matrix4x4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Matrix4x4.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/alexunder/09C1B27DA5EB573A/MIPT/C_plus_plus/2_sem/Homework/Matrix4x4/main.cpp -o CMakeFiles/Matrix4x4.dir/main.cpp.s

# Object files for target Matrix4x4
Matrix4x4_OBJECTS = \
"CMakeFiles/Matrix4x4.dir/main.cpp.o"

# External object files for target Matrix4x4
Matrix4x4_EXTERNAL_OBJECTS =

Matrix4x4: CMakeFiles/Matrix4x4.dir/main.cpp.o
Matrix4x4: CMakeFiles/Matrix4x4.dir/build.make
Matrix4x4: CMakeFiles/Matrix4x4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/alexunder/09C1B27DA5EB573A/MIPT/C_plus_plus/2_sem/Homework/Matrix4x4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Matrix4x4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Matrix4x4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Matrix4x4.dir/build: Matrix4x4
.PHONY : CMakeFiles/Matrix4x4.dir/build

CMakeFiles/Matrix4x4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Matrix4x4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Matrix4x4.dir/clean

CMakeFiles/Matrix4x4.dir/depend:
	cd /media/alexunder/09C1B27DA5EB573A/MIPT/C_plus_plus/2_sem/Homework/Matrix4x4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/alexunder/09C1B27DA5EB573A/MIPT/C_plus_plus/2_sem/Homework/Matrix4x4 /media/alexunder/09C1B27DA5EB573A/MIPT/C_plus_plus/2_sem/Homework/Matrix4x4 /media/alexunder/09C1B27DA5EB573A/MIPT/C_plus_plus/2_sem/Homework/Matrix4x4/build /media/alexunder/09C1B27DA5EB573A/MIPT/C_plus_plus/2_sem/Homework/Matrix4x4/build /media/alexunder/09C1B27DA5EB573A/MIPT/C_plus_plus/2_sem/Homework/Matrix4x4/build/CMakeFiles/Matrix4x4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Matrix4x4.dir/depend


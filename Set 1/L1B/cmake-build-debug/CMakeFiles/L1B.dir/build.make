# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\CSCI261\Set1\L1B

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\CSCI261\Set1\L1B\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/L1B.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/L1B.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/L1B.dir/flags.make

CMakeFiles/L1B.dir/main.cpp.obj: CMakeFiles/L1B.dir/flags.make
CMakeFiles/L1B.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\CSCI261\Set1\L1B\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/L1B.dir/main.cpp.obj"
	C:\Downloads\mingw64\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\L1B.dir\main.cpp.obj -c C:\CSCI261\Set1\L1B\main.cpp

CMakeFiles/L1B.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/L1B.dir/main.cpp.i"
	C:\Downloads\mingw64\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CSCI261\Set1\L1B\main.cpp > CMakeFiles\L1B.dir\main.cpp.i

CMakeFiles/L1B.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/L1B.dir/main.cpp.s"
	C:\Downloads\mingw64\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CSCI261\Set1\L1B\main.cpp -o CMakeFiles\L1B.dir\main.cpp.s

# Object files for target L1B
L1B_OBJECTS = \
"CMakeFiles/L1B.dir/main.cpp.obj"

# External object files for target L1B
L1B_EXTERNAL_OBJECTS =

L1B.exe: CMakeFiles/L1B.dir/main.cpp.obj
L1B.exe: CMakeFiles/L1B.dir/build.make
L1B.exe: CMakeFiles/L1B.dir/linklibs.rsp
L1B.exe: CMakeFiles/L1B.dir/objects1.rsp
L1B.exe: CMakeFiles/L1B.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\CSCI261\Set1\L1B\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable L1B.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\L1B.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/L1B.dir/build: L1B.exe

.PHONY : CMakeFiles/L1B.dir/build

CMakeFiles/L1B.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\L1B.dir\cmake_clean.cmake
.PHONY : CMakeFiles/L1B.dir/clean

CMakeFiles/L1B.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\CSCI261\Set1\L1B C:\CSCI261\Set1\L1B C:\CSCI261\Set1\L1B\cmake-build-debug C:\CSCI261\Set1\L1B\cmake-build-debug C:\CSCI261\Set1\L1B\cmake-build-debug\CMakeFiles\L1B.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/L1B.dir/depend

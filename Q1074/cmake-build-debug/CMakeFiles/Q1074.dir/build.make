# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.1.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.1.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\for_acm_2018\lighoj\Q1074

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\for_acm_2018\lighoj\Q1074\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Q1074.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Q1074.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Q1074.dir/flags.make

CMakeFiles/Q1074.dir/main.cpp.obj: CMakeFiles/Q1074.dir/flags.make
CMakeFiles/Q1074.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\for_acm_2018\lighoj\Q1074\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Q1074.dir/main.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Q1074.dir\main.cpp.obj -c G:\for_acm_2018\lighoj\Q1074\main.cpp

CMakeFiles/Q1074.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Q1074.dir/main.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\for_acm_2018\lighoj\Q1074\main.cpp > CMakeFiles\Q1074.dir\main.cpp.i

CMakeFiles/Q1074.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Q1074.dir/main.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\for_acm_2018\lighoj\Q1074\main.cpp -o CMakeFiles\Q1074.dir\main.cpp.s

CMakeFiles/Q1074.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Q1074.dir/main.cpp.obj.requires

CMakeFiles/Q1074.dir/main.cpp.obj.provides: CMakeFiles/Q1074.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Q1074.dir\build.make CMakeFiles/Q1074.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Q1074.dir/main.cpp.obj.provides

CMakeFiles/Q1074.dir/main.cpp.obj.provides.build: CMakeFiles/Q1074.dir/main.cpp.obj


# Object files for target Q1074
Q1074_OBJECTS = \
"CMakeFiles/Q1074.dir/main.cpp.obj"

# External object files for target Q1074
Q1074_EXTERNAL_OBJECTS =

Q1074.exe: CMakeFiles/Q1074.dir/main.cpp.obj
Q1074.exe: CMakeFiles/Q1074.dir/build.make
Q1074.exe: CMakeFiles/Q1074.dir/linklibs.rsp
Q1074.exe: CMakeFiles/Q1074.dir/objects1.rsp
Q1074.exe: CMakeFiles/Q1074.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\for_acm_2018\lighoj\Q1074\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Q1074.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Q1074.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Q1074.dir/build: Q1074.exe

.PHONY : CMakeFiles/Q1074.dir/build

CMakeFiles/Q1074.dir/requires: CMakeFiles/Q1074.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/Q1074.dir/requires

CMakeFiles/Q1074.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Q1074.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Q1074.dir/clean

CMakeFiles/Q1074.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\for_acm_2018\lighoj\Q1074 G:\for_acm_2018\lighoj\Q1074 G:\for_acm_2018\lighoj\Q1074\cmake-build-debug G:\for_acm_2018\lighoj\Q1074\cmake-build-debug G:\for_acm_2018\lighoj\Q1074\cmake-build-debug\CMakeFiles\Q1074.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Q1074.dir/depend

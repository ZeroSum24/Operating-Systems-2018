# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /opt/clion-2017.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2017.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/coursework.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/coursework.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/coursework.dir/flags.make

CMakeFiles/coursework.dir/buddy.cpp.o: CMakeFiles/coursework.dir/flags.make
CMakeFiles/coursework.dir/buddy.cpp.o: ../buddy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/coursework.dir/buddy.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coursework.dir/buddy.cpp.o -c /home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework/buddy.cpp

CMakeFiles/coursework.dir/buddy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coursework.dir/buddy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework/buddy.cpp > CMakeFiles/coursework.dir/buddy.cpp.i

CMakeFiles/coursework.dir/buddy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coursework.dir/buddy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework/buddy.cpp -o CMakeFiles/coursework.dir/buddy.cpp.s

CMakeFiles/coursework.dir/buddy.cpp.o.requires:

.PHONY : CMakeFiles/coursework.dir/buddy.cpp.o.requires

CMakeFiles/coursework.dir/buddy.cpp.o.provides: CMakeFiles/coursework.dir/buddy.cpp.o.requires
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/buddy.cpp.o.provides.build
.PHONY : CMakeFiles/coursework.dir/buddy.cpp.o.provides

CMakeFiles/coursework.dir/buddy.cpp.o.provides.build: CMakeFiles/coursework.dir/buddy.cpp.o


CMakeFiles/coursework.dir/sched-rr.cpp.o: CMakeFiles/coursework.dir/flags.make
CMakeFiles/coursework.dir/sched-rr.cpp.o: ../sched-rr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/coursework.dir/sched-rr.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coursework.dir/sched-rr.cpp.o -c /home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework/sched-rr.cpp

CMakeFiles/coursework.dir/sched-rr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coursework.dir/sched-rr.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework/sched-rr.cpp > CMakeFiles/coursework.dir/sched-rr.cpp.i

CMakeFiles/coursework.dir/sched-rr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coursework.dir/sched-rr.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework/sched-rr.cpp -o CMakeFiles/coursework.dir/sched-rr.cpp.s

CMakeFiles/coursework.dir/sched-rr.cpp.o.requires:

.PHONY : CMakeFiles/coursework.dir/sched-rr.cpp.o.requires

CMakeFiles/coursework.dir/sched-rr.cpp.o.provides: CMakeFiles/coursework.dir/sched-rr.cpp.o.requires
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/sched-rr.cpp.o.provides.build
.PHONY : CMakeFiles/coursework.dir/sched-rr.cpp.o.provides

CMakeFiles/coursework.dir/sched-rr.cpp.o.provides.build: CMakeFiles/coursework.dir/sched-rr.cpp.o


CMakeFiles/coursework.dir/tarfs.cpp.o: CMakeFiles/coursework.dir/flags.make
CMakeFiles/coursework.dir/tarfs.cpp.o: ../tarfs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/coursework.dir/tarfs.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coursework.dir/tarfs.cpp.o -c /home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework/tarfs.cpp

CMakeFiles/coursework.dir/tarfs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coursework.dir/tarfs.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework/tarfs.cpp > CMakeFiles/coursework.dir/tarfs.cpp.i

CMakeFiles/coursework.dir/tarfs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coursework.dir/tarfs.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework/tarfs.cpp -o CMakeFiles/coursework.dir/tarfs.cpp.s

CMakeFiles/coursework.dir/tarfs.cpp.o.requires:

.PHONY : CMakeFiles/coursework.dir/tarfs.cpp.o.requires

CMakeFiles/coursework.dir/tarfs.cpp.o.provides: CMakeFiles/coursework.dir/tarfs.cpp.o.requires
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/tarfs.cpp.o.provides.build
.PHONY : CMakeFiles/coursework.dir/tarfs.cpp.o.provides

CMakeFiles/coursework.dir/tarfs.cpp.o.provides.build: CMakeFiles/coursework.dir/tarfs.cpp.o


# Object files for target coursework
coursework_OBJECTS = \
"CMakeFiles/coursework.dir/buddy.cpp.o" \
"CMakeFiles/coursework.dir/sched-rr.cpp.o" \
"CMakeFiles/coursework.dir/tarfs.cpp.o"

# External object files for target coursework
coursework_EXTERNAL_OBJECTS = \
"/home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework/buddy.o" \
"/home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework/sched-rr.o" \
"/home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework/tarfs.o"

coursework: CMakeFiles/coursework.dir/buddy.cpp.o
coursework: CMakeFiles/coursework.dir/sched-rr.cpp.o
coursework: CMakeFiles/coursework.dir/tarfs.cpp.o
coursework: ../buddy.o
coursework: ../sched-rr.o
coursework: ../tarfs.o
coursework: CMakeFiles/coursework.dir/build.make
coursework: CMakeFiles/coursework.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable coursework"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/coursework.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/coursework.dir/build: coursework

.PHONY : CMakeFiles/coursework.dir/build

CMakeFiles/coursework.dir/requires: CMakeFiles/coursework.dir/buddy.cpp.o.requires
CMakeFiles/coursework.dir/requires: CMakeFiles/coursework.dir/sched-rr.cpp.o.requires
CMakeFiles/coursework.dir/requires: CMakeFiles/coursework.dir/tarfs.cpp.o.requires

.PHONY : CMakeFiles/coursework.dir/requires

CMakeFiles/coursework.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/coursework.dir/cmake_clean.cmake
.PHONY : CMakeFiles/coursework.dir/clean

CMakeFiles/coursework.dir/depend:
	cd /home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework /home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework /home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework/cmake-build-debug /home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework/cmake-build-debug /home/fdsfsdf/Desktop/OS_CW/os-coursework/coursework/cmake-build-debug/CMakeFiles/coursework.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/coursework.dir/depend


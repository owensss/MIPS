# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = "d:\Soft\CMake 2.8\bin\cmake.exe"

# The command to remove a file.
RM = "d:\Soft\CMake 2.8\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = "d:\Soft\CMake 2.8\bin\cmake-gui.exe"

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Dropbox\refactoring_MIPS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Dropbox\refactoring_MIPS\build

# Include any dependencies generated for this target.
include bin/CMakeFiles/assembler.dir/depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/assembler.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/assembler.dir/flags.make

bin/CMakeFiles/assembler.dir/MainParser.cpp.obj: bin/CMakeFiles/assembler.dir/flags.make
bin/CMakeFiles/assembler.dir/MainParser.cpp.obj: bin/CMakeFiles/assembler.dir/includes_CXX.rsp
bin/CMakeFiles/assembler.dir/MainParser.cpp.obj: ../src/MainParser.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report D:\Dropbox\refactoring_MIPS\build\CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object bin/CMakeFiles/assembler.dir/MainParser.cpp.obj"
	cd /d D:\Dropbox\refactoring_MIPS\build\bin && D:\Soft\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles\assembler.dir\MainParser.cpp.obj -c D:\Dropbox\refactoring_MIPS\src\MainParser.cpp

bin/CMakeFiles/assembler.dir/MainParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assembler.dir/MainParser.cpp.i"
	cd /d D:\Dropbox\refactoring_MIPS\build\bin && D:\Soft\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E D:\Dropbox\refactoring_MIPS\src\MainParser.cpp > CMakeFiles\assembler.dir\MainParser.cpp.i

bin/CMakeFiles/assembler.dir/MainParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assembler.dir/MainParser.cpp.s"
	cd /d D:\Dropbox\refactoring_MIPS\build\bin && D:\Soft\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S D:\Dropbox\refactoring_MIPS\src\MainParser.cpp -o CMakeFiles\assembler.dir\MainParser.cpp.s

bin/CMakeFiles/assembler.dir/MainParser.cpp.obj.requires:
.PHONY : bin/CMakeFiles/assembler.dir/MainParser.cpp.obj.requires

bin/CMakeFiles/assembler.dir/MainParser.cpp.obj.provides: bin/CMakeFiles/assembler.dir/MainParser.cpp.obj.requires
	$(MAKE) -f bin\CMakeFiles\assembler.dir\build.make bin/CMakeFiles/assembler.dir/MainParser.cpp.obj.provides.build
.PHONY : bin/CMakeFiles/assembler.dir/MainParser.cpp.obj.provides

bin/CMakeFiles/assembler.dir/MainParser.cpp.obj.provides.build: bin/CMakeFiles/assembler.dir/MainParser.cpp.obj

bin/CMakeFiles/assembler.dir/CodeParser.cpp.obj: bin/CMakeFiles/assembler.dir/flags.make
bin/CMakeFiles/assembler.dir/CodeParser.cpp.obj: bin/CMakeFiles/assembler.dir/includes_CXX.rsp
bin/CMakeFiles/assembler.dir/CodeParser.cpp.obj: ../src/CodeParser.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report D:\Dropbox\refactoring_MIPS\build\CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object bin/CMakeFiles/assembler.dir/CodeParser.cpp.obj"
	cd /d D:\Dropbox\refactoring_MIPS\build\bin && D:\Soft\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles\assembler.dir\CodeParser.cpp.obj -c D:\Dropbox\refactoring_MIPS\src\CodeParser.cpp

bin/CMakeFiles/assembler.dir/CodeParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assembler.dir/CodeParser.cpp.i"
	cd /d D:\Dropbox\refactoring_MIPS\build\bin && D:\Soft\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E D:\Dropbox\refactoring_MIPS\src\CodeParser.cpp > CMakeFiles\assembler.dir\CodeParser.cpp.i

bin/CMakeFiles/assembler.dir/CodeParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assembler.dir/CodeParser.cpp.s"
	cd /d D:\Dropbox\refactoring_MIPS\build\bin && D:\Soft\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S D:\Dropbox\refactoring_MIPS\src\CodeParser.cpp -o CMakeFiles\assembler.dir\CodeParser.cpp.s

bin/CMakeFiles/assembler.dir/CodeParser.cpp.obj.requires:
.PHONY : bin/CMakeFiles/assembler.dir/CodeParser.cpp.obj.requires

bin/CMakeFiles/assembler.dir/CodeParser.cpp.obj.provides: bin/CMakeFiles/assembler.dir/CodeParser.cpp.obj.requires
	$(MAKE) -f bin\CMakeFiles\assembler.dir\build.make bin/CMakeFiles/assembler.dir/CodeParser.cpp.obj.provides.build
.PHONY : bin/CMakeFiles/assembler.dir/CodeParser.cpp.obj.provides

bin/CMakeFiles/assembler.dir/CodeParser.cpp.obj.provides.build: bin/CMakeFiles/assembler.dir/CodeParser.cpp.obj

bin/CMakeFiles/assembler.dir/CommentParser.cpp.obj: bin/CMakeFiles/assembler.dir/flags.make
bin/CMakeFiles/assembler.dir/CommentParser.cpp.obj: bin/CMakeFiles/assembler.dir/includes_CXX.rsp
bin/CMakeFiles/assembler.dir/CommentParser.cpp.obj: ../src/CommentParser.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report D:\Dropbox\refactoring_MIPS\build\CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object bin/CMakeFiles/assembler.dir/CommentParser.cpp.obj"
	cd /d D:\Dropbox\refactoring_MIPS\build\bin && D:\Soft\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles\assembler.dir\CommentParser.cpp.obj -c D:\Dropbox\refactoring_MIPS\src\CommentParser.cpp

bin/CMakeFiles/assembler.dir/CommentParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assembler.dir/CommentParser.cpp.i"
	cd /d D:\Dropbox\refactoring_MIPS\build\bin && D:\Soft\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E D:\Dropbox\refactoring_MIPS\src\CommentParser.cpp > CMakeFiles\assembler.dir\CommentParser.cpp.i

bin/CMakeFiles/assembler.dir/CommentParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assembler.dir/CommentParser.cpp.s"
	cd /d D:\Dropbox\refactoring_MIPS\build\bin && D:\Soft\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S D:\Dropbox\refactoring_MIPS\src\CommentParser.cpp -o CMakeFiles\assembler.dir\CommentParser.cpp.s

bin/CMakeFiles/assembler.dir/CommentParser.cpp.obj.requires:
.PHONY : bin/CMakeFiles/assembler.dir/CommentParser.cpp.obj.requires

bin/CMakeFiles/assembler.dir/CommentParser.cpp.obj.provides: bin/CMakeFiles/assembler.dir/CommentParser.cpp.obj.requires
	$(MAKE) -f bin\CMakeFiles\assembler.dir\build.make bin/CMakeFiles/assembler.dir/CommentParser.cpp.obj.provides.build
.PHONY : bin/CMakeFiles/assembler.dir/CommentParser.cpp.obj.provides

bin/CMakeFiles/assembler.dir/CommentParser.cpp.obj.provides.build: bin/CMakeFiles/assembler.dir/CommentParser.cpp.obj

# Object files for target assembler
assembler_OBJECTS = \
"CMakeFiles/assembler.dir/MainParser.cpp.obj" \
"CMakeFiles/assembler.dir/CodeParser.cpp.obj" \
"CMakeFiles/assembler.dir/CommentParser.cpp.obj"

# External object files for target assembler
assembler_EXTERNAL_OBJECTS =

bin/assembler.exe: bin/CMakeFiles/assembler.dir/MainParser.cpp.obj
bin/assembler.exe: bin/CMakeFiles/assembler.dir/CodeParser.cpp.obj
bin/assembler.exe: bin/CMakeFiles/assembler.dir/CommentParser.cpp.obj
bin/assembler.exe: bin/CMakeFiles/assembler.dir/build.make
bin/assembler.exe: bin/CMakeFiles/assembler.dir/objects1.rsp
bin/assembler.exe: bin/CMakeFiles/assembler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable assembler.exe"
	cd /d D:\Dropbox\refactoring_MIPS\build\bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\assembler.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/assembler.dir/build: bin/assembler.exe
.PHONY : bin/CMakeFiles/assembler.dir/build

bin/CMakeFiles/assembler.dir/requires: bin/CMakeFiles/assembler.dir/MainParser.cpp.obj.requires
bin/CMakeFiles/assembler.dir/requires: bin/CMakeFiles/assembler.dir/CodeParser.cpp.obj.requires
bin/CMakeFiles/assembler.dir/requires: bin/CMakeFiles/assembler.dir/CommentParser.cpp.obj.requires
.PHONY : bin/CMakeFiles/assembler.dir/requires

bin/CMakeFiles/assembler.dir/clean:
	cd /d D:\Dropbox\refactoring_MIPS\build\bin && $(CMAKE_COMMAND) -P CMakeFiles\assembler.dir\cmake_clean.cmake
.PHONY : bin/CMakeFiles/assembler.dir/clean

bin/CMakeFiles/assembler.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Dropbox\refactoring_MIPS D:\Dropbox\refactoring_MIPS\src D:\Dropbox\refactoring_MIPS\build D:\Dropbox\refactoring_MIPS\build\bin D:\Dropbox\refactoring_MIPS\build\bin\CMakeFiles\assembler.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : bin/CMakeFiles/assembler.dir/depend

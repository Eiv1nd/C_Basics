# 1 About
These are my cheat sheets for the C programming language.




# 2 The Build process

## 2.1 The pre-processor

Handles every # command (include, define, ifndef, endif)
Runs before the compiler
Example: Reads the content of stdio.h and inserts this content where the #include line is. Then perform next # command
File is passed to the compiler

## 2.2 The compiler

Takes your code and builds each .c file to an .o (object) file.
This .o file is built for your CPU.
Syntax errors in your code are reported by the compiler
All the resulting .o files are sent to the linker.

#### GCC build options (GCC arguments)
`-std=c99`	**_Sets the language standard to C99_**  
`-Wall`		**_Turns on all warnings_**  
`-I`		**_Adds a folder to the #include search path_**  
`-o` 		**_Set the output (object) file name_**   


## 2.3 The linker
Input is the object files built by the compiler.
A linker "puts together" the executable from these objects and libraries.
The linker detects if any code is missing (linker error).


#### Static linking
* Requires headers for use
* Code is built into the binary
* EXE is larger
* Requires static libraries to build
* Usually requires a preprocessor definition (e.g. SFML_STATIC)

#### Dynamic linking
* Requires headers for use
* Requires external DLL/library files
* EXE is the same size as without lib
* Recommended on all platforms

#### Link options
`-L` 		**_Add a folder to the library search path_**  
`-l` 		**_Link with a specific library (followed by name)_**  
`-o`		**_Set the output file name_**  


## 2.4 Examples

**_Build and link in one step (default options)_**  
```bash
gcc main.c
./a.out
```

**_Build and link in one step and give your .exe a name_**  
```bash
gcc -o newname.exe main.c
```

**_Build and link in seperate steps_** 
```bash
gcc -c main.c  
gcc main.o
```

**_Build and link multiple files in seperate steps_**  
```bash
gcc -Wall -pedantic -std=c99 -c main.c file1.c file2.c  
gcc -lsdl2 -o project.exe *.o  
```



# 3 External libraries

#### Naming
* `i686-w64`		**_32bit library_**
* `x86_64-w64`	**_64bit library_**

#### Linux
* libsfml-graphics.so 	**_Dynamic library_**
* libsfml-graphics.a 		**_Static library_**

#### Windows
* `<name>.lib`			**_Dynamic library for release build_**
* `<name>-d.lib`			**_Dynamic library for debug build_**
* `<name>-s.lib`			**_Static library for release build_**
* `<name>-s-d.lib` 		**_Static library for debug build_**



# 4 Build systems
Build systems uses rules defined in a makefile to build software.

* CMake (cross platform, generates platform specific makefiles)
* SCons (cross platform, builds for you)
* Make (Unix / MinGW specific)
* MSBuild (Windows specific)

## 4.1 CMake

* `link_directories(directory1 directory2)`		**_Adding a library lib path. Only used for local paths in the project._**
* `include_directories(dir1 dir2)`				**_Adding a library include path. Only used for local paths in the project._**
* `target_link_libraries(target sfml-graphics sfml-window sfml-system)`	**_Linking with a library (SFML example)._**
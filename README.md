# 🎓 C Education Intermediate (`c-education-intermediate-20904`)

A comprehensive, interactive educational course hub and test suite written in **Standard C (C99)** designed to master intermediate-level C programming concepts.

---

## 📚 Course Modules & Curriculum

1. **🧠 Module 1: Pointers & Dynamic Memory Allocation**
   - Single & Double Pointers (`*`, `**`), address referencing & dereferencing
   - Pointer arithmetic & array offset calculations
   - Heap memory management: `malloc`, `realloc`, and `free` without memory leaks

2. **🌳 Module 2: Data Structures from Scratch**
   - **Singly Linked List**: Dynamic node allocation, insertion, deletion, and traversal
   - **Stack Buffer**: LIFO buffer with push, pop, overflow & underflow checks
   - **Binary Search Tree (BST)**: Recursive insertion, in-order traversal, and time complexity analysis

3. **📦 Module 3: Structs, Unions & Memory Alignment**
   - Struct padding, CPU word boundary alignment, and member ordering optimization
   - Unions and shared memory blocks
   - Bitfields for compact hardware flag registers

4. **⚡ Module 4: Function Pointers & Callbacks**
   - Dynamic dispatch tables with function pointers
   - Callback pattern and array transformation
   - Generic `qsort` with custom comparators

5. **🔢 Module 5: Bitwise Manipulation & Permissions**
   - Bitwise operations (`&`, `|`, `^`, `~`, `<<`, `>>`)
   - Industry-standard permission bitmasks (SET, CLEAR, TOGGLE, CHECK flags)

6. **💾 Module 6: File I/O & Serialization**
   - Text file reading and writing (`fopen`, `fprintf`, `fgets`, `fclose`)
   - Direct binary struct serialization using `fwrite` and `fread`

7. **🎓 Module 7: Interactive Mastery Quiz**
   - Comprehensive multi-topic quiz with real-time feedback, detailed explanations, scoring, and letter grades.

---

## 📂 Repository Structure

```
c-education-intermediate-20904/
├── src/
│   ├── main.c               # Interactive course hub & menu
│   ├── utils.h / .c         # Terminal styling, colors & cross-platform input
│   ├── pointers_memory.h/.c # Module 1: Pointers & Heap memory
│   ├── data_structures.h/.c # Module 2: Linked list, Stack, BST
│   ├── structs_unions.h/.c  # Module 3: Structs, Unions & Padding
│   ├── function_pointers.h/.c # Module 4: Function pointers & Callbacks
│   ├── bitwise_ops.h/.c     # Module 5: Bitwise operations & bitmasks
│   ├── file_io.h/.c         # Module 6: Text & binary file I/O
│   └── quiz.h/.c            # Module 7: Interactive assessment quiz
├── build.bat                # Windows 1-click build script
├── Makefile                 # Make compilation rules
├── CMakeLists.txt           # CMake build definition
├── play.py                  # Python launcher helper
└── README.md                # Documentation & curriculum
```

---

## 🚀 How to Build and Run

### Method 1: Using GCC / Clang (Recommended)

```bash
# Compile all modules
gcc -Wall -Wextra -std=c99 -O2 src/*.c -o c_education_intermediate

# Run on Windows:
.\c_education_intermediate.exe

# Run on Linux / macOS:
./c_education_intermediate
```

### Method 2: Using Make
```bash
make
make run
```

### Method 3: Windows Batch Script
Double-click `build.bat` or run:
```cmd
build.bat
```

---

## 📜 License

Open source under the MIT License.

# Sorting-Algorithm-Demo
Professional Merge Sort implementation in C++ with interactive user input and verification.  

This repository contains a clean, well-documented, and production-ready implementation of the Merge Sort algorithm.  
It demonstrates modern C++ practices, recursion, template programming, and robust error handling.

---

## Features
- Template-based Merge Sort for any numeric type (`int`, `long long`, etc.)  
- Interactive input: accepts integers separated by spaces or commas  
- Supports both ascending and descending sorting  
- Verification of correctness after sorting  
- Professional console output formatting  
- Time Complexity: O(n log n)  
- Space Complexity: O(n) due to temporary arrays during merging  

---

## Prerequisites
Make sure you have a C++ compiler installed:  
- g++ (Linux / macOS)  
- MinGW or MSVC (Windows)

## Running the Program
1. Clone the repository:
   ```bash
   git clone https://github.com/YOUR-USERNAME/merge-sort-cpp.git
   cd merge-sort-cpp
   ```

2. Compile the program:
```bash
    g++ main.cpp -o mergesort
```
3. Run the program:
```bash
   ./mergesort //for Linux / macOS
    mergesort.exe //for Windows
```

4. Enter integers separated by spaces or commas when prompted.
   
5. After the sort, the program will display:
- Original input
- Sorted data (ascending)
- Sorted data (descending)
- Verification of correctness

6. The program will then ask if you want to run again or exit.

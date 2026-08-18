#include <stdio.h>
#include <stdlib.h>
#include "pointers_memory.h"
#include "utils.h"

static void demo_pointer_basics(void) {
    clear_screen();
    print_header("LESSON 1.1: POINTERS & DEREFERENCING", "Understanding memory addresses and values");

    int num = 42;
    int *ptr = &num;
    int **double_ptr = &ptr;

    printf(COLOR_GREEN "Code snippet:" COLOR_RESET "\n");
    printf("  int num = 42;\n");
    printf("  int *ptr = &num;          // ptr holds address of num\n");
    printf("  int **double_ptr = &ptr;  // double_ptr holds address of ptr\n\n");

    printf(COLOR_YELLOW "Live Memory Inspection:" COLOR_RESET "\n");
    printf("  Variable 'num':        Value = " COLOR_GREEN "%d" COLOR_RESET "  | Address = " COLOR_CYAN "%p\n" COLOR_RESET, num, (void*)&num);
    printf("  Pointer 'ptr':         Points to = " COLOR_CYAN "%p" COLOR_RESET " | Dereferenced (*ptr) = " COLOR_GREEN "%d" COLOR_RESET " | Address = " COLOR_MAGENTA "%p\n" COLOR_RESET, (void*)ptr, *ptr, (void*)&ptr);
    printf("  Double Pointer '**':   Points to = " COLOR_MAGENTA "%p" COLOR_RESET " | **double_ptr = " COLOR_GREEN "%d\n\n" COLOR_RESET, (void*)double_ptr, **double_ptr);

    printf(COLOR_WHITE "Modifying value via pointer: *ptr = 100;\n" COLOR_RESET);
    *ptr = 100;
    printf("  Now num = " COLOR_GREEN "%d" COLOR_RESET " (Updated directly in memory!)\n", num);

    pause_prompt();
}

static void demo_pointer_arithmetic(void) {
    clear_screen();
    print_header("LESSON 1.2: POINTER ARITHMETIC", "How C navigates arrays through pointer offsets");

    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr; // points to arr[0]

    printf(COLOR_GREEN "Array Base Address: " COLOR_CYAN "%p\n\n" COLOR_RESET, (void*)arr);
    printf("Address Calculation Formula: " COLOR_YELLOW "address = base + (index * sizeof(type))\n\n" COLOR_RESET);

    for (int i = 0; i < 5; i++) {
        printf("  *(p + %d) -> Address: " COLOR_CYAN "%p" COLOR_RESET " | Value: " COLOR_GREEN "%d" COLOR_RESET " (Byte Offset: +%d)\n",
               i, (void*)(p + i), *(p + i), (int)(i * sizeof(int)));
    }

    printf("\n" COLOR_WHITE "Notice how each address increments by " COLOR_YELLOW "%d bytes" COLOR_WHITE " (sizeof(int))!\n" COLOR_RESET, (int)sizeof(int));
    pause_prompt();
}

static void demo_dynamic_memory(void) {
    clear_screen();
    print_header("LESSON 1.3: DYNAMIC MEMORY ALLOCATION", "malloc, calloc, realloc, and free on the Heap");

    printf(COLOR_GREEN "1. Allocating with malloc(3 * sizeof(int)):" COLOR_RESET "\n");
    int *heap_arr = (int*)malloc(3 * sizeof(int));
    if (!heap_arr) {
        printf(COLOR_RED "Allocation failed!\n" COLOR_RESET);
        return;
    }

    for (int i = 0; i < 3; i++) {
        heap_arr[i] = (i + 1) * 100;
        printf("   heap_arr[%d] = %d (Address: %p)\n", i, heap_arr[i], (void*)&heap_arr[i]);
    }

    printf("\n" COLOR_GREEN "2. Expanding size using realloc(heap_arr, 5 * sizeof(int)):" COLOR_RESET "\n");
    int *expanded = (int*)realloc(heap_arr, 5 * sizeof(int));
    if (expanded) {
        heap_arr = expanded;
        heap_arr[3] = 400;
        heap_arr[4] = 500;
        for (int i = 0; i < 5; i++) {
            printf("   heap_arr[%d] = %d (Address: %p)\n", i, heap_arr[i], (void*)&heap_arr[i]);
        }
    }

    printf("\n" COLOR_RED "3. Freeing memory with free(heap_arr) & setting to NULL to prevent dangling pointer:\n" COLOR_RESET);
    free(heap_arr);
    heap_arr = NULL;
    printf(COLOR_GREEN "   Memory successfully released to OS!\n" COLOR_RESET);

    pause_prompt();
}

void run_pointers_memory_module(void) {
    int choice = 0;
    while (1) {
        clear_screen();
        print_header("MODULE 1: POINTERS & DYNAMIC MEMORY", "Mastering raw memory in C");
        printf(COLOR_GREEN "  [1] Pointer Basics & Dereferencing (*, **)\n" COLOR_RESET);
        printf(COLOR_GREEN "  [2] Pointer Arithmetic & Array Indexing\n" COLOR_RESET);
        printf(COLOR_GREEN "  [3] Dynamic Memory Allocation (malloc, realloc, free)\n" COLOR_RESET);
        printf(COLOR_RED   "  [4] Return to Course Hub\n\n" COLOR_RESET);
        printf(COLOR_YELLOW "Enter choice (1-4): " COLOR_RESET);

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: demo_pointer_basics(); break;
            case 2: demo_pointer_arithmetic(); break;
            case 3: demo_dynamic_memory(); break;
            case 4: return;
            default: break;
        }
    }
}

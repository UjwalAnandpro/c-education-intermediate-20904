#include <stdio.h>
#include <stdlib.h>
#include "function_pointers.h"
#include "utils.h"

static int add(int a, int b) { return a + b; }
static int multiply(int a, int b) { return a * b; }
static int subtract(int a, int b) { return a - b; }

typedef int (*OperationFunc)(int, int);

static void execute_math_op(const char* op_name, OperationFunc func, int x, int y) {
    int result = func(x, y);
    printf("  Operation: " COLOR_CYAN "%-12s" COLOR_RESET " | Inputs: (%d, %d) | Result = " COLOR_GREEN "%d\n" COLOR_RESET, op_name, x, y, result);
}

// Callback array mapper
typedef void (*TransformCallback)(int*);

static void square_val(int* x) { *x = (*x) * (*x); }
static void double_val(int* x) { *x = (*x) * 2; }

static void map_array(int* arr, int size, TransformCallback cb) {
    for (int i = 0; i < size; i++) {
        cb(&arr[i]);
    }
}

// Custom comparator for qsort
static int compare_asc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

static int compare_desc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

static void demo_function_pointers_basic(void) {
    clear_screen();
    print_header("LESSON 4.1: FUNCTION POINTER BASICS", "Storing function addresses and dynamic dispatch");

    printf(COLOR_GREEN "Function Pointer Syntax:\n" COLOR_RESET);
    printf("  int (*OperationFunc)(int, int);\n\n");

    printf(COLOR_YELLOW "Dynamic Dispatch Table Execution:\n" COLOR_RESET);
    execute_math_op("Addition", add, 12, 8);
    execute_math_op("Subtraction", subtract, 12, 8);
    execute_math_op("Multiplication", multiply, 12, 8);

    pause_prompt();
}

static void demo_callback_transformers(void) {
    clear_screen();
    print_header("LESSON 4.2: CALLBACKS & HIGHER-ORDER FUNCTIONS", "Transforming arrays using function callbacks");

    int numbers1[4] = {2, 4, 6, 8};
    int numbers2[4] = {2, 4, 6, 8};

    printf(COLOR_CYAN "Original Array: [2, 4, 6, 8]\n\n" COLOR_RESET);

    map_array(numbers1, 4, double_val);
    printf(COLOR_GREEN "After map_array(numbers, double_val): " COLOR_RESET "[");
    for (int i = 0; i < 4; i++) printf("%d%s", numbers1[i], i == 3 ? "" : ", ");
    printf("]\n");

    map_array(numbers2, 4, square_val);
    printf(COLOR_GREEN "After map_array(numbers, square_val): " COLOR_RESET "[");
    for (int i = 0; i < 4; i++) printf("%d%s", numbers2[i], i == 3 ? "" : ", ");
    printf("]\n");

    pause_prompt();
}

static void demo_generic_qsort(void) {
    clear_screen();
    print_header("LESSON 4.3: GENERIC QSORT WITH COMPARATORS", "Standard Library polymorphism in pure C");

    int dataset[] = {45, 12, 89, 3, 67, 23, 99};
    int n = sizeof(dataset) / sizeof(dataset[0]);

    printf(COLOR_WHITE "Initial Dataset: [45, 12, 89, 3, 67, 23, 99]\n\n" COLOR_RESET);

    qsort(dataset, n, sizeof(int), compare_asc);
    printf(COLOR_GREEN "Sorted Ascending (qsort + compare_asc):   " COLOR_RESET "[");
    for (int i = 0; i < n; i++) printf("%d%s", dataset[i], i == n - 1 ? "" : ", ");
    printf("]\n");

    qsort(dataset, n, sizeof(int), compare_desc);
    printf(COLOR_YELLOW "Sorted Descending (qsort + compare_desc):  " COLOR_RESET "[");
    for (int i = 0; i < n; i++) printf("%d%s", dataset[i], i == n - 1 ? "" : ", ");
    printf("]\n");

    pause_prompt();
}

void run_function_pointers_module(void) {
    int choice = 0;
    while (1) {
        clear_screen();
        print_header("MODULE 4: FUNCTION POINTERS & CALLBACKS", "Dynamic dispatch and generic abstractions in C");
        printf(COLOR_GREEN "  [1] Function Pointers & Dispatch Tables\n" COLOR_RESET);
        printf(COLOR_GREEN "  [2] Callback Pattern & Array Mapping\n" COLOR_RESET);
        printf(COLOR_GREEN "  [3] Generic qsort & Custom Comparators\n" COLOR_RESET);
        printf(COLOR_RED   "  [4] Return to Course Hub\n\n" COLOR_RESET);
        printf(COLOR_YELLOW "Enter choice (1-4): " COLOR_RESET);

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: demo_function_pointers_basic(); break;
            case 2: demo_callback_transformers(); break;
            case 3: demo_generic_qsort(); break;
            case 4: return;
            default: break;
        }
    }
}

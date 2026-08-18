#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "pointers_memory.h"
#include "data_structures.h"
#include "structs_unions.h"
#include "function_pointers.h"
#include "bitwise_ops.h"
#include "file_io.h"
#include "quiz.h"

static void display_course_menu(void) {
    clear_screen();
    printf(COLOR_CYAN "╔═══════════════════════════════════════════════════════════════════════╗\n" COLOR_RESET);
    printf(COLOR_CYAN "║" COLOR_YELLOW "               C INTERMEDIATE EDUCATION COURSE HUB                     " COLOR_CYAN "║\n" COLOR_RESET);
    printf(COLOR_CYAN "║" COLOR_WHITE  "        Interactive Deep Dive into Advanced C Programming              " COLOR_CYAN "║\n" COLOR_RESET);
    printf(COLOR_CYAN "╚═══════════════════════════════════════════════════════════════════════╝\n\n" COLOR_RESET);

    printf(COLOR_GREEN   "  [1] 🧠 Module 1: Pointers, Double Pointers & Heap Memory (malloc/free)\n" COLOR_RESET);
    printf(COLOR_GREEN   "  [2] 🌳 Module 2: Data Structures in C (Linked List, Stack, BST)\n" COLOR_RESET);
    printf(COLOR_GREEN   "  [3] 📦 Module 3: Structs, Unions, Bitfields & Memory Padding\n" COLOR_RESET);
    printf(COLOR_GREEN   "  [4] ⚡ Module 4: Function Pointers, Callbacks & Generic Sorts\n" COLOR_RESET);
    printf(COLOR_GREEN   "  [5] 🔢 Module 5: Bitwise Operations & Permission Bitmasks\n" COLOR_RESET);
    printf(COLOR_GREEN   "  [6] 💾 Module 6: File I/O & Binary Struct Serialization\n" COLOR_RESET);
    printf(COLOR_YELLOW  "  [7] 🎓 Module 7: Interactive Mastery Quiz & Knowledge Check\n" COLOR_RESET);
    printf(COLOR_RED     "  [8] 🚪 Exit Course Hub\n\n" COLOR_RESET);
    printf(COLOR_YELLOW  "Select a module (1-8): " COLOR_RESET);
}

int main(void) {
    int choice = 0;

    while (1) {
        display_course_menu();

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: run_pointers_memory_module(); break;
            case 2: run_data_structures_module(); break;
            case 3: run_structs_unions_module(); break;
            case 4: run_function_pointers_module(); break;
            case 5: run_bitwise_module(); break;
            case 6: run_file_io_module(); break;
            case 7: run_quiz_module(); break;
            case 8:
                clear_screen();
                printf(COLOR_GREEN "\nThank you for learning Intermediate C! Keep coding and building!\n\n" COLOR_RESET);
                return 0;
            default:
                break;
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "structs_unions.h"
#include "utils.h"

struct Unpadded {
    char a;     // 1 byte
    int b;      // 4 bytes
    char c;     // 1 byte
};

struct Optimized {
    int b;      // 4 bytes
    char a;     // 1 byte
    char c;     // 1 byte
};

union DataHolder {
    int i;
    float f;
    char str[20];
};

struct Flags {
    unsigned int is_active : 1;  // 1 bit
    unsigned int has_admin : 1;  // 1 bit
    unsigned int theme_id  : 4;  // 4 bits (0-15)
};

static void demo_struct_padding(void) {
    clear_screen();
    print_header("LESSON 3.1: STRUCT MEMORY PADDING & ALIGNMENT", "Why sizeof(struct) is larger than sum of its members");

    printf(COLOR_CYAN "Structure Definition 1 (Naive order):\n" COLOR_RESET);
    printf("  struct Unpadded {\n    char a;  // 1 byte\n    int b;   // 4 bytes\n    char c;  // 1 byte\n  };\n");
    printf(COLOR_YELLOW "  Total sizeof(struct Unpadded) = %d bytes!\n" COLOR_RESET, (int)sizeof(struct Unpadded));
    printf(COLOR_WHITE "  (Explanation: Compiler inserts 3 padding bytes after 'a' and 3 after 'c' for 4-byte CPU word alignment).\n\n" COLOR_RESET);

    printf(COLOR_CYAN "Structure Definition 2 (Optimized order):\n" COLOR_RESET);
    printf("  struct Optimized {\n    int b;   // 4 bytes\n    char a;  // 1 byte\n    char c;  // 1 byte\n  };\n");
    printf(COLOR_GREEN "  Total sizeof(struct Optimized) = %d bytes!\n\n" COLOR_RESET, (int)sizeof(struct Optimized));

    printf(COLOR_MAGENTA "💡 Best Practice: Order struct members from largest type to smallest type to minimize padding overhead!\n" COLOR_RESET);
    pause_prompt();
}

static void demo_unions(void) {
    clear_screen();
    print_header("LESSON 3.2: UNIONS & SHARED MEMORY", "Overlapping memory locations for different data representations");

    union DataHolder data;
    printf(COLOR_CYAN "Union Definition:\n" COLOR_RESET);
    printf("  union DataHolder {\n    int i;        // 4 bytes\n    float f;      // 4 bytes\n    char str[20]; // 20 bytes\n  };\n");
    printf(COLOR_YELLOW "  sizeof(union DataHolder) = %d bytes (equal to largest member)!\n\n" COLOR_RESET, (int)sizeof(union DataHolder));

    data.i = 1024;
    printf("1. Setting data.i = 1024:\n");
    printf("   data.i = " COLOR_GREEN "%d" COLOR_RESET "\n\n", data.i);

    data.f = 3.14159f;
    printf("2. Setting data.f = 3.14159:\n");
    printf("   data.f = " COLOR_GREEN "%f" COLOR_RESET "\n", data.f);
    printf("   data.i is now corrupted = " COLOR_RED "%d" COLOR_RESET " (because memory is shared!)\n\n", data.i);

    pause_prompt();
}

static void demo_bitfields(void) {
    clear_screen();
    print_header("LESSON 3.3: BITFIELDS & COMPACT FLAGS", "Packing multiple boolean/enum flags into single bytes");

    struct Flags user_flags = {1, 0, 7};
    printf(COLOR_CYAN "Bitfield Struct:\n" COLOR_RESET);
    printf("  struct Flags {\n    unsigned int is_active : 1; // 1 bit\n    unsigned int has_admin : 1; // 1 bit\n    unsigned int theme_id  : 4; // 4 bits (0-15)\n  };\n\n");

    printf(COLOR_YELLOW "Total Size: %d bytes (stores 3 distinct fields in single machine word)\n\n" COLOR_RESET, (int)sizeof(struct Flags));
    printf("  is_active: " COLOR_GREEN "%u" COLOR_RESET "\n", user_flags.is_active);
    printf("  has_admin: " COLOR_GREEN "%u" COLOR_RESET "\n", user_flags.has_admin);
    printf("  theme_id : " COLOR_GREEN "%u" COLOR_RESET "\n", user_flags.theme_id);

    pause_prompt();
}

void run_structs_unions_module(void) {
    int choice = 0;
    while (1) {
        clear_screen();
        print_header("MODULE 3: STRUCTS, UNIONS & MEMORY ALIGNMENT", "Low-level data representation and memory layout");
        printf(COLOR_GREEN "  [1] Struct Padding & CPU Alignment\n" COLOR_RESET);
        printf(COLOR_GREEN "  [2] Unions & Shared Memory Blocks\n" COLOR_RESET);
        printf(COLOR_GREEN "  [3] Bitfields & Compact Hardware Registers\n" COLOR_RESET);
        printf(COLOR_RED   "  [4] Return to Course Hub\n\n" COLOR_RESET);
        printf(COLOR_YELLOW "Enter choice (1-4): " COLOR_RESET);

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: demo_struct_padding(); break;
            case 2: demo_unions(); break;
            case 3: demo_bitfields(); break;
            case 4: return;
            default: break;
        }
    }
}

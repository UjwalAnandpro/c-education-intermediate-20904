#include <stdio.h>
#include <stdlib.h>
#include "bitwise_ops.h"
#include "utils.h"

static void print_binary_8(unsigned char val) {
    for (int i = 7; i >= 0; i--) {
        if ((val >> i) & 1) {
            printf(COLOR_GREEN "1" COLOR_RESET);
        } else {
            printf(COLOR_WHITE "0" COLOR_RESET);
        }
        if (i == 4) printf(" ");
    }
}

static void demo_bitwise_operators(void) {
    clear_screen();
    print_header("LESSON 5.1: BITWISE OPERATORS (&, |, ^, ~, <<, >>)", "Low-level binary operations at hardware level");

    unsigned char a = 0b00111100; // 60
    unsigned char b = 0b00001101; // 13

    printf("  Variable A = %3d (Binary: ", a); print_binary_8(a); printf(")\n");
    printf("  Variable B = %3d (Binary: ", b); print_binary_8(b); printf(")\n\n");

    printf(COLOR_CYAN "1. Bitwise AND (a & b):    " COLOR_RESET);
    print_binary_8(a & b);
    printf(" = %d\n", a & b);

    printf(COLOR_CYAN "2. Bitwise OR  (a | b):    " COLOR_RESET);
    print_binary_8(a | b);
    printf(" = %d\n", a | b);

    printf(COLOR_CYAN "3. Bitwise XOR (a ^ b):    " COLOR_RESET);
    print_binary_8(a ^ b);
    printf(" = %d\n", a ^ b);

    printf(COLOR_CYAN "4. Bitwise NOT (~a):       " COLOR_RESET);
    print_binary_8((unsigned char)~a);
    printf(" = %d\n", (unsigned char)~a);

    printf(COLOR_CYAN "5. Left Shift  (a << 2):   " COLOR_RESET);
    print_binary_8(a << 2);
    printf(" = %d (Multiplication by 2^2)\n", a << 2);

    printf(COLOR_CYAN "6. Right Shift (a >> 2):   " COLOR_RESET);
    print_binary_8(a >> 2);
    printf(" = %d (Division by 2^2)\n", a >> 2);

    pause_prompt();
}

#define PERM_READ    (1 << 0) // 0001
#define PERM_WRITE   (1 << 1) // 0010
#define PERM_EXEC    (1 << 2) // 0100
#define PERM_ADMIN   (1 << 3) // 1000

static void demo_bitmask_flags(void) {
    clear_screen();
    print_header("LESSON 5.2: BITMASKS & PERMISSION FLAGS", "Industry standard bit manipulation patterns");

    unsigned char user_perms = 0;
    printf(COLOR_WHITE "Initial permissions: None (" COLOR_RESET); print_binary_8(user_perms); printf(")\n\n");

    // SET bits
    user_perms |= (PERM_READ | PERM_WRITE);
    printf(COLOR_GREEN "1. Granting READ and WRITE (perms |= READ | WRITE):\n   " COLOR_RESET);
    print_binary_8(user_perms);
    printf(" (Decimal: %d)\n\n", user_perms);

    // CHECK bit
    printf(COLOR_YELLOW "2. Checking permissions:\n" COLOR_RESET);
    printf("   Has READ permission?  %s\n", (user_perms & PERM_READ) ? "✅ YES" : "❌ NO");
    printf("   Has ADMIN permission? %s\n\n", (user_perms & PERM_ADMIN) ? "✅ YES" : "❌ NO");

    // TOGGLE bit
    user_perms ^= PERM_EXEC;
    printf(COLOR_CYAN "3. Toggling EXECUTE permission (perms ^= EXEC):\n   " COLOR_RESET);
    print_binary_8(user_perms);
    printf("\n\n");

    // CLEAR bit
    user_perms &= ~PERM_WRITE;
    printf(COLOR_RED "4. Revoking WRITE permission (perms &= ~WRITE):\n   " COLOR_RESET);
    print_binary_8(user_perms);
    printf("\n");

    pause_prompt();
}

void run_bitwise_module(void) {
    int choice = 0;
    while (1) {
        clear_screen();
        print_header("MODULE 5: BITWISE MANIPULATION & REGISTERS", "Hardware-level bit processing in C");
        printf(COLOR_GREEN "  [1] Bitwise Operators (&, |, ^, ~, <<, >>)\n" COLOR_RESET);
        printf(COLOR_GREEN "  [2] Bitmasks, Permission Flags & Bit Flipping\n" COLOR_RESET);
        printf(COLOR_RED   "  [3] Return to Course Hub\n\n" COLOR_RESET);
        printf(COLOR_YELLOW "Enter choice (1-3): " COLOR_RESET);

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: demo_bitwise_operators(); break;
            case 2: demo_bitmask_flags(); break;
            case 3: return;
            default: break;
        }
    }
}

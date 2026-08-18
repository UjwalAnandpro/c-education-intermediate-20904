#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_io.h"
#include "utils.h"

typedef struct {
    int id;
    char name[32];
    double gpa;
} StudentRecord;

static void demo_text_file_io(void) {
    clear_screen();
    print_header("LESSON 6.1: TEXT FILE I/O", "fopen, fprintf, fgets, fclose");

    const char* filename = "demo_text.txt";
    FILE* fp = fopen(filename, "w");
    if (!fp) {
        printf(COLOR_RED "Error opening file for write!\n" COLOR_RESET);
        return;
    }

    fprintf(fp, "Line 1: Intermediate C Programming\n");
    fprintf(fp, "Line 2: File Handling Demonstration\n");
    fprintf(fp, "Line 3: Clean Resource Management\n");
    fclose(fp);

    printf(COLOR_GREEN "✅ Successfully wrote 3 lines to '%s'!\n\n" COLOR_RESET, filename);

    // Reading back
    printf(COLOR_YELLOW "Reading content back with fgets():\n" COLOR_RESET);
    fp = fopen(filename, "r");
    if (fp) {
        char buffer[128];
        while (fgets(buffer, sizeof(buffer), fp)) {
            printf("  📄 %s", buffer);
        }
        fclose(fp);
    }

    remove(filename);
    pause_prompt();
}

static void demo_binary_struct_serialization(void) {
    clear_screen();
    print_header("LESSON 6.2: BINARY STRUCT SERIALIZATION", "fwrite & fread for direct memory dumping to disk");

    const char* bin_file = "student_data.bin";
    StudentRecord original = {101, "Alice Johnson", 3.92};

    printf(COLOR_CYAN "Original In-Memory Struct:\n" COLOR_RESET);
    printf("  ID: %d | Name: %s | GPA: %.2f\n\n", original.id, original.name, original.gpa);

    // Write to binary
    FILE* fp = fopen(bin_file, "wb");
    if (fp) {
        fwrite(&original, sizeof(StudentRecord), 1, fp);
        fclose(fp);
        printf(COLOR_GREEN "✅ Serialized %d bytes directly to '%s' with fwrite()!\n\n" COLOR_RESET, (int)sizeof(StudentRecord), bin_file);
    }

    // Read into fresh struct
    StudentRecord loaded = {0};
    fp = fopen(bin_file, "rb");
    if (fp) {
        fread(&loaded, sizeof(StudentRecord), 1, fp);
        fclose(fp);
        printf(COLOR_YELLOW "Deserialized Struct from Disk with fread():\n" COLOR_RESET);
        printf("  Loaded ID:   " COLOR_GREEN "%d\n" COLOR_RESET, loaded.id);
        printf("  Loaded Name: " COLOR_GREEN "%s\n" COLOR_RESET, loaded.name);
        printf("  Loaded GPA:  " COLOR_GREEN "%.2f\n" COLOR_RESET, loaded.gpa);
    }

    remove(bin_file);
    pause_prompt();
}

void run_file_io_module(void) {
    int choice = 0;
    while (1) {
        clear_screen();
        print_header("MODULE 6: FILE I/O & STRUCT SERIALIZATION", "Persistent data storage in text and binary formats");
        printf(COLOR_GREEN "  [1] Text File Reading & Writing\n" COLOR_RESET);
        printf(COLOR_GREEN "  [2] Binary Struct Serialization (fwrite/fread)\n" COLOR_RESET);
        printf(COLOR_RED   "  [3] Return to Course Hub\n\n" COLOR_RESET);
        printf(COLOR_YELLOW "Enter choice (1-3): " COLOR_RESET);

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: demo_text_file_io(); break;
            case 2: demo_binary_struct_serialization(); break;
            case 3: return;
            default: break;
        }
    }
}

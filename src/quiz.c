#include <stdio.h>
#include <stdlib.h>
#include "quiz.h"
#include "utils.h"

typedef struct {
    const char* question;
    const char* options[4];
    int correct_option;
    const char* explanation;
} QuizQuestion;

static QuizQuestion questions[] = {
    {
        "What does 'int *p = (int*)malloc(sizeof(int));' do?",
        {"Allocates memory on the Stack", "Allocates memory on the Heap", "Creates a global static variable", "Allocates memory inside CPU cache"},
        2,
        "malloc() dynamically requests memory from the OS on the Heap at runtime."
    },
    {
        "If 'int arr[5];', what is equivalent to '*(arr + 3)'?",
        {"arr[3]", "&arr[3]", "arr + 3", "*arr[3]"},
        1,
        "In C, array indexing arr[i] is syntactically translated directly to *(arr + i)."
    },
    {
        "Why does 'struct { char a; int b; char c; }' usually take 12 bytes instead of 6 bytes?",
        {"Stack corruption", "Byte alignment and CPU padding", "Unicode character encoding", "Memory leak"},
        2,
        "Compilers insert padding bytes so multi-byte data types align with machine word boundaries (e.g. 4-byte boundaries)."
    },
    {
        "What happens to the members of a 'union'?",
        {"Each member has distinct separate memory", "All members share the same base memory address", "Members are dynamically allocated", "Members cannot be modified"},
        2,
        "A union shares memory among all its members; the total size equals the size of its largest member."
    },
    {
        "What is the result of the bitwise expression 'x ^ x' for any integer x?",
        {"x", "1", "0", "~x"},
        3,
        "XORing any number with itself cancels all identical bits and always results in 0."
    }
};

void run_quiz_module(void) {
    int total = sizeof(questions) / sizeof(questions[0]);
    int score = 0;

    clear_screen();
    print_header("MODULE 7: INTERMEDIATE C MASTERY QUIZ", "Test your knowledge across all 6 core modules");
    printf(COLOR_CYAN "You will be presented with %d questions. Select option (1-4) for each.\n\n" COLOR_RESET, total);
    pause_prompt();

    for (int i = 0; i < total; i++) {
        clear_screen();
        print_header("MASTERY QUIZ", "Question assessment");
        printf(COLOR_YELLOW "Question %d of %d:\n" COLOR_RESET, i + 1, total);
        printf(COLOR_WHITE "%s\n\n" COLOR_RESET, questions[i].question);

        for (int opt = 0; opt < 4; opt++) {
            printf("  [%d] %s\n", opt + 1, questions[i].options[opt]);
        }

        int user_choice = 0;
        printf(COLOR_YELLOW "\nYour answer (1-4): " COLOR_RESET);
        while (scanf("%d", &user_choice) != 1 || user_choice < 1 || user_choice > 4) {
            while (getchar() != '\n');
            printf(COLOR_RED "Invalid choice. Please enter 1, 2, 3, or 4: " COLOR_RESET);
        }

        if (user_choice == questions[i].correct_option) {
            printf(COLOR_GREEN "\n🎉 CORRECT! " COLOR_RESET);
            score++;
        } else {
            printf(COLOR_RED "\n❌ INCORRECT! " COLOR_RESET);
            printf("Correct answer was: " COLOR_GREEN "[%d] %s\n" COLOR_RESET,
                   questions[i].correct_option, questions[i].options[questions[i].correct_option - 1]);
        }

        printf(COLOR_CYAN "💡 Explanation: " COLOR_RESET "%s\n", questions[i].explanation);
        pause_prompt();
    }

    clear_screen();
    print_header("QUIZ RESULTS SUMMARY", "Final Score & Grade");
    printf(COLOR_WHITE "Your Final Score: " COLOR_YELLOW "%d / %d" COLOR_WHITE " (%.1f%%)\n\n" COLOR_RESET,
           score, total, (score * 100.0) / total);

    if (score == total) {
        printf(COLOR_GREEN "🏆 GRADE: A+ (MASTER OF C PROGRAMMING! Exceptional understanding!)\n" COLOR_RESET);
    } else if (score >= 3) {
        printf(COLOR_YELLOW "⭐ GRADE: B (SOLID INTERMEDIATE FOUNDATION! Keep practicing!)\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "📚 GRADE: C (Review the course modules to strengthen your concepts.)\n" COLOR_RESET);
    }

    pause_prompt();
}

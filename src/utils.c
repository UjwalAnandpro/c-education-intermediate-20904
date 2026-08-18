#include "utils.h"

void clear_screen(void) {
#ifdef _WIN32
    system("cls");
#else
    printf("\033[H\033[J");
    fflush(stdout);
#endif
}

void sleep_ms(int ms) {
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}

int custom_getch(void) {
#ifdef _WIN32
    return _getch();
#else
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    int ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
#endif
}

void print_header(const char* title, const char* subtitle) {
    printf(COLOR_CYAN "═════════════════════════════════════════════════════════════════════════\n" COLOR_RESET);
    printf(COLOR_YELLOW "  📖 %s\n" COLOR_RESET, title);
    if (subtitle && strlen(subtitle) > 0) {
        printf(COLOR_WHITE  "     %s\n" COLOR_RESET, subtitle);
    }
    printf(COLOR_CYAN "═════════════════════════════════════════════════════════════════════════\n\n" COLOR_RESET);
}

void pause_prompt(void) {
    printf(COLOR_CYAN "\n[Press any key to continue...]" COLOR_RESET);
    custom_getch();
    printf("\n");
}

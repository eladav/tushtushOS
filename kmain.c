#include "system.h"

void print_logo() {
    char *line1 = "  _             _     _             _      ___  ____                            ";
    char *line2 = " | |_ _   _ ___| |__ | |_ _   _ ___| |__  / _ \\/ ___|                           ";
    char *line3 = " | __| | | / __| '_ \\| __| | | / __| '_ \\| | | \\___ \\                           ";
    char *line4 = " | |_| |_| \\__ \\ | | | |_| |_| \\__ \\ | | | |_| |___) |                          ";
    char *line5 = "  \\__|\\__,_|___/_| |_|\\__|\\__,_|___/_| |_|\\___/|____/                           ";
    char *line6 = "                                                                                ";
    write(line1, 80);
    write(line2, 80);
    write(line3, 80);
    write(line4, 80);
    write(line5, 80);
    write(line6, 80);
}

int kmain() {
    clear_screen();
    print_logo();
    return 0;
}
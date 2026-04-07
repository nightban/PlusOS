#include "screen.h"

char *video = (char*)0xB8000;

int cursor = 0;

void clear_screen() {
    for (int i = 0; i < 80 * 25; i++) {
        video[i * 2] = ' ';
        video[i * 2 + 1] = 0x07;
    }
    cursor = 0;
}

void print(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        print_char(str[i]);
    }
}

void print_char(char c) {
    video[cursor * 2] = c;
    video[cursor * 2 + 1] = 0x07;
    cursor++;
}

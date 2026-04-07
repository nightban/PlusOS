#include "screen.h"

volatile char* video = (volatile char*)0xB8000;

void clear_screen() {
    for (int i = 0; i < 80 * 25; i++) {
        video[i * 2] = ' ';
        video[i * 2 + 1] = 0x07;
    }
}

void print_char(char c) {
    static int pos = 0;
    video[pos * 2] = c;
    video[pos * 2 + 1] = 0x07;
    pos++;
}

void print(const char* str) {
    int i = 0;
    while (str[i]) {
        print_char(str[i]);
        i++;
    }
}

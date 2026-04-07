#include "screen.h"
#include "keyboard.h"

void kernel_main() {
    clear_screen();

    print("PlusOS Lite 0.1\n");
    print("Keyboard test: type something\n");

    while (1) {
        char c = keyboard_getchar();
        if (c != 0) {
            print_char(c);
        }
    }
}

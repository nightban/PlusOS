#include <stdint.h>

typedef struct {
    uint32_t* addr;
    uint32_t width;
    uint32_t height;
    uint32_t pitch;
    uint32_t bpp;
} framebuffer_t;

framebuffer_t fb;

void put_pixel(int x, int y, uint32_t color) {
    uint32_t* pixel = (uint32_t*)((uint8_t*)fb.addr + y * fb.pitch + x * (fb.bpp / 8));
    *pixel = color;
}

void draw_rect(int x, int y, int w, int h, uint32_t color) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            put_pixel(x + j, y + i, color);
        }
    }
}

void kernel_main() {
    // фон (рабочий стол)
    draw_rect(0, 0, fb.width, fb.height, 0x008800);

    // панель "Пуск"
    draw_rect(0, fb.height - 50, fb.width, 50, 0x222222);

    // кнопка "Пуск"
    draw_rect(10, fb.height - 40, 100, 30, 0x555555);

    // окно
    draw_rect(200, 150, 400, 300, 0xCCCCCC);

    while (1) {
        __asm__ volatile("hlt");
    }
}

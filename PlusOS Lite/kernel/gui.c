void draw_pixel(int x, int y, char color) {
    char *video = (char*)0xA0000;
    video[y * 320 + x] = color;
}

void draw_box(int x, int y, int w, int h, char color) {
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            draw_pixel(x + i, y + j, color);
        }
    }
}

#include "framebuffer.h"        

unsigned int cursor_cols = 0;
unsigned int cursor_rows = 0;

int write(char *buf, unsigned int len) {
    for (unsigned int i = 0; i < len; i++) {
        if (cursor_cols == 80) {
            cursor_cols = 0;
            cursor_rows++;
            if (cursor_rows == 25) {
                cursor_rows = 24;
                fb_scroll();
            }
        }
        unsigned int cursor_pos = cursor_cols + (cursor_rows * 80);
        fb_write_cell(cursor_pos, buf[i], FB_BLACK, FB_DARK_GREY);
        cursor_cols += 1;
    }
    
    fb_move_cursor(cursor_cols + (cursor_rows * 80));
    return len;
}

void clear_screen() {
    for (int i = 0; i < 2000; i++) {
        fb_write_cell(i, ' ', FB_BLACK, FB_DARK_GREY);
    }
}
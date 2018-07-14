#include "framebuffer.h"        
#include "serial.h"

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

void write_serial(char *buf, unsigned int len, unsigned short com_port) {
    for (unsigned int i = 0; i < len; i++){
        send_byte(buf[i], com_port);
    }
}

void log(char *message, unsigned int len, char level) {
    unsigned short port = SERIAL_COM1_BASE;
    init_serial_port(port);
    char *level_text = "[Info]:";
    unsigned int level_length = 7;
    if (level == 'E') {
        level_text = "[Error]:";
        level_length = 8;
    } else if(level == 'W') {
        level_text = "[Warn]:";
    }
    char newline = 0x0A;
    write_serial(level_text, level_length, SERIAL_COM1_BASE);
    write_serial(message, len, SERIAL_COM1_BASE);
    write_serial(&newline, 1, SERIAL_COM1_BASE);
}
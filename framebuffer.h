#ifndef INCLUDE_FRAMEBUFFER_H
#define INCLUDE_FRAMEBUFFER_H

void fb_move_cursor(unsigned short pos);

void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg);

void fb_scroll();

    #define FB_GREEN     2
    #define FB_DARK_GREY 8
    #define FB_BLACK     0

#endif
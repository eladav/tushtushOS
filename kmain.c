        #include "io.h"

    /* The I/O ports */
    #define FB_COMMAND_PORT         0x3D4
    #define FB_DATA_PORT            0x3D5

    /* The I/O port commands */
    #define FB_HIGH_BYTE_COMMAND    14
    #define FB_LOW_BYTE_COMMAND     15

    /** fb_move_cursor:
     *  Moves the cursor of the framebuffer to the given position
     *
     *  @param pos The new position of the cursor
     */
    void fb_move_cursor(unsigned short pos)
    {
        outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
        outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
        outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
        outb(FB_DATA_PORT,    pos & 0x00FF);
    }
    
    /** fb_write_cell:
     *  Writes a character with the given foreground and background to position i
     *  in the framebuffer.
     *
     *  @param i  The location in the framebuffer
     *  @param c  The character
     *  @param fg The foreground color
     *  @param bg The background color
     */
    void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg)
    {
        char *fb = (char *) 0x000B8000;
        fb[i] = c;
        fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
    }

    #define FB_GREEN     2
    #define FB_DARK_GREY 8
    #define FB_BLACK     0
    
int kmain() {
    for (int i = 0; i < 4000; i = i + 2) {
        fb_write_cell(i, ' ', FB_BLACK, FB_DARK_GREY);
    }
    fb_write_cell(0, 't', FB_GREEN, FB_DARK_GREY);
    fb_write_cell(2, 'u', FB_GREEN, FB_DARK_GREY);
    fb_write_cell(4, 's', FB_GREEN, FB_DARK_GREY);
    fb_write_cell(6, 'h', FB_GREEN, FB_DARK_GREY);
    fb_write_cell(8, 't', FB_GREEN, FB_DARK_GREY);
    fb_write_cell(10, 'u', FB_GREEN, FB_DARK_GREY);
    fb_write_cell(12, 's', FB_GREEN, FB_DARK_GREY);
    fb_write_cell(14, 'h', FB_GREEN, FB_DARK_GREY);
    fb_write_cell(16, 'O', FB_GREEN, FB_DARK_GREY);
    fb_write_cell(18, 'S', FB_GREEN, FB_DARK_GREY);

    fb_move_cursor(10);
    return 0;
}
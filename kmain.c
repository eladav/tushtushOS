#include "system.h"
#include "io.h"
#include "serial.h"

struct GDTDefinition {
    unsigned int limit;
    unsigned int base;
    unsigned short type;
} __attribute__((packed));


struct gdt_entry_struct {
   unsigned short limit_low;
   unsigned short base_low;
   unsigned char base_middle;
   unsigned char access;
   unsigned char granularity;
   unsigned char base_high;
} __attribute__((packed));
typedef struct gdt_entry_struct gdt_entry_t;

struct GTDEntries {
    gdt_entry_t null;
    gdt_entry_t code;
    gdt_entry_t data;
}__attribute__((packed));
typedef struct GTDEntries GTDEntries_t;
GTDEntries_t table;

void print_logo() {
    char *line1 = "  _             _     _             _      ___  ____                            ";
    char *line2 = " | |_ _   _ ___| |__ | |_ _   _ ___| |__  / _ \\/ ___|                           ";
    char *line3 = " | __| | | / __| '_ \\| __| | | / __ | '_ \\| | | \\___ \\                           ";
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

void encodeGdtEntry(unsigned short *target, struct GDTDefinition source)
{
    // Check the limit to make sure that it can be encoded
    if ((source.limit > 65536) && ((source.limit & 0xFFF) != 0xFFF)) {
        log("You can't do that!", 18, 'E');
    }
    if (source.limit > 65536) {
        // Adjust granularity if required
        source.limit = source.limit >> 12;
        target[6] = 0xC0;
    } else {
        target[6] = 0x40;
    }
 
    // Encode the limit
    target[0] = source.limit & 0xFF;
    target[1] = (source.limit >> 8) & 0xFF;
    target[6] |= (source.limit >> 16) & 0xF;
 
    // Encode the base 
    target[2] = source.base & 0xFF;
    target[3] = (source.base >> 8) & 0xFF;
    target[4] = (source.base >> 16) & 0xFF;
    target[7] = (source.base >> 24) & 0xFF;
 
    // And... Type
    target[5] = source.type;
    char * chars = (char *)target;
    log(chars, 8, 'I');
}

void load_gdt() {
    table.null.limit_low = 0;
    table.null.base_low = 0;
    table.null.base_middle = 0;
    table.null.access = 0;
    table.null.granularity = 0;
    table.null.base_high = 0;

    table.code.limit_low = 0xFFFF;
    table.code.base_low = 0;
    table.code.base_middle = 0;
    table.code.access = 0x9A;
    table.code.granularity = 0xCF;
    table.code.base_high = 0;

    table.data.limit_low = 0xFFFF;
    table.data.base_low = 0;
    table.data.base_middle = 0;
    table.data.access = 0x92;
    table.data.granularity = 0xCF;
    table.data.base_high = 0;
    
    
    setGdt((unsigned long *)&table, sizeof(table));
    reloadSegments();
    log("GDT set up!", 11, 'I');
}

int kmain() {
    log("init", 4, 'I');
    log("setting up GDT", 14, 'I');
    clear_screen();
    load_gdt();
    print_logo();
    return 0;
}
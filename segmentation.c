#include "gdt_setup.h"
#include "system.h"

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
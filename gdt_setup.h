    #ifndef INCLUDE_GDT_H
    #define INCLUDE_GDT_H

    void setGdt(unsigned long* gdt, unsigned short gdt_size);

    void reloadSegments();

    #endif /* INCLUDE_GDT_H */
#ifndef INCLUDE_SYSTEM_H
#define INCLUDE_SYSTEM_H

    int write(char *buf, unsigned int len);
    void clear_screen();
    void write_serial(char *buf, unsigned int len, unsigned short com_port);
    void log(char *message, unsigned int len, char level);

#endif
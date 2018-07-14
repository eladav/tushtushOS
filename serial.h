#ifndef INCLUDE_COM_H
#define INCLUDE_COM_H

#define SERIAL_COM1_BASE                0x3F8      /* COM1 base port */
#define SERIAL_COM2_BASE                0x2F8      /* COM2 base port */
#define SERIAL_COM3_BASE                0x3E8      /* COM3 base port */
#define SERIAL_COM4_BASE                0x2E8      /* COM4 base port */

void init_serial_port(unsigned short com);

void send_byte(char c, unsigned short com);

#endif
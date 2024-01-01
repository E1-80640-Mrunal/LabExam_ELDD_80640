#ifndef __IMPORT_H
#define __IMPORT_H

#include<linux/kfifo.h>

#define MAX 32
extern int size;

extern struct kfifo my_fifo;

extern int my_kfifo_size;
extern int my_kfifo_len;
extern int my_kfifo_avail;

//functions
void kfifo_push(char *ch, int s);

char * kfifo_pop(int s);


#endif
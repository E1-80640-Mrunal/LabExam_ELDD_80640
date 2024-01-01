#include<linux/module.h>
#include"import.h"

//variables
struct kfifo my_fifo;
int my_kfifo_size;
int my_kfifo_len;
int my_kfifo_avail;
char op[30];


int size = MAX;
module_param(size,int, 0444);

static __init int export_init(void)
{
    int ret;
    printk(KERN_INFO "%s: export_init() called.\n", THIS_MODULE -> name);
    ret = kfifo_alloc(&my_fifo, MAX, GFP_KERNEL);
	if(ret < 0)
	{
		printk(KERN_ERR "%s: kfifo_alloc() is failed\n", THIS_MODULE->name);
		return -1;
	}
    my_kfifo_size = kfifo_size(&my_fifo);
    my_kfifo_len = kfifo_len(&my_fifo);
    my_kfifo_avail = kfifo_avail(&my_fifo);
    printk(KERN_INFO "%s: kfifo_alloc() allocated fifo.\n", THIS_MODULE->name);

    return 0;
}

static __exit void export_exit(void)
{
    printk(KERN_INFO "%s: export_exit() called.\n", THIS_MODULE -> name);

    printk(KERN_INFO "%s: Exported symbol kfifo_size = %d.\n", THIS_MODULE -> name, my_kfifo_size);
    printk(KERN_INFO "%s: Exported symbol kfifo_len = %d\n", THIS_MODULE -> name, my_kfifo_len);
    printk(KERN_INFO "%s: Exported symbol kfifo_avail = %d\n", THIS_MODULE->name, my_kfifo_avail);

    kfifo_free(&my_fifo);
    printk(KERN_INFO "%s: kfifo_free() released fifo.\n", THIS_MODULE->name);

}

void kfifo_push(char *ch, int s)
{
    int ret;
    ret = kfifo_in(&my_fifo, ch, s);
    printk(KERN_INFO "%s: bytes written into kfifo : %d\n", THIS_MODULE->name, ret);
    my_kfifo_size = kfifo_size(&my_fifo);
    my_kfifo_len = kfifo_len(&my_fifo);
    my_kfifo_avail = kfifo_avail(&my_fifo);
}

char * kfifo_pop(int s)
{
    my_kfifo_size = kfifo_size(&my_fifo);
    my_kfifo_len = kfifo_len(&my_fifo);
    my_kfifo_avail = kfifo_avail(&my_fifo);
    int ret;
    ret = kfifo_out(&my_fifo, op, s);
    printk(KERN_INFO "%s: bytes read from kfifo : %d\n", THIS_MODULE->name, ret);
    return op;
}

//module init exit wrappers
module_init(export_init);
module_exit(export_exit);

//export symbols
EXPORT_SYMBOL(my_kfifo_size);
EXPORT_SYMBOL(my_kfifo_len);
EXPORT_SYMBOL(my_kfifo_avail);
EXPORT_SYMBOL(kfifo_push);
EXPORT_SYMBOL(kfifo_pop);

//module information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mrunal Patwardhan");
MODULE_DESCRIPTION("LabExam_ELDD export module");
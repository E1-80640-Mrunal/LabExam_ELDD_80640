#include<linux/module.h>
#include"import.h"

struct kfifo my_fifo;
int kfifo_size;
int kfifo_len;
int kfifo_avail;

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
    printk(KERN_INFO "%s: kfifo_alloc() allocated fifo.\n", THIS_MODULE->name);
    return 0;
}

static __exit void export_exit(void)
{
    printk(KERN_INFO "%s: export_exit() called.\n", THIS_MODULE -> name);

    kfifo_free(&my_fifo);
    printk(KERN_INFO "%s: kfifo_free() released fifo.\n", THIS_MODULE->name);

}

//module init exit wrappers
module_init(export_init);
module_exit(export_exit);

//export symbols
EXPORT_SYMBOL(kfifo_size);
EXPORT_SYMBOL(kfifo_len);
EXPORT_SYMBOL(kfifo_avail);

//module information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mrunal Patwardhan");
MODULE_DESCRIPTION("LabExam_ELDD export module");
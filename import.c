#include<linux/module.h>
#include"import.h"

char op[30];

static __init int import_init(void)
{
    char *name = "Mrunal";
    printk(KERN_INFO "%s: import_init() called.\n", THIS_MODULE -> name);
    printk(KERN_INFO "%s: Exported symbol kfifo_size = %d.\n", THIS_MODULE -> name, my_kfifo_size);
    printk(KERN_INFO "%s: Exported symbol kfifo_len = %d\n", THIS_MODULE -> name, my_kfifo_len);
    printk(KERN_INFO "%s: Exported symbol kfifo_avail = %d\n", THIS_MODULE->name, my_kfifo_avail);

    kfifo_push(name, sizeof(name));
    printk(KERN_INFO "%s: kfifo_push() called.\n", THIS_MODULE -> name);
    printk(KERN_INFO "%s: Exported symbol kfifo_size = %d.\n", THIS_MODULE -> name, my_kfifo_size);
    printk(KERN_INFO "%s: Exported symbol kfifo_len = %d\n", THIS_MODULE -> name, my_kfifo_len);
    printk(KERN_INFO "%s: Exported symbol kfifo_avail = %d\n", THIS_MODULE->name, my_kfifo_avail);
    return 0;
}

static __exit void import_exit(void)
{
    printk(KERN_INFO "%s: Exported symbol kfifo_size = %d.\n", THIS_MODULE -> name, my_kfifo_size);
    printk(KERN_INFO "%s: Exported symbol kfifo_len = %d\n", THIS_MODULE -> name, my_kfifo_len);
    printk(KERN_INFO "%s: Exported symbol kfifo_avail = %d\n", THIS_MODULE->name, my_kfifo_avail);
    
    kfifo_pop(3);
    printk(KERN_INFO "%s: kfifo_pop() called.\n", THIS_MODULE -> name);

    printk(KERN_INFO "%s: Exported symbol kfifo_size = %d.\n", THIS_MODULE -> name, my_kfifo_size);
    printk(KERN_INFO "%s: Exported symbol kfifo_len = %d\n", THIS_MODULE -> name, my_kfifo_len);
    printk(KERN_INFO "%s: Exported symbol kfifo_avail = %d\n", THIS_MODULE->name, my_kfifo_avail);
    printk(KERN_INFO "%s: export_exit() called.\n", THIS_MODULE -> name);
}

//module init exit wrappers
module_init(import_init);
module_exit(import_exit);

//module information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mrunal Patwardhan");
MODULE_DESCRIPTION("LabExam_ELDD import module");
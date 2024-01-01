#include<linux/module.h>
#include"import.h"


static __init int import_init(void)
{
    printk(KERN_INFO "%s: import_init() called.\n", THIS_MODULE -> name);
    return 0;
}

static __exit void import_exit(void)
{
    printk(KERN_INFO "%s: export_exit() called.\n", THIS_MODULE -> name);
}

//module init exit wrappers
module_init(import_init);
module_exit(import_exit);

//module information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mrunal Patwardhan");
MODULE_DESCRIPTION("LabExam_ELDD import module");
#include<linux/kernel.h>


static __init int export_init(void)
{
    printk(KERN_INFO "%s: export_init() called.\n", THIS_MODULE -> name);
    return 0;
}

static __exit void export_exit(void)
{
    printk(KERN_INFO "%s: export_exit() called.\n", THIS_MODULE -> name);
}

//module init exit wrappers
module_init(export_init);
module_exit(export_exit);

//module information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mrunal Patwardhan");
MOODULE_DESCRIPTION("LabExam_ELDD export module");
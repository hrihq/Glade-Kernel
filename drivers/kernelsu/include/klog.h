#ifndef __KSU_H_KLOG
#define __KSU_H_KLOG

#include <linux/printk.h>
// task_work_add() gained an enum task_work_notify_mode third argument in
// v5.11 (TWA_NONE/TWA_RESUME/TWA_SIGNAL); older kernels take a plain bool
// where true means "notify the target task". Map the enum to the legacy
// argument so every call site can use TWA_RESUME unchanged.
#include <linux/version.h>
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 11, 0)
#define TWA_RESUME true
#endif


#ifdef pr_fmt
#undef pr_fmt
#define pr_fmt(fmt) "KernelSU: " fmt
#endif

#ifdef CONFIG_KSU_DEBUG
#define ksu_dbg(fmt, ...) pr_info(fmt, ##__VA_ARGS__)
#else
#define ksu_dbg(fmt, ...) no_printk(KERN_INFO pr_fmt(fmt), ##__VA_ARGS__)
#endif

#endif

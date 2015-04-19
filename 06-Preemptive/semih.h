/* Define semihosting operation number */

#define SYS_OPEN 0x01
#define SYS_CLOSE 0x02
#define SYS_WRITE 0x05

int semihost_syscall(int number, ...) __attribute__((naked));

int open(const char *pathname, int flags);
int close(int fildes);
int write(int fildes, const void *buf, int nbyte);



#include <string.h>
#include <stdarg.h>
#include "semih.h"

int semihost_syscall(int num, ...)
{
	asm(
	    "BKPT 	0xAB\n"
	    "BX 	lr\n"
	);
}

int open(const char *pathname, int flags)
{
	int argv[] = { (int) pathname, flags, strlen(pathname) };
	return semihost_syscall(SYS_OPEN, argv);
}

int close(int fildes)
{
	return semihost_syscall(SYS_CLOSE, &fildes);
}

int write(int fildes, const void *buf, int nbyte)
{
	int argv[] = { fildes, (int) buf, nbyte };
	return nbyte - semihost_syscall(SYS_WRITE, argv);
}


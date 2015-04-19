#include <string.h>
#include "semih.h"

int open(const char *pathname, int flags)
{
	int argv[] = { (int) pathname, flags, strlen(pathname) };
	return syscall(SYS_OPEN, argv);
}

int close(int fildes)
{
	return syscall(SYS_CLOSE, &fildes);
}

int write(int fildes, const void *buf, int nbyte)
{
	int argv[] = { fildes, (int) buf, nbyte };
	return nbyte - syscall(SYS_WRITE, argv);
}


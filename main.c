#include <err.h>

#include "file.h"

extern int
main(void)
{
	char buf;
	int ret;

	if (init() < 0)
		errx(1, "Init error");

	while ((ret = read1(&buf)) > 0)
		if (write1(buf) < 0)
			errx(1, "Write error");

	if (ret < 0)
		errx(1, "Read error");

	if (flush() < 0)
		errx(1, "Flush error");

	return 0;
}

#include <assert.h>
#include <stdio.h>

#include "file.h"

extern int
init(void)
{
	if (setvbuf(stdin, NULL, _IOFBF, SIZE))
		return -1;
	if (setvbuf(stdout, NULL, _IOFBF, SIZE))
		return -1;
	return 0;
}

extern int
read1(char *c)
{
	size_t ret;

	ret = fread(c, 1, 1, stdin);
	if (ret == 1)
		return 1;
	assert(ret == 0);

	if (ferror(stdin))
		return -1;

	assert(feof(stdin));
	return 0;
}

extern int
write1(char c)
{
	size_t ret;

	ret = fwrite(&c, 1, 1, stdout);
	if (ret == 1)
		return 1;
	assert(ret == 0);

	assert(ferror(stdout));
	assert(!feof(stdout));
	return -1;
}

extern int
flush(void)
{
	if (fflush(stdout))
		return -1;

	return 0;
}

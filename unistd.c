#include <assert.h>
#include <unistd.h>

#include "file.h"

extern int
init(void)
{
	return 0;
}

extern int
read1(char *c)
{
	static char buf[SIZE];
	static size_t pos, len;
	ssize_t ret;

	if (pos < len) {
		*c = buf[pos++];
		return 1;
	}
	assert(pos == len);

	ret = read(0, buf, SIZE);
	if (ret > 0) {
		len = (size_t)ret;
		pos = 0;
		return read1(c);
	}
	if (ret < 0)
		return -1;
	return 0;
}

static char buf[SIZE];
static size_t pos;

extern int
write1(char c)
{
	if (pos < SIZE) {
		buf[pos++] = c;
		return 1;
	}
	assert(pos == SIZE);

	if (flush() == 0 && write1(c) > 0)
		return 1;

	return -1;
}

extern int
flush(void)
{
	if (pos == 0)
		return 0;

	assert(pos <= SIZE);
	if (write(1, buf, pos) != (ssize_t)pos)
		return -1;

	pos = 0;
	return 0;
}

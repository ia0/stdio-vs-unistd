#ifndef FILE_H
#define FILE_H

#define SIZE 8192

extern int /* -1 on error, 0 on success */
init(void);

extern int /* -1 on error, 0 on end-of-file, 1 on success */
read1(
	char *c /* [borrow][out] */
);

extern int /* -1 on error, 1 on success */
write1(char c);

extern int /* -1 on error, 0 on success */
flush(void);

#endif /* file.h */

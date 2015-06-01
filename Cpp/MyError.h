#ifndef __MY__ERROR_H_
#define __MY__ERROR_H_

#include <errno.h>		/* for definition of errno */
#include <stdarg.h>		/* ISO C variable aruments */

#define	MAXLINE	4096			/* max line length */

void	err_dump(const char *, ...);		/* {App misc_source} */
void	err_msg(const char *, ...);
void	err_quit(const char *, ...);
void	err_exit(int, const char *, ...);
void	err_ret(const char *, ...);
void	err_sys(const char *, ...);

void	log_msg(const char *, ...);			/* {App misc_source} */
void	log_open(const char *, int, int);
void	log_quit(const char *, ...);
void	log_ret(const char *, ...);
void	log_sys(const char *, ...);

#endif
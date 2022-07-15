#include <stdio.h>		//print_center() - printf_center()
#include <string.h>		//print_center() - printf_center()
#include <sys/ioctl.h>	//print_center() - printf_center()
#include <unistd.h>		//print_center() - printf_center()
#include <stdarg.h>		//printf_center()




/*
#include <stdio.h>		printf()
#include <string.h>		strlen()
#include <sys/ioctl.h>	struct winsize; ioctl(); TIOCGWINSZ
#include <unistd.h>		STDOUT_FILENO
__TO_DO__ enable support for multiple lines
*/
void print_center(char str[]) {
	//= move cursor to center
		struct winsize window_size;
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &window_size); // Assigns the size of the terminal to window_size

		for (int i = 0; i < window_size.ws_col / 2 - (strlen(str) / 2); i++)
			printf(" ");
	//! move cursor to center

	printf("%s", str);
}

/*
#include <stdio.h>		printf()
#include <string.h>		strlen()
#include <sys/ioctl.h>	struct winsize - ioctl() - TIOCGWINSZ
#include <unistd.h>		STDOUT_FILENO
#include <stdarg.h>		va_start() - va_end()
__TO_DO__ find a way to count args to avoid segfault when more args then implied by format
__TO_DO__ enable support for multiple lines
__!WARNING!__ Causes segfault when called with more arguments then implied by format
*/
void printf_center(char const* format, ...)
{
	//= format string
		va_list args;
		char str[1000];

		va_start(args, format);
		vsnprintf(str, sizeof(str), format, args); //stores output string to str
		va_end(args);
	//! format string

	//= move cursor to center
		struct winsize window_size;
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &window_size); // Assigns the size of the terminal to window_size

		for (int i = 0; i < window_size.ws_col / 2 - (strlen(str) / 2); i++)
			printf(" ");
	//! move cursor at to center

	printf("%s", str);
}


int main(void) {
	//char str[1000];
	//snprintf(str, sizeof(str), "test %i\n", 4);
	print_center("centered text\n");
	printf_center("str %i %f %c %s\n", 2000000000, 7.8, 'c', "yo");
}

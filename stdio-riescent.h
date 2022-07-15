#include <stdio.h>	   //print_center() - printf_center()
#include <string.h>	   //print_center() - printf_center()
#include <sys/ioctl.h> //print_center() - printf_center()
#include <unistd.h>	   //print_center() - printf_center()
#include <stdarg.h>	   //printf_center()

/*
#include <stdio.h>		printf()
#include <string.h>		strlen()
#include <sys/ioctl.h>	struct winsize; ioctl(); TIOCGWINSZ
#include <unistd.h>		STDOUT_FILENO
__TO_DO__ enable support for multiple lines
*/
// Prints a string in the middle of a terminal line
void print_center(const char *str)
{
	//= move cursor to center
	struct winsize window_size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window_size); // Assigns the size of the terminal to window_size

	for (int i = 0; i < window_size.ws_col / 2 - (strlen(str) / 2); i++)
		printf(" ");
	//!

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
// Prints a formated string in the middle of a terminal line
void printf_center(const char *format, ...)
{
	//= format string
	va_list args;
	char print_me[1000];

	va_start(args, format);
	vsnprintf(print_me, sizeof(print_me) / sizeof(print_me[0]), format, args); // stores output string to str
	va_end(args);
	//!

	//= move cursor to center
	struct winsize window_size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window_size); // Assigns the size of the terminal to window_size

	/* window_size.ws_col / 2 - strlen(print_me) / 2 needs to be stored in a variable
	   or the following loop bugs when string longer than the terminal can write in one line */
	int spaces_to_write = window_size.ws_col / 2 - strlen(print_me) / 2;
	for (int i = 0; i < spaces_to_write; i++)
		printf(" ");
	//!

	printf("%s", print_me);
}

//#include <stdio.h>
/* Prints argument and returns user input (scanf) after verifiyng it is an int
   (if it isn't an int the user will be asked to retry infinitely) */
int get_int(const char *print)
{
	printf("%s", print);

	int return_integer;
	if (!scanf("%i", &return_integer))
	{
		printf("An error occured, make sure you input an integer. ");

		//= This discards the input from scanf to avoid entering an infinite loop
		while (return_integer != '\n' && return_integer != EOF)
			return_integer = getchar();
		//!

		return_integer = get_int(print); // Restarts the fonction
	}
	return (return_integer);
}

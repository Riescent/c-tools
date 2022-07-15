#include <stdio.h>		//printf()
#include <string.h>		//strlen()
#include <sys/ioctl.h>	//struct winsize; ioctl(); TIOCGWINSZ
#include <unistd.h>		//STDOUT_FILENO

//TODO enable support for formating (%i, %s...)
//TODO enable support for multiple lines
void print_center(char text[]) {
	struct winsize window_size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window_size); // Assigns the size of the terminal to window_size

	for (int i = 0; i < window_size.ws_col / 2 - (strlen(text) / 2); i++)
		printf(" ");
	printf("%s", text);
}

int main(void) {
	print_center("test\ntest2\n");
}

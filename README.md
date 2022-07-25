# C-tools

## Headers to make c easy
How to use c-tools -> [click me](https://github.com/Riescent/c-tools#how-to-use-c-tools)  

## stdio-c-tools.h

  - #### void print_center(const char *str)  
            Prints a string in the middle of a terminal line  
  - #### void printf_center(const char *format, ...)
            Prints a formated string (accepts %i...) in the middle of a terminal line
  - #### int get_int(const char *print)
            Prints argument and returns user input (scanf) after verifiyng it is an int (if it isn't an int the user will be asked to retry infinitely)
  - #### int get_int_center(const char *print)
            Prints argument at line center and returns user input (scanf) after verifiyng it is an int (if it isn't an int the user will be asked to retry infinitely)
  - #### void new_line(void)
            Prints a new line
            

## time-c-tools.h

  - #### unsigned long long time_ms(void)
            Returns number that grows by one every ms
            

## random-c-tools.h

  - #### int random_range(const int min, const int max)
            Returns random value >= min and <= max. Add "srand(time_ms());" to main() for better results
            

## arr-c-tools.h

  - #### #define arrsize(arr) sizeof(arr) / sizeof(arr[0])
            Used to get the size of an array
  - #### void randomize_arr_int(int *arr, const int arr_size, const int min, const int max)
            Randomize all members of an int array in a set range (min and max are included)
  - #### void sort_arr_int(int *ptr_arr, const int arr_size)
            Sorts an int array from lower to bigger
  - #### int bi_search_arr_int(const int target, const int *arr, const int arr_size)
            Does a binary search for 'target' in an int array
  
## How to use c-tools
  - #### Add to one project
      - [Download](https://github.com/Riescent/c-tools/archive/refs/heads/main.zip)  
      - Open the downloaded file.  
      - Copy the "c-tools_headers" folder and "c-tools.h" to your project's folder.  
      - At the top of your project's .c file, add:  
            #include "c-tools.h"

  - #### Add to all projects (Using [VS Code](https://code.visualstudio.com/), the [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner) extension, and gcc compiler)
      - Create a folder anywhere on your computer. (We will refer to the path of this folder as ___/PATH/___)  
      - [Download](https://github.com/Riescent/c-tools/archive/refs/heads/main.zip)  
      - Open the downloaded file.  
      - Copy the "c-tools_headers" folder and "c-tools.h" to ___/PATH/___.  
      - In VS code: press F1, type "open settings", select ">Preferences: Open Settings (JSON)"  
      - At the end of the file, add:  
            "C_Cpp.default.includePath": ["___/PATH/___"]  
      - Search for "code-runner.executorMap"  
      - Under "code-runner.executorMap" search for "c"  
      - Replace the line where you found "c" with:  
            "c": "cd $dir && gcc -I ___/PATH/___ $fileName -o $fileNameWithExt && $dir$fileNameWithExt && rm $dir$fileNameWithExt",  
      - At the top of your project's .c file, add:  
            #include "c-tools.h"  
      - Run your code using [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)  

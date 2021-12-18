# ft_printf
This project is recoding printf() in stdio.h. By the project restrictions, we were only allowed to use the external C functions ```malloc```, ```free``` and ```write```, as well as the C library macros ```va_start```, ```va_arg```, ```va_copy``` and ```va_end```.

## Discription
ft_printf() will accept the following flags

| Specifier  | Output |
| ------------- | ------------- |
| c | character |
| s | string of characters |
| p | pointer address |
| d or i  | signed deciam integer  |
| u  | unsigned decimal integer  |
| o | unsigned octal |
| x | unsigned hexadecimal integer |
| X | unsigned hexadecimal integer (uppercase ) |

### Other features

*width and pricisions can also be defined.

*passing 0 as a flag will left-pad the number with zeroes

## Setup

#### Cloning the repository and compiling the project

```bash
git clone https://github.com/odkaz/ft_printf.git;cd ft_printf;make;make clean;
```

#### Compile with your main.c

```bash
gcc -Wall -Werror -Wextra main.c -L. -lftprintf
```

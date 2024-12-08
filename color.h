#pragma once
#ifndef COLOR_PRINT_H
#define COLOR_PRINT_H

typedef enum
{
	black,
	red,
	green,
	yellow,
	blue,
	magenta,
	cyan,
	white
} color;

#define RESET "\033[0m"
#define BG_BLACK "\033[40m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_WHITE "\033[47m"

void color_print(color selection);

#endif
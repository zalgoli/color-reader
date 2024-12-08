// Self-include
#include "color.h"

// Standard library headers
#include <stdio.h>


void color_print(color selection)
{
	switch (selection)
	{
	case black: printf("%s ", BG_BLACK); break;
	case red: printf("%s ", BG_RED); break;
	case green: printf("%s ", BG_GREEN); break;
	case yellow: printf("%s ", BG_YELLOW); break;
	case blue: printf("%s ", BG_BLUE); break;
	case magenta: printf("%s ", BG_MAGENTA); break;
	case cyan: printf("%s ", BG_CYAN); break;
	case white: printf("%s ", BG_WHITE); break;
	default: break;
	}
	printf("%s", RESET);
}


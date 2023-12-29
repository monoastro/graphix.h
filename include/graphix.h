#pragma once

//This is an attempt to write a wrapper mimicking borland's graphics.h on top of SFML
//I'm taking reference from the following sources; so let it serve as the documenation for the functions implemented:
//1. https://home.cs.colorado.edu/~main/bgi/doc/

//references in comments are refered to using the follwing format:
//ref.1 = https://home.cs.colorado.edu/~main/bgi/doc/


//All graphics drivers supported by borland's graphics.h 
enum graphics_drivers { DETECT, CGA, MCGA, EGA, EGA64, EGAMONO, IBM8514, HERCMONO, ATT400, VGA, PC3270 };

//All colors of borland's palette; I checked
#define MAXCOLORS 15
enum colors { BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE };

// Various modes for each graphics driver as listed in ref.1 this is gonna get repetitive 
enum graphics_modes 
{ 
	CGAC0, CGAC1, CGAC2, CGAC3, CGAHI, 
    MCGAC0 = 0, MCGAC1, MCGAC2, MCGAC3, MCGAMED, MCGAHI,
    EGALO = 0, EGAHI,
    EGA64LO = 0, EGA64HI,
    EGAMONOHI = 3, //there's two of these I wonder why
    HERCMONOHI = 0,
    ATT400C0 = 0, ATT400C1, ATT400C2, ATT400C3, ATT400MED, ATT400HI,
    VGALO = 0, VGAMED, VGAHI,
    PC3270HI = 0,
    IBM8514LO = 0, IBM8514HI //both of these have the same value in ref.1
};


//and finally,
//the function prototypes
void initgraph(int *graphdriver, int *graphmode, char const *pathtodriver);
void putpixel(int x, int y, int color);

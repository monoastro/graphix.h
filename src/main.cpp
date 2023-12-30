#include <stdio.h>
#include <math.h>
#include "graphix.h"

#include <thread> //for delay purposes
				  
void dda(int x1, int y1, int x2, int y2)
{
	int dx, dy, steps, i;
	float x, y, x_inc, y_inc;

	dx = x2 - x1;
	dy = y2 - y1;

	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);

	x_inc = dx / (float)steps;
	y_inc = dy / (float)steps;

	x = x1;
	y = y1;

	putpixel(x, y, GREEN);

	for (i = 0; i < steps; i++)
	{
		x += x_inc;
		y += y_inc;

		putpixel(round(x), round(y), GREEN);
	}
}

int main()
{
	
	int x1, y1, x2, y2;

	printf("Enter the coordinates of the first point: ");
	scanf("%d %d", &x1, &y1);
	printf("Enter the coordinates of the second point: ");
	scanf("%d %d", &x2, &y2);

	int graphdriver = DETECT, graphmode;
	initgraph(&graphdriver, &graphmode, "");

	dda(x1, y1, x2, y2);

	//sleep; substitute for getch()
	std::this_thread::sleep_for(std::chrono::milliseconds(10000));
	
	closegraph();
	
	return 0;	
}

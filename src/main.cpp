#include "graphix.h"

int main()
{
	int graphdriver = DETECT, graphmode;
	initgraph(&graphdriver, &graphmode, "");
	
	//yeah I'm pretty sure this needs to be multithreaded
	//go to sfml_gift.cpp -> run() to write the further code until then
	return 0;	
}

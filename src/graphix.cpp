#include "graphix.h"
#include "sfml_gift/sfml_gift.hpp"

//the sfml application on top of which this wrapper is built
//needs to be global because the graphics.h functions are not object oriented
sfml_gift::Application capybara; //it's called capybara because capybaras are cool

void initgraph(int *graphdriver, int *graphmode, char const *pathtodriver)
{
	//none of the function's arguments are used at this time
	//tbf all they do is change the size of the window at the end of the day
	//the path to driver is just completely useless but added for compatibility
	//this is gonna be common theme during writing this I can feel it
	
	//doing this so the compiler stops yelling that these are unused 
	graphdriver = graphdriver;
	graphmode = graphmode;
	pathtodriver = pathtodriver;

	//initializing the window
	//by default it takes size values from definitions.hpp but needs to be changed 
	//so that it takes values based on graphdriver and graphmode
	capybara.Init();
	capybara.Run();


}

void putpixel(int x, int y, int color)
{

	sf::VertexArray point(sf::Points, 1);
    point[0].position = sf::Vector2f(x, y);
	point[0].color = sfml_gift::convertToSFMLcolor(color);
    capybara.m_applicationData->m_window->draw(point);
}


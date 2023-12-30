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

	//the function that needs to be started on a separate thread
	//the infinite loop needs to be on the separate thread to keep
	//the window alive until closegraph is called or x is pressed
	
	if(!capybara.m_applicationData->m_threadRunning)
	{
		capybara.m_windowThread = std::thread(&sfml_gift::Application::Run, &capybara);
		capybara.m_applicationData->m_threadRunning = true;
	}
}

void closegraph(int wid)
{
	//to be implemented with wid
	wid = wid;

    if (capybara.m_applicationData->m_threadRunning && capybara.m_applicationData->m_window->isOpen())
	{
		capybara.m_applicationData->m_closeWindow = true;
		capybara.waitForThread();
	}
}

void putpixel(int x, int y, int color)
{
	sf::Vertex point(sf::Vector2f(x, y), sfml_gift::convertToSFMLcolor(color));
	capybara.m_applicationData->m_window->draw(&point, 1, sf::Points);
	capybara.m_applicationData->m_window->display();
}


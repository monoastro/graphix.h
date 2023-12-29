#include "sfml_gift.hpp"

#include "graphix.h" //temporarily here beacuse code isn't multithreaded yet

namespace sfml_gift
{
	Application::Application()
	:
		//this is all the initialization that's needed
		m_applicationData(std::make_shared<sfml_gift::applicationData>())
	{
	}

	Application::~Application()
	{
	}

	//the window isn't created until this function is called
	//which perfectly encapsulates the behavior of initgraph
	void Application::Init(unsigned width, unsigned height)
	{
		m_applicationData->m_window->create(sf::VideoMode(width, height), Title);
	}

	void Application::Run()
	{
		while(m_applicationData->m_window->isOpen())
		{
			
			//Input
			m_applicationData->m_inputs->pollEvent(*(this->m_applicationData->m_window));
			//Draw
			m_applicationData->m_window->clear(sf::Color::Black);

			//without multithreading this is where the reset of the code needs to be tested for now
			for(int i = 0; i < 1000; i++)
			{
				putpixel(i, i, GREEN);
			}

			//Display
			m_applicationData->m_window->display();
		}
	}


	//pain intensifies
	sf::Color convertToSFMLcolor(int color)
	{
		sf::Color sfmlColor;
		switch(color)
		{
			case BLACK:
				sfmlColor = sf::Color::Black;
				break;
			case BLUE:
				sfmlColor = sf::Color::Blue;
				break;
			case GREEN:
				sfmlColor = sf::Color::Green;
				break;
			case CYAN:
				sfmlColor = sf::Color::Cyan;
				break;
			case RED:
				sfmlColor = sf::Color::Red;
				break;
			case MAGENTA:
				sfmlColor = sf::Color::Magenta;
				break;
			case BROWN:
				sfmlColor = sf::Color(165, 42, 42);
				break;
			case LIGHTGRAY:
				sfmlColor = sf::Color(211, 211, 211);
				break;
			case DARKGRAY:
				sfmlColor = sf::Color(169, 169, 169);
				break;
			case LIGHTBLUE:
				sfmlColor = sf::Color(173, 216, 230);
				break;
			case LIGHTGREEN:
				sfmlColor = sf::Color(144, 238, 144);
				break;
			case LIGHTCYAN:
				sfmlColor = sf::Color(224, 255, 255);
				break;
			case LIGHTRED:
				sfmlColor = sf::Color(255, 182, 193);
				break;
			case LIGHTMAGENTA:
				sfmlColor = sf::Color(255, 192, 203);
				break;
			case YELLOW:
				sfmlColor = sf::Color::Yellow;
				break;
			case WHITE:
				sfmlColor = sf::Color::White;
				break;
			default:
				sfmlColor = sf::Color::Black;
				break;
		}
		return sfmlColor;
	}
}

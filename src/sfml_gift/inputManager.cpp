#include "inputManager.hpp"

namespace sfml_gift
{
	inputManager::inputManager()
	{
	}

	inputManager::~inputManager()
	{
	}

	//we can handle getch() stuff here
	void inputManager::pollEvent(sf::RenderWindow& window)
	{
		while(window.pollEvent(m_event))
		{
			if(m_event.type == sf::Event::Closed)
				window.close();
		}
	}
}

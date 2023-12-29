#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

namespace sfml_gift
{
	//a basic input manager nothing too fancy right now
	class inputManager
	{
		public:
			inputManager();
			~inputManager();

			void pollEvent(sf::RenderWindow& window);
		private:
			sf::Event m_event;
	};
}

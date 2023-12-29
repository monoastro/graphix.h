#pragma once
//the name of this file is sfml_gift because graphix.h is a wrapper on top of sfml
//also because it's christmas season

#include <memory> //the holy goddess of memory management

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "definitions.hpp"
#include "inputManager.hpp"

namespace sfml_gift
{
	//I feel like we're gonna have to detect keypresses and manage assets later on
	//making this struct now to avoid having to rewrite everything later
	struct applicationData
	{
		std::unique_ptr<sf::RenderWindow> m_window;
		std::unique_ptr<sfml_gift::inputManager> m_inputs;

		applicationData() : 
			m_window(std::make_unique<sf::RenderWindow>()),
			m_inputs(std::make_unique<sfml_gift::inputManager>())
		{
		}

		bool m_isFullScreen = false;
	};

	class Application 
	{
	public:
		Application();
		~Application();

		//doing this separates the window values from the objects
		//and fixes the problem of the window being created and fixed
		//before initgraph is called
		void Init(unsigned width = WIDTH, unsigned height = HEIGHT);

		void Run();
		
		//this would usually be private but it needs to be accessed by the graphix.h functions
		//so no privacy around these c neighborhoods
		std::shared_ptr<sfml_gift::applicationData> m_applicationData;
	private:
	};

	//extra functions; putting them here for now
	sf::Color convertToSFMLcolor(int color);
}

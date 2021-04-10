#include "Platform/Platform.hpp"

int main()
{
#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML boilerplate application!", sf::Style::Close | sf::Style::Resize);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::Resized:
					std::cout << "New window width: " << event.size.width
							  << "New window height: " << event.size.height << std::endl;
					break;

				default:
					break;
			}
		}
	}

	return 0;
}

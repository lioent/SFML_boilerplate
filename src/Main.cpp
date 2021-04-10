#include "Header/Player.hpp"
#include "Platform/Platform.hpp"

static const float VIEW_WIDTH = 512.0f;
static const float VIEW_HEIGHT = 512.0f;

int main()
{
#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML boilerplate application!", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT));

	sf::Texture playerTexture;
	playerTexture.loadFromFile("content/tux_from_linux.png");
	Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 300.0f);

	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::Resized: {
					float aspectRatio = float(window.getSize().x / float(window.getSize().y));
					view.setSize(VIEW_WIDTH * aspectRatio, VIEW_HEIGHT);

					std::cout
						<< "New window width: " << event.size.width
						<< "New window height: " << event.size.height << std::endl;
					break;
				}

				case sf::Event::TextEntered:
					if (event.text.unicode < 128)
						std::cout << static_cast<char>(event.text.unicode);
					break;

				default:
					break;
			}
		}

		player.update(deltaTime);
		view.setCenter(player.position());

		window.clear(sf::Color(150, 150, 150));
		player.draw(window);
		window.display();
		window.setView(view);
	}

	return 0;
}

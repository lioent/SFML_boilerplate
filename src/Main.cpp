#include "Platform/Platform.hpp"

int main()
{
#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML boilerplate application!", sf::Style::Close | sf::Style::Resize);

	sf::Texture playerTexture;
	playerTexture.loadFromFile("content/tux_from_linux.png");

	Animation animation(&playerTexture, sf::Vector2u(3, 9), 0.3f);

	sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f));
	player.setPosition(206.0f, 206.0f);
	player.setTexture(&playerTexture);

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

				case sf::Event::Resized:
					std::cout << "New window width: " << event.size.width
							  << "New window height: " << event.size.height << std::endl;
					break;

				case sf::Event::TextEntered:
					if (event.text.unicode < 128)
						std::cout << static_cast<char>(event.text.unicode);
					break;

				default:
					break;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
				player.move(0.0f, -0.5f);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
				player.move(-0.5f, 0.0f);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
				player.move(0.0f, 0.5f);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
				player.move(0.5f, 0.0f);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
				player.setPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
			}
		}

		animation.Update(0, deltaTime);
		player.setTextureRect(animation.uvRect());

		window.clear(sf::Color(150, 150, 150));
		window.draw(player);
		window.display();
	}

	return 0;
}

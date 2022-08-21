#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    // There are multiple styles in sf; you can pass multiple using a bitwise |
    // This will allow the user to close the window and a title bar
    sf::RenderWindow window(sf::VideoMode(512, 512), "Hello world!", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
    sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
    player.setFillColor(sf::Color::Red);

    // while the window is open
    while (window.isOpen()) {
        sf::Event evnt{};
        // allows the user to move the window
        while (window.pollEvent(evnt)) {
            switch (evnt.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    std::cout << evnt.size.width << "x" << evnt.size.height << std::endl;
                    break;
                case sf::Event::TextEntered:
                    if (evnt.text.unicode < 128) {
                        // printf("%c", evnt.text.unicode);
                        std::cout << (char)evnt.text.unicode;
                    }
                    break;
                default:
                    break;
            }
        }

        window.draw(player);
        window.display();
    }

    return 0;
}
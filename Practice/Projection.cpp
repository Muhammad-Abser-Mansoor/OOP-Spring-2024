#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Moving Map");
    
    //Player Ball
    sf::CircleShape player(15.f);
    player.setPosition(sf::Vector2f(20.f,20.f));
    player.setFillColor(sf::Color::Cyan);
    //Player Ball End
    //Borders
    sf::RectangleShape LeftBorder (sf::Vector2f(4.f,600.f));
    LeftBorder.setFillColor(sf::Color::Green);
    sf::RectangleShape BottomBorder (sf::Vector2f(800.f,4.f));
    BottomBorder.setFillColor(sf::Color::Blue);
    BottomBorder.setPosition(sf::Vector2f(0.f,596.f));
    sf::RectangleShape TopBorder (sf::Vector2f(800.f,4.f));
    TopBorder.setFillColor(sf::Color::Red);
    sf::RectangleShape RightBorder (sf::Vector2f(4.f,600.f));
    RightBorder.setFillColor(sf::Color::Yellow);
    RightBorder.setPosition(sf::Vector2f(796.f,0.f));
    //Borders End
    //Middle Chowrangi
    sf::CircleShape Chowrangi(60.f);
    Chowrangi.setFillColor(sf::Color::White);
    sf::Vector2u windowSize = window.getSize();
    float circleX = (windowSize.x - Chowrangi.getRadius() * 2) / 2;
    float circleY = (windowSize.y - Chowrangi.getRadius() * 2) / 2;
    Chowrangi.setPosition(circleX, circleY);
    //Middle Chowrangi End
    //Starting Area
    sf::RectangleShape l1(sf::Vector2f(270.f,10.f));
    l1.setPosition(sf::Vector2f(4.f,60.f));
    sf::RectangleShape sh1(sf::Vector2f(40.f,100.f));
    sh1.setPosition(sf::Vector2f(350.f,14.f));
    sh1.setFillColor(sf::Color::Black);
    sh1.setOutlineColor(sf::Color::White);
    sh1.setOutlineThickness(10.f);
    sf::RectangleShape l2(sf::Vector2f(10.f,120.f));
    l2.setPosition(sf::Vector2f(274.f,60.f));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
                window.close(); 
        }
        window.clear();
        window.draw(LeftBorder);
        window.draw(BottomBorder);
        window.draw(TopBorder);
        window.draw(RightBorder);
        window.draw(Chowrangi);
        window.draw(player);
        window.draw(l1);
        window.draw(l2);
        window.draw(sh1);
        window.display();
    }
    return 0;
}

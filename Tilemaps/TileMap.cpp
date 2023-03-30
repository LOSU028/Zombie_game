#include <SFML/Graphics.hpp>
#include<iostream>
#include <fstream>
#include <cctype>
#include<string>

int main()
{
    std::ifstream openfile("TilesMap.txt");

    sf::Texture tileTexture;
    sf::Sprite tiles;

    sf::Vector2i map[100][100];
    sf::Vector2i loadCounter = sf::Vector2i(0,0);

    int rows = 0;
    if(openfile.is_open())
    {
        std::string tileLocation;
        openfile >> tileLocation;
        tileTexture.loadFromFile(tileLocation);
        tiles.setTexture(tileTexture);
        while(!openfile.eof())
        {
            std::string str;
            openfile >> str;
            char x = str[0], y=str[2];
            if(!isdigit(x) || !isdigit(y))
                map[loadCounter.x][loadCounter.y] = sf::Vector2i(-1, -1);
            else
                map[loadCounter.x][loadCounter.y] = sf::Vector2i(x - '0', y - '0');


        if(openfile.peek() == '\n')
        {
            loadCounter.x=0;
            loadCounter.y++;
            std::cout << " " << rows++;
        }
        else
            loadCounter.x++;
        }
        loadCounter.y++;
    }
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mapas");

    while(window.isOpen())
    {
        sf::Event Event;
        while(window.pollEvent(Event))
        {
            switch(Event.type)
            {
                case sf::Event::Closed:
                window.close();
                break;
            }
        }

        window.clear(sf::Color(0, 240, 255));
        for(int i = 0; i < rows+10 /*loadCounter.x*/; i++)
        {
            for(int j = 0; j < loadCounter.y; j++)
            {
                if(map[i][j].x != -1 && map[i][j].y !=-1)
                {
                    tiles.setPosition(i * 32, j * 32);
                    tiles.setTextureRect(sf::IntRect(map[i][j].x * 32, map[i][j].y *32, 32, 32));
                    window.draw(tiles);
                }
            }
        }
        sf::sleep(sf::milliseconds(30));
        window.display();
    }
}

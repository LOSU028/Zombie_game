#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Despegable.h"
#include "Personaje.h"
#include "Zombie .h"
#include <cstdlib>
#include <ctime>

using namespace sf;
using namespace std;

RenderWindow ventana;

string vida1;
int vida = 10;
bool P1();
bool P2();
bool P3();
bool fondo();
Font t;
Zombie zombies[100];
Personaje personaje;
Text hp;
Clock reloj;
Clock relooj;





bool izquierda();


int main ()
{
         t.loadFromFile("DagestaN .ttf");
         vida1 = "HP:" + to_string(vida);
         hp.setString(vida1);

        hp.setFont(t);
        bool P1_d = false;
        bool P2_d = false;
        bool P3_d = false;


        //srand(time(0));

    ventana.create (VideoMode(800, 600), "Zomo");

    std::vector<Despegable*> slide;
    std::vector<Despegable*>zombiess;
    zombiess.push_back(&zombies[0]);
    zombiess.push_back(&zombies[1]);
    zombiess.push_back(&zombies[2]);
    zombiess.push_back(&zombies[3]);
    zombiess.push_back(&zombies[4]);
    zombiess.push_back(&zombies[5]);
    zombiess.push_back(&zombies[6]);
    zombiess.push_back(&zombies[7]);
    zombiess.push_back(&zombies[8]);
    zombiess.push_back(&zombies[9]);
    zombiess.push_back(&zombies[10]);
    zombiess.push_back(&zombies[11]);
    zombiess.push_back(&zombies[12]);
    zombiess.push_back(&zombies[13]);
    zombiess.push_back(&zombies[14]);
    zombiess.push_back(&zombies[15]);
    zombiess.push_back(&zombies[16]);
    zombiess.push_back(&zombies[17]);
    zombiess.push_back(&zombies[18]);
    zombiess.push_back(&zombies[19]);
    slide.push_back(&personaje);

    unsigned index = 0;
    while (ventana.isOpen()){

             Event evento;

            while (ventana.pollEvent(evento)){
                if (evento.type == Event::Closed){
                    ventana.close();
                    break;
                }
                else
                if ((evento.type == Event::KeyPressed) &&
                    (evento.key.code == Keyboard::Enter)){
                        if ((index+1) == slide.size()) {
                        ventana.close();
                        }
                else {
                    index++;
                }
                break;
                }
                else{
                    slide[index]->handleEvent(evento);
                }
            }

        ventana.clear(Color::Black);
         if (!P1_d){
            P1_d = P1();
        }
        else
        if (!P2_d){
            P2_d = P2();

        }
        else
        if (!P3_d){
            P3_d = P3();
        }
        else{
            fondo();
            ventana.draw(hp);
            slide[index]->draw(ventana);
            zombiess[index]->draw(ventana);
            zombiess[index+1]->draw(ventana);
            zombiess[index+2]->draw(ventana);
            zombiess[index+3]->draw(ventana);
            zombiess[index+4]->draw(ventana);
            zombiess[index+5]->draw(ventana);
            zombiess[index+6]->draw(ventana);
            zombiess[index+7]->draw(ventana);
            zombiess[index+8]->draw(ventana);
            zombiess[index+9]->draw(ventana);
            zombiess[index+10]->draw(ventana);
            zombiess[index+11]->draw(ventana);
            zombiess[index+12]->draw(ventana);
            zombiess[index+13]->draw(ventana);
            zombiess[index+14]->draw(ventana);
            zombiess[index+15]->draw(ventana);
            zombiess[index+16]->draw(ventana);
            zombiess[index+17]->draw(ventana);
            zombiess[index+18]->draw(ventana);
            zombiess[index+19]->draw(ventana);
        }



       if(personaje.animacion.getGlobalBounds().intersects(zombies[0].zom.getGlobalBounds())||
          personaje.animacion.getGlobalBounds().intersects(zombies[1].zom.getGlobalBounds())||
          personaje.animacion.getGlobalBounds().intersects(zombies[2].zom.getGlobalBounds())||
          personaje.animacion.getGlobalBounds().intersects(zombies[3].zom.getGlobalBounds())||
          personaje.animacion.getGlobalBounds().intersects(zombies[4].zom.getGlobalBounds())||
          personaje.animacion.getGlobalBounds().intersects(zombies[5].zom.getGlobalBounds())||
          personaje.animacion.getGlobalBounds().intersects(zombies[6].zom.getGlobalBounds())||
          personaje.animacion.getGlobalBounds().intersects(zombies[7].zom.getGlobalBounds())||
          personaje.animacion.getGlobalBounds().intersects(zombies[8].zom.getGlobalBounds())||
          personaje.animacion.getGlobalBounds().intersects(zombies[9].zom.getGlobalBounds())||
          personaje.animacion.getGlobalBounds().intersects(zombies[10].zom.getGlobalBounds())||
          personaje.animacion.getGlobalBounds().intersects(zombies[11].zom.getGlobalBounds())||
          personaje.animacion.getGlobalBounds().intersects(zombies[12].zom.getGlobalBounds())||
          personaje.animacion.getGlobalBounds().intersects(zombies[13].zom.getGlobalBounds())||
          personaje.animacion.getGlobalBounds().intersects(zombies[14].zom.getGlobalBounds())||
          personaje.animacion.getGlobalBounds().intersects(zombies[15].zom.getGlobalBounds())||
          personaje.animacion.getGlobalBounds().intersects(zombies[16].zom.getGlobalBounds())||
          personaje.animacion.getGlobalBounds().intersects(zombies[17].zom.getGlobalBounds())||
          personaje.animacion.getGlobalBounds().intersects(zombies[18].zom.getGlobalBounds())||
          personaje.animacion.getGlobalBounds().intersects(zombies[19].zom.getGlobalBounds())){
            if (reloj.getElapsedTime().asSeconds()>2){
            vida = vida-1;
            vida1 ="HP:" + to_string(vida);
             hp.setString(vida1);
             reloj.restart();
            }
        }
        if(vida == 0){
            ventana.clear(Color::Black);
            t.loadFromFile("DagestaN .ttf");
            Text red;
            Sprite lose;
            Texture l;
            l.loadFromFile("win.png");
            lose.setTexture(l);
            lose.setScale(5.5,5.5);
            lose.setPosition(200,200);
            red.setFont(t);
            red.setCharacterSize(170);
            red.setStyle(red.Bold);
            red.setFillColor(Color::Red);
            red.setPosition(100, 100);
            red.setString("You died");
            ventana.draw(red);
            ventana.draw(lose);
        }
        else if((relooj.getElapsedTime().asSeconds() > 120 )&& (vida > 0)){
            ventana.clear(Color::Black);
            t.loadFromFile("DagestaN .ttf");
            Text ye;
            ye.setFont(t);
            ye.setCharacterSize(170);
            ye.setStyle(ye.Bold);
            ye.setFillColor(Color::Yellow);
            ye.setPosition(100, 100);
            ye.setString("You win uwu");
            ventana.draw(ye);
        }
         if (vida == 0){
            ventana.display();
            sleep(seconds(5));
            break;
         }
         if ((relooj.getElapsedTime().asSeconds() > 120) &&  (vida>0)){
            ventana.display();
            sleep(seconds(5));
            break;
         }
         else{
            ventana.display();
         }
    }

    return 0;
}

bool P1()
{
    t.loadFromFile("DagestaN .ttf");
    static int luz, azul= 1;

    luz = azul/2;
    Text blue;
    blue.setFont(t);
    blue.setCharacterSize(170);
    blue.setStyle(blue.Bold);
    blue.setFillColor(Color(luz, luz, azul));
    blue.setPosition(100, 100);
    blue.setString("UWU.Corp\n Presenta...");
    ventana.draw(blue);
    sleep(milliseconds(10));
   /** llega al azul claro, decir (112, 112, 255) y se detiene*/
    return (255 == azul++);
}
bool P2()
{

    static int destello = 0;
    static RectangleShape r1, r2, r3, r11, r22, r33;
    static Color oscuro(230, 200, 180);
    if (0 == destello){

        r1.setSize(Vector2f(500, 105));
        r1.setPosition(120, 130);
        r1.setFillColor(Color::Red);

        r2.setSize(Vector2f(500, 105));
        r2.setPosition(120, 252);
        r2.setFillColor(Color::Red);

        r3.setSize(Vector2f(500, 105));
        r3.setPosition(120, 375);
        r3.setFillColor(Color::Red);

        r11.setSize(Vector2f(480,85));
        r11.setPosition(130,140);
        r11.setFillColor(Color::Yellow);

        r22.setSize(Vector2f(480, 85));
        r22.setPosition(130, 262);
        r22.setFillColor(Color::Yellow);

        r33.setSize(Vector2f(480, 85));
        r33.setPosition(130, 385);
        r33.setFillColor(Color::Yellow);

    }
    ventana.draw(r1);
    ventana.draw(r2);
    ventana.draw(r3);
    ventana.draw(r11);
    ventana.draw(r22);
    ventana.draw(r33);

    Text b, b2, b3;
    b.setFont(t);
    b2.setFont(t);
    b3.setFont(t);
    b.setCharacterSize(100);
    b2.setCharacterSize(100);
    b3.setCharacterSize(100);
    if (0 == (destello%2)){ /** pares cuando destello vale algun numero par */
        b.setFillColor(oscuro);
        b2.setFillColor(oscuro);
        b3.setFillColor(oscuro);
    }
    else { /** nones cuando destello vale algun numero primo*/
        b.setFillColor(Color::White);
        b2.setFillColor(Color::White);
        b3.setFillColor(Color::White);
    }
    b.setPosition(225, 120);
    b.setString("Zombies");
    b2.setPosition(225,242);
    b2.setString("Asesinos");
    b3.setPosition(225,365);
    b3.setString("    2.0");
    ventana.draw(b);
    ventana.draw(b2);
    ventana.draw(b3);
    sleep(milliseconds(60));

    /** se produce destello hasta que sea mayor a 50*/
    return (destello++ >50);
}
bool P3()
{
    static bool first = true;
    static Image arch[3];
    static Texture skin[3];
    static Sprite regreso;
    static Sprite mano;
    static Sprite hoyo;

    if (first){
        arch[0].loadFromFile("regreso.bmp");
        arch[0].createMaskFromColor(Color::White);
        skin[0].loadFromImage(arch[0]);
        regreso.setTexture(skin[0]);
        regreso.setPosition(100, 70);
        regreso.scale(2,1.5);

        arch[1].loadFromFile("mano.png");
        arch[1].createMaskFromColor(Color::White);
        skin[1].loadFromImage(arch[1]);
        mano.setTexture(skin[1]);
        mano.setPosition(350, 480);
        mano.scale(2.4, 2.4);

        arch[2].loadFromFile("suelo.png");
        arch[2].createMaskFromColor(Color::White);
        skin[2].loadFromImage(arch[2]);
        hoyo.setTexture(skin[2]);
        hoyo.setPosition(215, 390);
        hoyo.scale(2.4, 2.4);

        first = false;
    }


    RectangleShape pasto;
    pasto.setSize(Vector2f(800, 200));
    pasto.move(0, 407);
    pasto.setFillColor(Color(55,84,38));
    ventana.draw(pasto);
    CircleShape espacio;
    espacio.setRadius(45);
    espacio.setPointCount(6);
    espacio.move(365, 430);
    espacio.rotate(-5);
    espacio.setFillColor(Color::Black);
    ventana.draw(espacio);

    mano.move(0, -1);
    ventana.draw(regreso);
    ventana.draw(mano);
    ventana.draw(hoyo);
    sleep(milliseconds(15));

    /** mano sube hasta llegar a y 300 */
   return (mano.getPosition().y == 300);

}
bool fondo()
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
            rows++;
        }
        else
            loadCounter.x++;
        }
        loadCounter.y++;
    }

        ventana.clear(sf::Color::Green);
        for(int i = 0; i < rows+10 /*loadCounter.x*/; i++)
        {
            for(int j = 0; j < loadCounter.y ; j++)
            {
                if(map[i][j].x != -1 && map[i][j].y !=-1)
                {
                    tiles.setPosition(i * 32, j * 32);
                    tiles.setTextureRect(sf::IntRect(map[i][j].x * 32, map[i][j].y *32, 32, 32));
                    ventana.draw(tiles);
                }
            }
        }
        sf::sleep(sf::milliseconds(30));
    }



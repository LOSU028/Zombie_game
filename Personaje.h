#ifndef BID_CEDI_PERSONAJE_H
#define BID_CEDI_PERSONAJE_H
#include "Despegable.h"




class Personaje : public Despegable
{
     public:
        Sprite animacion;
        Personaje() {
            load();
        }


         void handleEvent(const Event &ev) {
        if (ev.type == Event::KeyPressed){
            switch (ev.key.code){
                case Keyboard::A :caminariz = true; break;
                case Keyboard::D :caminarde = true;break;
                case Keyboard::W :caminarup = true;break;
                case Keyboard::S :caminardown = true;break;
                case Keyboard::H : ayuda = true;break;
                default: break;

            }
        }
        else if (ev.type == Event::KeyReleased){
            switch (ev.key.code){
            case Keyboard::A : caminariz = false;break;
            case Keyboard::D : caminarde = false;break;
            case Keyboard::W : caminarup = false;break;
            case Keyboard::S : caminardown = false;break;
            case Keyboard::H : ayuda = false;break;
            }
        }

    }

    void flip(){
        sprite[0].setTextureRect (IntRect (image[0].getSize().x, 0, -image[0].getSize().x,  image[0].getSize().y));
        sprite[1].setTextureRect (IntRect (image[1].getSize().x, 0, -image[1].getSize().x,  image[1].getSize().y));
        sprite[2].setTextureRect (IntRect (image[2].getSize().x, 0, -image[2].getSize().x,  image[2].getSize().y));
    }
    void unflip(){
        sprite[0].setTextureRect (IntRect (0, 0,  image[0].getSize().x,  image[0].getSize().y));
        sprite[1].setTextureRect (IntRect (0, 0,  image[1].getSize().x,  image[1].getSize().y));
        sprite[2].setTextureRect (IntRect (0, 0,  image[2].getSize().x,  image[2].getSize().y));
    }

    void load(){

             bool ya = true;
            if (ya){

                image[0].loadFromFile("newpiskel.png");
                image[0].createMaskFromColor(Color::Cyan);
                textu[0].loadFromImage(image[0]);
                sprite[0].setTexture(textu[0]);
                sprite[0].setScale(.3,.3);


                image[1].loadFromFile("Piskel.png");
                image[1].createMaskFromColor(Color::Cyan);
                textu[1].loadFromImage(image[1]);
                sprite[1].setTexture(textu[1]);
                sprite[1].setScale(.3,.3);


                image[2].loadFromFile("New.png");
                image[2].createMaskFromColor(Color::Cyan);
                textu[2].loadFromImage(image[2]);
                sprite[2].setTexture(textu[2]);
                sprite[2].setScale(.3,.3);

                image[3].loadFromFile("frente y back.png");
                image[3].createMaskFromColor(Color::Cyan);
                textu[3].loadFromImage(image[3]);
                sprite[3].setTexture(textu[3]);
                sprite[3].setTextureRect(IntRect(25,0, 24,50));
                sprite[3].setScale(1.5,1.5);


                image[4].loadFromFile("frente y back.png");
                image[4].createMaskFromColor(Color::Cyan);
                textu[4].loadFromImage(image[4]);
                sprite[4].setTexture(textu[4]);
                sprite[4].setTextureRect(IntRect(0,0, 25,50));
                sprite[4].setScale(1.5,1.5);
                ya = false;

                }

                animacion = sprite[0];
                animacion.setPosition(x,y);

    }
    void do_ayuda(){
        RenderWindow wind;
        Text help;
        Font h;
        wind.create(VideoMode(1000,600),"Ayuda");
        wind.clear(Color::Black);
        h.loadFromFile("DagestaN .ttf");
        help.setFont(h);
        help.setCharacterSize(30);
        help.setStyle(help.Bold);
        help.setFillColor(Color::Cyan);
        help.setString("Hola, Binevenido a Zombies 2.0 \n Este juego es bastante simple de jugar, \n cuentas con 10 puntos de vida durante todo el juego\n"
                       "Si tocas algun zombie perderas un punto de vida, si tu vida llega\n a 0 perderas el juego y tendras que iniciar de nuevo para ganar\n"
                       "Tu objetivo (para ganar el juego) es sobrevivir \n durante dos minutos, con tu puntaje de vida mayor a 0\n"
                       "Utiliza W A S D para moverte en la direcion que desees\n"
                       "Buena Suerte!\n\n"
                       "(Por favor espere a que esta pantalla se cierre por si misma)");
        wind.draw(help);
        wind.display();
        sleep(seconds(25));
        wind.close();

    }

     void do_caminariz (){
                if (reloj.getElapsedTime().asSeconds() > .15f){
                        x-=20;
                        sprite[0].setPosition(x,y);
                        sprite[1].setPosition(x,y);
                        sprite[2].setPosition(x,y);
                    switch (uno){
                        case 0: animacion=sprite[0], uno++;break;
                        case 1: animacion=sprite[1], uno++;break;
                        case 2: animacion=sprite[2], uno=0;break;
                    }

                    reloj.restart();
                    }
    }
    void do_caminarde(){
                if (reloj.getElapsedTime().asSeconds() > .15f){
                        x+=20;
                        sprite[0].setPosition(x,y);
                        sprite[1].setPosition(x,y);
                        sprite[2].setPosition(x,y);
                    switch (uno){
                        case 0: animacion=sprite[0], uno++;break;
                        case 1: animacion=sprite[1], uno++;break;
                        case 2: animacion=sprite[2], uno=0;break;
                    }

                    reloj.restart();
                    }
    }
    void do_caminarup(){
        if (reloj.getElapsedTime().asSeconds() > .15f){
            y-=20;
            sprite[3].setPosition(x,y);
            animacion=sprite[3];
            reloj.restart();
            }
    }
    void do_caminardown(){
        if (reloj.getElapsedTime().asSeconds() > .15f){
            y+=20;
            sprite[4].setPosition(x,y);
            animacion=sprite[4];
            reloj.restart();
            }
    }
    void draw (RenderWindow &w) {
        if  (caminariz){
            unflip();
            do_caminariz();
        }
        else
        if(caminarde){
            flip();
            do_caminarde();
        }
        else
        if(caminarup){
            do_caminarup();
        }
        else
        if(caminardown){
            do_caminardown();
        }
        else
        if(ayuda){
            do_ayuda();
        }
        w.draw(animacion);
    }
    private:

        bool caminariz = false;
        bool caminarde = false;
        bool caminarup = false;
        bool caminardown = false;
        bool ayuda = false;

        Image image[5];
        Texture textu[5];
        Sprite sprite[5];
        int x = 200, y = 200;
        int uno = 0;
        Clock reloj;


};

#endif // BID_CEDI_PERSONAJE_H

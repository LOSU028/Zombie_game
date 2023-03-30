#ifndef BID_CEDI_ZOMBIE _H
#define BID_CEDI_ZOMBIE _H


class Zombie: public Despegable
{
     public:
        Sprite zom;
        Zombie() {
        bool prim = true;
        if(prim){
        im.loadFromFile("zom.png");
        im.createMaskFromColor(Color::Cyan);
        tx.loadFromImage(im);
        zom.setTexture(tx);
        zom.setScale(0.3,0.3);
        zom.setPosition(rand()%750,rand()%550);
        zom.move(3,3);
        zom.setScale(.5,.5);
        crono.restart();
        prim = false;
        }
        }
        void deambular(){
        if (crono.getElapsedTime().asSeconds() < .5){
        switch (direccion){
        case 0: zom.move(0,0); break;
        case 1:
            if (zom.getPosition().x <10){
                direccion = 0; break;
            }
            zom.move(-rand()%10,0); break;
        case 2:
            if (zom.getPosition().x > 700){
                direccion = 0; break;
            }
            zom.move(rand()%10,0); break;
        case 3:
            if (zom.getPosition().y <10){
                direccion = 0; break;
            }
            zom.move(0,-rand()%10); break;
        case 4:
            if (zom.getPosition().y > 500){
                direccion = 0; break;
            }
            zom.move(0,rand()%10); break;
        default: break;
        }
        sleep(milliseconds(0.9));
    }
    else {
        direccion = rand()%5;
        crono.restart();
    }
    }
    void draw (RenderWindow &win) {
        deambular();
        win.draw(zom);
    }


    protected:
            Sprite zom2 = zom;
    private:
         int direccion;

         Image im;
         Texture tx;

         Clock crono;
};

#endif // BID_CEDI_ZOMBIE _H

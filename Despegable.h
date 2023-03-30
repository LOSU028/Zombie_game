#ifndef BID_CEDI_DESPEGABLE_H
#define BID_CEDI_DESPEGABLE_H
#  include <SFML/Graphics.hpp>
#  include <iostream>
using namespace sf;

class Despegable
{
    public:
        Despegable() {}
        virtual void handleEvent (const Event &ev) {  }
        virtual void draw (RenderWindow &win) {}
};

#endif // BID_CEDI_DESPEGABLE_H

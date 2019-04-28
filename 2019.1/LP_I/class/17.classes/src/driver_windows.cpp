#include <iostream>

#include "window.h"

int main() {
        Window w1("Janela 1", 10, 10, 40, 50, 2);
        Window w3("Janela 3");
        Window w4("Janela 4", 50);
        Window w5("Janela 5", 10, 10, 20, 20);
        Window w2;

        Window *pw1 = new Window("Jan 10", 1, 1, 5, 6, 10);
        int x = pw1->area();	
        int y = (*pw1).area();
        // usou ....
        delete pw1;
        pw1 = &w3;

        Window lista[] = {{"jan1", 1, 2, 3, 4, 5}, {"jan2", 5, 6, 7, 8, 10}};

        Window *v = new Window[200];

        w2.set_id("Janela 2");

        std::cout << ">>> Area = " << w1.area() << std::endl;
        // w1.set_id( "Janela 1" );
        // w1.set_level( 2 );

        return 0;
}

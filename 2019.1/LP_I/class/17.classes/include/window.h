#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <string>

class Window {
       private:
        int x1, y1;      //!< Coordenadas do canto inferior esquerdo.
        int x2, y2;      //!< Coordenadas do canto superior direito.
        std::string id;  //!< Identificador único da janela.
        int level;       //!< Camada ocupada pela janela.

       public:
        Window(std::string id = "untitled", int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0,
               int level = 0);

        ~Window();

        /// Calcula e retorna a area de janela.
        int area();

        void set_llc(int, int);
        void set_trc(int, int);

        void set_id(std::string name) { id = name; }
};

#endif

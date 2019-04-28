#include "window.h"

// Construtor
Window::Window(std::string id, int x1, int y1, int x2, int y2, int level)
    : x1{x1}, y1{y1}, x2{x2}, y2{y2}, id{id}, level{level} {
        std::cout << ">> Entrei no CONStrutor versao com parametros!\n";
        std::cout << "   Janela \"" << id << "\"\n";
}

// Desconstrutor
Window::~Window() { std::cout << "<<< Entrei no destutor! " << id << "\n"; }

int Window::area() { return (x2 - x1) * (y2 - y1); }

void Window::set_llc(int nx, int ny) {
        x1 = nx;
        y1 = ny;
}

void Window::set_trc(int nx, int ny) {
        x2 = nx;
        y2 = ny;
}


#include "../include/window.hpp"

#include <sys/ioctl.h>
#include <unistd.h>

namespace Editor
{
    Window *Window::_m_window_instance;
    Window::Window()
    {
        struct winsize ws;
        if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0)
            Window::terminate();
        _m_cols = ws.ws_col;
        _m_rows = ws.ws_row;
    }

    Window::~Window(){}

    Window* Window::getWindowInstance()
    {
        if (_m_window_instance == NULL)
            _m_window_instance = new Window();
        return _m_window_instance;
    }

    void Window::terminate()
    {
        WindowMode::disableRowMode();
        std::exit(0);
    }

};

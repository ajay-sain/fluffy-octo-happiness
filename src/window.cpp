#include "../include/window.hpp"

namespace TerminalTextEditor
{

    Window* Window::_m_instance;
    termios Window::orig_termios;

    Window::Window()
    {
        struct winsize ws;
        if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0)
            TerminalTextEditor::Window::terminate();
        _m_cols = ws.ws_col;
        _m_rows = ws.ws_row;
    }

    Window::~Window() {}

    int Window::getWindowHeight()
    {
        return _m_rows;
    }

    int Window::getWindowWidth()
    {
        return _m_cols;
    }

    void Window::initRowMode()
    {
        // _m_editor_mode = true;
        try
        {
            std::cout << "############################## Enabling Row Mode ###############################\r\n";
            tcgetattr(STDIN_FILENO, &orig_termios);
            struct termios raw = orig_termios;
            raw.c_iflag &= ~(ICRNL | IXON);
            raw.c_oflag &= ~(OPOST);
            // raw.c_cc[VMIN] = 0;
            // raw.c_cc[VTIME] = 1;
            raw.c_lflag &= ~(ECHO | ICANON | ISIG);
            tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
        }
        catch (std::exception e)
        {
            std::cout << e.what() << std::endl;
            Window::exitRowMode();
        }
    }

    void Window::exitRowMode()
    {
        std::cout << "############################## Destroying Row Mode ###############################\r\n";
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
        // Window::clearWindow();
        // _m_editor_mode = false;
    }

    void Window::clearWindow()
    {
        write(STDOUT_FILENO, "\x1b[2J", 4);
        write(STDOUT_FILENO, "\x1b[H", 3);
    }

    Window *Window::getInstance()
    {
        if(_m_instance == NULL)
            _m_instance = new Window();
        return _m_instance;
    }

    void Window::terminate(){
        Window::exitRowMode();
        // Window::clearWindow();
        exit(0);
    }

};
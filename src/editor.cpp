#include "../include/editor.hpp"

namespace TerminalTextEditor
{

    Editor *Editor::_m_instance;

    Editor::Editor()
    {
        _m_cursor = Cursor::getInstance();
        _m_keyboard = Keyboard::getInstance();
        _m_window = Window::getInstance();
    }

    Editor::~Editor() {}

    void Editor::refreshScreen()
    {
        write(STDOUT_FILENO, "\x1b[?25l", 6);
        write(STDOUT_FILENO, "\x1b[H", 3);
        drawLineNumber();
        char buf[32];
        snprintf(buf, sizeof(buf), "\x1b[%d;%dH", _m_cursor->getY() + 1, _m_cursor->getX() + 1);
        write(STDOUT_FILENO, buf, strlen(buf));
        write(STDOUT_FILENO, "\x1b[?25h", 6);
    }

    void Editor::loop()
    {
        while (1)
        {
            refreshScreen();
            handleInput();
        }
    }

    void Editor::handleInput()
    {
        int c = _m_keyboard->handleKeyPress();
        switch (c)
        {
        case CTRL_KEY('q'):
            std::cout << "quitting terminal\r\n";
            Window::terminate();
            break;
        case CTRL_KEY('s'):
            std::cout << "saving file\r\n";
            break;
        case ARROW_UP:
        case ARROW_DOWN:
        case ARROW_RIGHT:
        case ARROW_LEFT:
            _m_cursor->move(c);
            break;
        default:
            std::cout << "iscntrl"
                      << iscntrl(c) << " (int)c" << (char)c << " c" << c << "\r\n";
        }
    }

    Editor *Editor::getInstance()
    {
        if (_m_instance == NULL)
            _m_instance = new Editor();
        return _m_instance;
    }

    void Editor::drawLineNumber()
    {
        for (int y = 0; y < _m_window->getWindowHeight(); y++)
        {
            write(STDOUT_FILENO, "~", 1);
            write(STDOUT_FILENO, "\x1b[K", 3);
            if (y < _m_window->getWindowHeight() - 1)
                write(STDOUT_FILENO, "\r\n", 2);
        }
    }

};
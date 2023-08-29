#include "../include/keyboard.hpp"
#include "../include/window.hpp"


namespace TerminalTextEditor
{

    Keyboard *Keyboard::_m_instance;

    Keyboard::Keyboard(){}

    Keyboard::~Keyboard(){}

    Keyboard *Keyboard::getInstance()
    {
        if (_m_instance == NULL)
            _m_instance = new Keyboard();
        return _m_instance;
    }

    int Keyboard::handleKeyPress()
    {
        int nread;
        char c;
        while ((nread = read(STDIN_FILENO, &c, 1)) != 1)
            if (nread == -1 && errno != EAGAIN)
                TerminalTextEditor::Window::terminate();
        if (c == '\x1b')
        {
            char seq[3];

            if (read(STDIN_FILENO, &seq[0], 1) != 1)
                return '\x1b';
            if (read(STDIN_FILENO, &seq[1], 1) != 1)
                return '\x1b';

            if (seq[0] == '[')
            {
                switch (seq[1])
                {
                case 'A':
                    return ARROW_UP;
                case 'B':
                    return ARROW_DOWN;
                case 'C':
                    return ARROW_RIGHT;
                case 'D':
                    return ARROW_LEFT;
                }
            }
            return '\x1b';
        }
        else
            return c;
    }

};
#include "../include/mode.hpp"

namespace Editor
{

    termios WindowMode::orig_termios;

    void WindowMode::enableRowMode()
    {
        try
        {
            std::cout << "############################## Enabling Row Mode ###############################\r\n";
            tcgetattr(STDIN_FILENO, &Editor::WindowMode::orig_termios);
            struct termios raw = Editor::WindowMode::orig_termios;
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
            WindowMode::disableRowMode;
        }
    }

    void WindowMode::disableRowMode()
    {
        std::cout << "############################## Destroying Row Mode ###############################\r\n";
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &Editor::WindowMode::orig_termios);
    }

}
#include "../include/window.hpp"
#include "../include/keyboard.hpp"

int main(int argc, char const *argv[])
{
    TerminalTextEditor::Window::initRowMode();

    TerminalTextEditor::Keyboard* keyboard = TerminalTextEditor::Keyboard::getInstance();

    try
    {
        char c;
        keyboard->handleKeyPress();
        // while(read(STDIN_FILENO, &c, 1) == 1){
        //     std::cout << c ;
        // }
    }
    catch (std::exception e)
    {
        std::cout << e.what() << std::endl;
    }

    TerminalTextEditor::Window::exitRowMode();
    return 0;
}
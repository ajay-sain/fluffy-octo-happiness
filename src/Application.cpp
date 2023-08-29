#include "../include/window.hpp"
#include "../include/keyboard.hpp"
#include "../include/editor.hpp"

int main(int argc, char const *argv[])
{
    TerminalTextEditor::Window::initRowMode();

    TerminalTextEditor::Editor *editor = TerminalTextEditor::Editor::getInstance();

    try
    {
        editor->loop();
    }
    catch (std::exception e)
    {
        std::cout << e.what() << std::endl;
    }

    TerminalTextEditor::Window::exitRowMode();
    return 0;
}
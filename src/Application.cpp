#include "../include/mode.hpp"
#include "../include/editor.hpp"

int main(int argc, char const *argv[])
{
    Editor::WindowMode::enableRowMode();

    Editor::TerminalEditor* editor = Editor::TerminalEditor::getInstance();

    try
    {
        editor->loop();
    }
    catch (std::exception e)
    {
        std::cout << e.what() << std::endl;
    }

    Editor::WindowMode::disableRowMode();
    return 0;
}
#include "../include/editor.hpp"

namespace Editor
{
    TerminalEditor *TerminalEditor::_m_local_instance;

    TerminalEditor::TerminalEditor(){}

    TerminalEditor::~TerminalEditor() {}

    TerminalEditor *TerminalEditor::getInstance()
    {
        if (_m_local_instance == NULL)
            _m_local_instance = new TerminalEditor();
        return _m_local_instance;
    }

    void TerminalEditor::loop(){
        refreshScreen();
        // readInput();
    }

    void TerminalEditor::refreshScreen(){
        // clearScreen();
        // writeBuffer();
        std::cout << "clearing Screen\r\n";

    }
};
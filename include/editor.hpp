#pragma once

#include <iostream>

namespace Editor
{
    class TerminalEditor
    {
    private:
        static TerminalEditor *_m_local_instance;
        TerminalEditor();

    public:
        TerminalEditor(const TerminalEditor &) = delete;
        TerminalEditor &operator=(const TerminalEditor &) = delete;
        ~TerminalEditor();

        static TerminalEditor* getInstance();

        void loop();

        void refreshScreen();

    };
};
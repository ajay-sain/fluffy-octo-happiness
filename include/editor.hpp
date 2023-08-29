#pragma once

#include "common.hpp"
#include "../include/cursor.hpp"
#include "../include/keyboard.hpp"


namespace TerminalTextEditor{

    class Editor{
        private:
            bool _m_mode;
            static Editor* _m_instance;
            TerminalTextEditor::Cursor* _m_cursor;
            TerminalTextEditor::Keyboard* _m_keyboard;
            TerminalTextEditor::Window* _m_window;
            Editor();

        public:
            ~Editor();
            Editor(const Editor &) = delete;
            Editor &operator=(const Editor &) = delete;
            void refreshScreen();
            void loop();
            void handleInput();
            static Editor* getInstance();
            void drawLineNumber();
    };

};
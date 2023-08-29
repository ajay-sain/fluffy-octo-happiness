#pragma once

#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <exception>
#include <sys/ioctl.h>

namespace TerminalTextEditor{
    class Window{
        private:
            int _m_rows;
            int _m_cols;
            static bool _m_editor_mode;
            static Window* _m_instance;
            Window();
        
        public: 
            static termios orig_termios;
            ~Window(){}
            Window(const Window &) = delete;
            Window &operator=(const Window &) = delete;

            int getWindowHeight();
            int getWindowWidth();
            static void initRowMode();
            static void exitRowMode();
            static void clearWindow();
            static Window* getInstance();
            void terminate();
    };
};
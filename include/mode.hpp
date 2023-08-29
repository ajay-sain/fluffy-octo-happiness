#pragma once

#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <exception>

namespace Editor{   

    class WindowMode{

        public:
            static termios orig_termios;
            WindowMode() = delete;
            WindowMode(const WindowMode& obj) = delete;
            WindowMode &operator=(const WindowMode& obj) = delete;
            ~WindowMode();
            
            static void enableRowMode(void);
            static void disableRowMode(void);
    };

    class EditorMode{

    };

}
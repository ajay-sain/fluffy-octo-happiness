#pragma once

#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <exception>
#include <sys/ioctl.h>

namespace TerminalTextEditor{

    enum ArrowKey{
        ARROW_UP=1000, ARROW_DOWN, ARROW_LEFT, ARROW_RIGHT
    };

};
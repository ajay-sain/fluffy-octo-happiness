#pragma once

#include "common.hpp"

namespace TerminalTextEditor{
    class Keyboard{
        private:
            static Keyboard* _m_instance;

        public:
            static Keyboard* getInstance();
            int handleKeyPress();
    };
};
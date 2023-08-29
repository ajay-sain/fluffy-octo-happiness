#pragma once

#include "common.hpp"

namespace TerminalTextEditor{
    class Keyboard{
        private:
            static Keyboard* _m_instance;
            Keyboard();

        public:
            ~Keyboard();
            Keyboard(const Keyboard &) = delete;
            Keyboard &operator=(const Keyboard &) = delete;
            static Keyboard* getInstance();
            int handleKeyPress();
    };
};
#pragma once


#include "window.hpp"

namespace TerminalTextEditor{

    enum CursorControl{
        UP=1000, DOWN, LEFT, RIGHT
    };

    class Cursor{
        private:
            static Cursor* _m_instance;
            Window* _m_window;
            int _m_x;
            int _m_y;
            Cursor();
        
        public: 
            ~Cursor();
            Cursor (const Cursor &);
            Cursor &operator=(const Cursor &);
            void move(Cursor);
            void move(int x, int y);
            static Cursor* getInstance();
    };
};
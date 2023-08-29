#pragma once

#include "../include/mode.hpp"

namespace Editor{
    class Window{   

        private:
            static Editor::Window *_m_window_instance;
            Window();

        public:
            int _m_rows;
            int _m_cols;
            bool _m_insert_mode;

            ~Window();
            Window(const Editor::Window &) = delete;
            Window &operator=(const Editor::Window &) = delete;

            Editor::Window* getWindowInstance();

            void terminate();
    };
};
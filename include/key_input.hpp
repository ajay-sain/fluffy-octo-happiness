#pragma once

namespace Editor{
    class KeyInput{
        private:
            KeyInput();
        public:
            KeyInput(const KeyInput &) = delete;
            KeyInput &operator=(const KeyInput &) = delete;
            ~KeyInput();

            KeyInput* getInstance();

            int readKeyboardInput();
    };
}
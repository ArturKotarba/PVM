#pragma once
#include "stdafx.h"
#include "GraphicsImgReader.h"
#include "ScreenManager.h"

namespace SX::SDLWindow
{

    class SDLWindow
    {
        public:
        explicit SDLWindow(string_view title_in);
        void start(int, int);
        ~SDLWindow();
        void createWindowWithBMP();
        void setScreen();
        void update();

        private:
        // unique_ptr<SDL_Window> window;
        // unique_ptr<SDL_Surface> screen;

        SDL_Window* m_window;
        string_view m_title;
        SX::Images::GraphicsImgReader m_imgReader;
        SX::ScreenManager::ScreenManager m_screenManager;
    };
    
    
} // namespace SX::SDLWindow



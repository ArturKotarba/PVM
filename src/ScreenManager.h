#pragma once
#include "stdafx.h"
#include "BuildingAreaCalculator.h"

using Callback = function<void()>; 

#define time std::chrono::_V2::system_clock::time_point

namespace SX::ScreenManager
{
    class ScreenManager
    {
    public:
        ScreenManager();
        ~ScreenManager();
        void drawBMPOnWindow(int width, int height, shared_ptr<SDL_Surface> surface, std::vector<int>& retTableToSlave_in);
        SDL_Color getPixelSurface(int x, int y, shared_ptr<SDL_Surface> surface);
        void setPixel(int x, int y, Uint8 R, Uint8 G, Uint8 B);
        void init(SDL_Window* window);
        void registerCallback(Callback callback_in);

    private:
        SDL_Surface *m_screen;
        Callback m_callback;
        SX::Building::Calculator::BuildingAreaCalculator m_buildingAreaCalculator;
    };

} // namespace SX::ScreenManager

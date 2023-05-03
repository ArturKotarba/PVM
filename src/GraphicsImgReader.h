#pragma once
#include "stdafx.h"

namespace SX::Images
{
    class GraphicsImgReader
    {

    public:
        GraphicsImgReader();
        ~GraphicsImgReader();
        shared_ptr<SDL_Surface> getBitmap();
        uint16_t getWidth();
        uint16_t getHeight();
        void loadBMP(string filePath = "");

    private:
        shared_ptr<SDL_Surface> m_bmp;
        uint16_t m_height, m_width;
    };

} // namespace SX::Images

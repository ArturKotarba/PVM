#pragma once
#include "stdafx.h"

namespace SX::Images
{
    class GraphicsImgReader
    {

    public:
        GraphicsImgReader();
        ~GraphicsImgReader();
        const shared_ptr<SDL_Surface> getBitmap();
        const uint16_t getWidth();
        const uint16_t getHeight();
        void loadBMP(const string& filePath_in = "");

    private:
        shared_ptr<SDL_Surface> m_bmp;
        uint16_t m_height, m_width;
    };

} // namespace SX::Images

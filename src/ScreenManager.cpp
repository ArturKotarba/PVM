#include "ScreenManager.h"

namespace SX::ScreenManager
{

    ScreenManager::ScreenManager() : m_screen(nullptr)
    {
    }

    ScreenManager::~ScreenManager()
    {
    }

    void ScreenManager::init(SDL_Window *window)
    {
        if (window)
        {
            m_screen = SDL_GetWindowSurface(window);
            if (m_screen == nullptr)
            {
                throw("SDL_GetWindowSurface Error: ", SDL_GetError());
            }
            m_callback();
        }
    }

    void ScreenManager::drawBMPOnWindow(int width, int height, shared_ptr<SDL_Surface> bmp)
    {
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                SDL_Color color;
                color = getPixelSurface(x, y, bmp);
                //cout << "r, g, b: " << (int)color.r << " " << (int)color.g << " " << (int)color.b << "\n";
                m_buildingAreaCalculator.compareColors(color);
                setPixel(x, y, color.r, color.g, color.b);
            }
        }
        m_callback();
        // m_buildingAreaCalculator.getPixelsNumber();
        // TODO line above is needed only for testing so far
    }

    SDL_Color ScreenManager::getPixelSurface(int x, int y, shared_ptr<SDL_Surface> surface)
    {

        SDL_Color color;
        Uint32 col = 0;

        // określamy pozycję
        char *pPosition = reinterpret_cast<char *>(surface->pixels);

        // przesunięcie względem y
        pPosition += (surface->pitch * y);

        // przesunięcie względem x
        pPosition += (surface->format->BytesPerPixel * x);

        // kopiujemy dane piksela
        memcpy(&col, pPosition, surface->format->BytesPerPixel);

        // konwertujemy kolor
        SDL_GetRGB(col, surface->format, &color.r, &color.g, &color.b);

        return (color);
    }

    void ScreenManager::setPixel(int x, int y, Uint8 R, Uint8 G, Uint8 B)
    {
        /* Zamieniamy poszczególne składowe koloru na format koloru piksela */
        Uint32 pixel = SDL_MapRGB(m_screen->format, R, G, B);

        /* Pobieramy informację ile bajtów zajmuje jeden piksel */
        int bpp = m_screen->format->BytesPerPixel;

        /* Obliczamy adres piksela */
        Uint8 *p1 = reinterpret_cast<Uint8 *>(m_screen->pixels + (y) * m_screen->pitch + (x) * bpp);

        /* Ustawiamy wartość piksela, w zależnoœci od formatu powierzchni*/
        switch (bpp)
        {
        case 1: // 8-bit
            *p1 = pixel;
            break;

        case 2: // 16-bit
            *(reinterpret_cast<Uint16 *> (p1)) = pixel;
            break;

        case 3: // 24-bit
            if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
            {
                p1[0] = (pixel >> 16) & 0xff;
                p1[1] = (pixel >> 8) & 0xff;
                p1[2] = pixel & 0xff;
            }
            else
            {
                p1[0] = pixel & 0xff;
                p1[1] = (pixel >> 8) & 0xff;
                p1[2] = (pixel >> 16) & 0xff;
            }
            break;

        case 4: // 32-bit
            *(reinterpret_cast<Uint32 *> (p1)) = pixel;
            break;
        }
    }

    void ScreenManager::registerCallback(Callback callback_in)
    {
        m_callback = callback_in;
    }

}
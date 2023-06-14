#include "SDLWindow.h"

namespace SX::SDLWindow
{
    SDLWindow::SDLWindow(string_view title_in) : m_window(nullptr), m_title(title_in)
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
        {
	    	throw("SDL_Init Error: ", SDL_GetError());
        }        
    }

    SDLWindow::~SDLWindow()
    {
    }

    void SDLWindow::start(int MIN, int MAX)
    {
        std::vector<int> retTableToSlave{};
        
        for(int i = MIN; i < MAX; i++) 
        {
            m_imgReader.loadBMP("graphicsImages/" + std::to_string(i + 1) + ".bmp");
            createWindowWithBMP();
            m_screenManager.registerCallback([this](){this->update();});
            m_screenManager.init(m_window);
            m_screenManager.drawBMPOnWindow(m_imgReader.getWidth(), m_imgReader.getHeight(), m_imgReader.getBitmap(), retTableToSlave);
            //probably best way is to create new instance of screenManager::m_buildingAreaCalcultor for each picture
        }
            pvm_initsend(PvmDataDefault);
            
            // for (int i = 0; i < retTableToSlave.size(); i++)
            // {
            //     std::cout << "retTableToSlave[i]: " << retTableToSlave[i] << "\n"; 
            // }

            int info = pvm_pkint(retTableToSlave.data(), retTableToSlave.size(), 1);
            pvm_send(pvm_parent(), 1);
    }

    void SDLWindow::createWindowWithBMP()
    {
        m_window = SDL_CreateWindow(m_title.data(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                                   m_imgReader.getWidth(), m_imgReader.getHeight(), SDL_WINDOW_SHOWN);
    }

    void SDLWindow::update()
    {
        SDL_UpdateWindowSurface(m_window);
    }

} // namespace SX::SDLWindow




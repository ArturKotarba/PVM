#include "stdafx.h"
#include "SDLWindow.h"

int main(int argc, char *argv[])
{
    try
    {
        SX::SDLWindow::SDLWindow mainWindow("PVM");
        mainWindow.start();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch( ... )
    {
        std::cout << "Unknow error!!\n";
    }

    SDL_Delay(6000);
    SDL_Quit();
    return 0;
    }
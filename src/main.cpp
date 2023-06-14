#include "stdafx.h"
#include "SDLWindow.h"

int MIN, MAX;

int main(int argc, char *argv[])
{
    pvm_catchout(stdout);
    if(argc == 3) {
        MIN = stoi(argv[1]);
        MAX = stoi(argv[2]);
        printf("MIN: %d, MAX: %d\n", MIN, MAX);
    }

    try
    {
        SX::SDLWindow::SDLWindow mainWindow("PVM");
        mainWindow.start(MIN, MAX);
        //pvm_exit();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        //pvm_exit();
    }
    catch( ... )
    {
        std::cout << "Unknow error!!\n";
        //pvm_exit();
    }

    pvm_exit();
    SDL_Quit();
    return 0;
}
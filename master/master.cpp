#include "stdafx.h"
#include <chrono>

int main()
{
    int masterId, numOfProcesses = 3, numOfFiles = 21, createdProcesses;
    int childrenIds[1];
    std::vector<int> createdChilds{};
    const int index = numOfFiles / numOfProcesses;

    pvm_catchout(stdout);

    if((masterId = pvm_mytid()) < 0) 
        pvm_perror("Error occured: Could not create master PVM process");
    

    printf("Master ID: %d\n", masterId);
    
    auto start = std::chrono::system_clock::now();

    for(int i = 0; i < numOfProcesses; i++)
    {
        printf("argv[1]: %s, argv[2]: %s\n", std::to_string(i * index).c_str(), std::to_string((i + 1) * index).c_str());
        char buf1[5], buf2[5];

        sprintf(buf1, "%d", i * index);
        sprintf(buf2, "%d", (i + 1) * index);
        
        char *argsv[] = { 
            buf1,
            buf2,
            (char *) 0
        };

        if((createdProcesses += pvm_spawn("slave", argsv, PvmTaskDefault, "", 1, childrenIds)) < 0) 
            pvm_perror("Error occured: Could not create child PVM process");

        createdChilds.push_back(childrenIds[0]);
    }
    
    std::cout << "createdChilds.size(): " << createdChilds.size() << "\n";
    
    std::vector<int> allGraphics{};
    allGraphics.reserve(numOfFiles);


    int indexIteration = 0; 
    for (int i = 0; i < createdChilds.size(); i++)
    {
        if (createdChilds[i] > 0)
        {
            while (true)
            {
                int recv_result = pvm_nrecv(createdChilds[indexIteration], 1);
                if (recv_result)
                {
                    std::vector<int> graphiscFromCurrChild{};
                    graphiscFromCurrChild.resize(index);
                    pvm_upkint(graphiscFromCurrChild.data(), index, 1);
                    allGraphics.insert(allGraphics.end(), graphiscFromCurrChild.begin(), graphiscFromCurrChild.end());
                    break;
                }

                if (indexIteration >= createdChilds.size())
                    indexIteration = 0;
                else    
                    indexIteration++;
            }
            
        }
    }

    for(int i = 0; i < allGraphics.size(); i++)
    {
        std::cout<< "obrazek nr " << i + 1 <<  ", pole: " << allGraphics[i] << " m2 "<< "\n";
    }

    auto end = std::chrono::system_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "Time that whole program took: " << diff << "\n"; 


    //Time that whole program took: 366549, 358036

    pvm_exit();
    return 0;
}
















    
    // std::cout << "x: " << x << "\n";

    // for(int i = 0; i < numOfProcesses; i++) {
    //     printf("print");
    //     int cont = 1;
    //     while(cont) 
    //     {
    //         int recv_result = pvm_recv(childrenIds[0], -1);
    //         if(recv_result) 
    //         {
    //             std::cout << "recv_result: " << recv_result << "\n"; 
    //             int numbers[index] = {0};
    //             pvm_upkint(numbers, index, 1);
    //             for(int j = 0; j < index; j++) 
    //             {
    //                 printf("print2");
    //                 std::cout<< "obrazek nr " << i + j << ", pole: " << numbers[j] << "\n";// << ", czas: " << numbers[1] << " mikrosekund" << std::endl;
    //                 //std::cout<< "obrazek nr " << i + j << ", pole: " << numbers[0] << ", czas: " << numbers[1] << " mikrosekund" << std::endl;
    //             }
    //             cont = 0;
    //             break;
    //         }
    //     }
    // }


    // for(int i = 0; i < numOfProcesses; i++) 
    // {
    //     int cont = 0;
    //     while(!cont) {
    //         int recv_result = pvm_nrecv(childrenIds[i], 0);
    //             if (recv_result)
    //             {
    //                 for(int j = 0; j < numOfFiles / numOfProcesses; j++) {
    //                     std::cout<< "recv_result: " << recv_result << "\n";
    //                     cont++;
    //                     int numbers[2] = {0, 0};
    //                     pvm_upkint(numbers, 2, 1);
    //                     std::cout<< "obrazek nr " << j << ", pole: " << numbers[0] << ", czas: " << numbers[1] << " mikrosekund" << std::endl;
    //                     if (cont == (numOfFiles / numOfProcesses))
    //                     {
    //                         break;
    //                     }
    //             }
    //         }
    //     }
    // }
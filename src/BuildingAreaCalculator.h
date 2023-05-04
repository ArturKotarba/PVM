#pragma once
#include "stdafx.h"

namespace SX::Building::Calculator
{

    class BuildingAreaCalculator
    {
        struct BuildingsColors
        {
            SDL_Color buildingColor{241, 243, 244}, buildingEdge{221, 223, 226};
        };

    public:
        BuildingAreaCalculator();
        ~BuildingAreaCalculator();
        void compareColors(const SDL_Color &color_in);
        void calculateTotatlArea();
        bool compareBuildingColors(const SDL_Color &color_in);
        bool compareBuildingEdgeColors(const SDL_Color &color_in);
        const size_t getPixelsNumber();

    private:
        BuildingsColors m_buildingsColors;
        size_t m_pixelsNumber;
    };
} // namespace SX::Building::Calculator
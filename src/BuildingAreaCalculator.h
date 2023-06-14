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
        const size_t calculateTotalArea();
        bool compareBuildingColors(const SDL_Color &color_in);
        bool compareBuildingEdgeColors(const SDL_Color &color_in);
        const size_t getPixelsNumber();
        void setPixelNumber(size_t val);

    private:
        BuildingsColors m_buildingsColors;
        size_t m_pixelsNumber;
    };
} // namespace SX::Building::Calculator
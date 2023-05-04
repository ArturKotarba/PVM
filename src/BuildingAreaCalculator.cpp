#include "BuildingAreaCalculator.h"

namespace SX::Building::Calculator
{
    BuildingAreaCalculator::BuildingAreaCalculator() : m_pixelsNumber(0)
    {
    }

    BuildingAreaCalculator::~BuildingAreaCalculator()
    {
    }

    bool BuildingAreaCalculator::compareBuildingColors(const SDL_Color &color_in)
    {
        if (color_in.r == m_buildingsColors.buildingColor.r && color_in.g == m_buildingsColors.buildingColor.g &&
            color_in.b == m_buildingsColors.buildingColor.b)
        {
            return true;
        }
        return false;
    }

    bool BuildingAreaCalculator::compareBuildingEdgeColors(const SDL_Color &color_in)
    {
        if (color_in.r == m_buildingsColors.buildingEdge.r && color_in.g == m_buildingsColors.buildingEdge.g &&
            color_in.b == m_buildingsColors.buildingEdge.b)
        {
            return true;
        }
        return false;
    }

    void BuildingAreaCalculator::compareColors(const SDL_Color &color_in)
    {
        if (compareBuildingColors(color_in) || compareBuildingEdgeColors(color_in))
        {
            m_pixelsNumber++;
        }
    }

    void BuildingAreaCalculator::calculateTotatlArea()
    {
        // TODO take num of pixels and multiply by scale
    }

    const size_t BuildingAreaCalculator::getPixelsNumber()
    {
        return m_pixelsNumber;
    }

} // namespace SX::Building::Calculator
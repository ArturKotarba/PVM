#include "BuildingAreaCalculator.h"

#define SCALE 10
#define SCREENHEIGTH 14 // cali
#define SCREENWIDTH 10 // cali


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

    const size_t BuildingAreaCalculator::calculateTotalArea()
    {
        // std::cout << "getScreenResolution(): " << getScreenResolution() << "getPixelsNumber(): " << getPixelsNumber() << "\n";

        return ((getPixelsNumber() *  getScreenResolution() ) / 100 * SCALE);
    }

    const size_t BuildingAreaCalculator::getPixelsNumber()
    {
        return m_pixelsNumber;
    }

    void BuildingAreaCalculator::setPixelNumber(size_t val) 
    {
        m_pixelsNumber = val;
    }

    double BuildingAreaCalculator::getScreenResolution()
    {
        SDL_GetCurrentDisplayMode(0, &m_DM);

        auto realPixelHeight = ( SCREENHEIGTH * 2.5 * 10 ) / m_DM.h;
        auto realPixelWidth = ( SCREENHEIGTH * 2.5 * 10 ) / m_DM.w;

        return realPixelHeight * realPixelWidth;
    }

} // namespace SX::Building::Calculator
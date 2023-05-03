#include "GraphicsImgReader.h"

namespace SX::Images
{
  GraphicsImgReader::GraphicsImgReader() : m_bmp(nullptr), m_height(0), m_width(0)
  {
  }

  GraphicsImgReader::~GraphicsImgReader()
  {
  }

  shared_ptr<SDL_Surface> GraphicsImgReader::getBitmap()
  {
    return m_bmp;
  }

  uint16_t GraphicsImgReader::getWidth()
  {
    return m_width;
  }

  uint16_t GraphicsImgReader::getHeight()
  {
    return m_height;
  }

  void GraphicsImgReader::loadBMP(string filePath)
  {
    filePath = SDL_GetBasePath();
    filePath += string("graphicsImages/5.bmp");
    m_bmp.reset(SDL_LoadBMP(filePath.data()));

    if (!m_bmp.get())
    {
      throw("Could not load m_bmp ", filePath);
    }

    m_height = m_bmp->h;
    m_width = m_bmp->w;
  }

} // namespace SX::Images

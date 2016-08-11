#pragma once
#include "common/types.h"
#include <functional>

namespace decaf
{

class GraphicsDriver
{
public:
   virtual ~GraphicsDriver()
   {
   }

   virtual void run() = 0;
   virtual void stop() = 0;
   virtual float getAverageFPS() = 0;

   virtual void invalidateMemory(uint32_t mode, ppcaddr_t memStart, ppcaddr_t memEnd) = 0;
};

class OpenGLDriver : public GraphicsDriver
{
public:
   virtual ~OpenGLDriver()
   {
   }

   virtual void getSwapBuffers(unsigned int *tv, unsigned int *drc) = 0;
   virtual void syncPoll(std::function<void(unsigned int, unsigned int)> swapFunc) = 0;
};

OpenGLDriver *
createGLDriver();

void
setGraphicsDriver(GraphicsDriver *driver);

GraphicsDriver *
getGraphicsDriver();

} // namespace decaf

#include <functional>
#include <initializer_list>
#include <string>
using Handle = std::function<void()>;
using slist = std::initializer_list<std::string>;

#include <imgui.h>//Interface Dependencies
#include <imgui_impl_sdl.h>
#include <imgui_impl_opengl3.h>

#include <GL/glew.h>                                //Rendering Dependencies
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <sstream>                                  //File / Console IO
#include <iostream>
#include <fstream>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>

#include "utility/texture.h"              //Utility Classes
#include "utility/shader.h"
#include "utility/model.h"
#include "utility/instance.h"
#include "utility/target.h"

#include "view.h"
#include "event.h"
#include "audio.h"

#include <chrono>

/* TINY ENGINE */

namespace Tiny {

static View view;           //Window and Interface  (Requires Initialization)
static Event event;         //Event Handler
static Audio audio;         //Audio Processor       (Requires Initialization)

bool window(std::string windowName, int width, int height){ //Open a window
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
    printf( "SDL could not initialize! Error: %s\n", SDL_GetError() );
    return false;
  }

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

  if( !( IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG ) ){
    printf( "SDL_Image could not initialize! Error: %s\n", IMG_GetError() );
    return false;
  }

  if( TTF_Init() == -1 ){ //for some reason this is -1
    printf( "SDL_ttf could not initialize! Error: %s\n", TTF_GetError() );
    return false;
  }

  if(!view.init(windowName, width, height)){ //Start the View Class
    std::cout<<"Failed to launch visual interface."<<std::endl;
    return false;
  }

  if(!audio.init()){ //Start the Audio Interface
    std::cout<<"Failed to launch audio interface."<<std::endl;
		return false;
	}

  return true;
}

void quit(){
  if(Tiny::view.enabled)  view.quit();
  if(Tiny::audio.enabled) audio.quit();
  TTF_Quit();
  SDL_Quit();
}

template<typename F, typename... Args>
void loop(F function, Args&&... args){
  while(!event.quit){

    if(Tiny::view.enabled){
      event.input();        //Get Input
      event.handle(view);   //Call the event-handling system
    }

    if(Tiny::audio.enabled) audio.process();      //Audio Processor

    function(args...);      //User-defined Game Loop

    if(Tiny::view.enabled)  view.render();        //Render View

  }
}

}

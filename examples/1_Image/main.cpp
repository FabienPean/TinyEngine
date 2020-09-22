#include <TinyEngine/TinyEngine.h>
#include <TinyEngine/helpers/image.h>
#include <TinyEngine/helpers/color.h>

#include "effects.h"

int main( int argc, char* args[] ) {

	Tiny::window("Shader Effects Example", 1200, 800);

	Tiny::event.handler = [](){ /* ... */ };

	Tiny::view.interface = interfaceFunc;

	Texture tex(image::load("assets/canyon.png"));		//Load Texture with Image
	Square2D flat;														//Create Primitive Model
	Shader effect({"assets/shader/effect.vs", "assets/shader/effect.fs"}, {"in_Quad", "in_Tex"});

	Tiny::view.pipeline = [&](){

		Tiny::view.target(color::black);				//Target Main Screen

		effect.use();														//Use Effect Shader
		effect.uniform("index", ind);						//Define Uniforms
		effect.uniform("res", res);
		effect.uniform("bits", bits);
		effect.texture("imageTexture", tex);		//Load Texture
		effect.uniform("model", flat.model);		//Add Model Matrix
		flat.render();													//Render Primitive

	};

	Tiny::loop([&](){
		/* Absolutely Nothing! */
	});

	Tiny::quit();

	return 0;
}

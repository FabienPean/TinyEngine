#include <TinyEngine/TinyEngine.h>

int main( int argc, char* args[] ) {

	Tiny::audio.init();
	Tiny::audio.load({"assets/acoustic.wav"});
	Tiny::audio.play("assets/acoustic.wav");

	Tiny::loop([&](){
		//This waits until the program quits...
	});

	Tiny::quit();

	return 0;
}

#include <iostream>
#include <cstdlib>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "NBody.hpp"

using namespace std;

int main(int argc, char* argv[]){

    int cbodies;
    
    double dt;
    double radius;
    double T;
    double time;

    string filename;

    sf::Clock clock; // for displaying elapsed time
    

    sf::SoundBuffer buffer; // load the audio file
    sf::Sound sound; // play the audio file
    
    if (argc != 3){
        
        cout << "\nThere are not enough arguments, exiting!" << endl;
        return -1;
    }
    
    time = 0; // start time

    filename = argv[0]; // make the filename the first arrgument
    T = strtod(argv[1], NULL); // max time
    dt = strtod(argv[2], NULL);
    
    cin >> cbodies; // take in CelestialBodies and the radius
    cin >> radius;


    Universe cb(radius, 500, cbodies,cin); // make a universe

    sf::RenderWindow window(sf::VideoMode(600, 600), "Meet Kothari's Solar System"); // display a window 
    
    buffer.loadFromFile("spacesound.ogg"); // the sound data is not stored directly in sf::Sound but in a separate class named sf::SoundBuffer. This class encapsulates the audio data, which is basically an array of 16-bit signed integers (called "audio samples"). 

	sound.setBuffer(buffer); // set the sound to the file I specified
	sound.play(); // play the sound
    
    while (window.isOpen()){
        
        sf::Event event;
        
        while (window.pollEvent(event)){ if (event.type == sf::Event::Closed) window.close(); }
        
        window.clear();
        
        if (time < T){ // as long as time hasn't run out

            sf::Time elapsed = clock.getElapsedTime(); // make sure to keep printing the elapsed time
            
            cout << "\nElapsed time: " << elapsed.asSeconds( ) << " seconds." << endl;
            
            cb.step(dt);
            
            time += dt;
        }
        
        window.draw(cb);
        window.display();
    }

	return 0;
}

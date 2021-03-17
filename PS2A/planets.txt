#ifndef _NBODY_H
#define _NBODY_H

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>


#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

const sf::Vector2f window(500,500);
const double radius = 2.50e11;

using namespace std;

class CelestialBody: public sf::Drawable {
    
    public:
    
    CelestialBody(); // default
    CelestialBody(double x_position, double y_position, double x_velocity, double y_velocity, double bmass, string planet); //  most important function in the class, will help positioning heavily

    void draw(sf::RenderTarget &obj, sf::RenderStates status) const; // draw!
    
    friend ostream &operator <<(ostream &output, CelestialBody &c); // overload the << operator
    friend istream &operator >>(istream &input, CelestialBody &d);  // overload the >> operator
    
    private:
    
    double mass; // for mass
    
    double xpos; // for xpos
    double ypos; // for ypos
    
    double xvel; // for xvel
    double yvel; // for yvel
    
    string picture;
    
    sf::Image pImage; // for the image 
    
    sf::Sprite pSprite; // for the sprites
    
    sf::Texture pTexture; // for the textures
};

class universe {
    
    public:
    
    void draw(sf::RenderWindow &window1){ // keep track of how many loops
        
        for (unsigned int i = 0; i < uni.size();i++){ 
            
            window1.draw(uni[i]);
            
            cout << "Loop # " << i << endl;
        }
    }
    
    void pushback(CelestialBody obj){ uni.push_back(obj); } // push back, needed to add for my implementation
    
    private:
    
    vector <CelestialBody> uni; // vector
};

#endif

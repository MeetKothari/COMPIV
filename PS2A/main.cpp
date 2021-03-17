#include <string>
#include <iostream>

#include "NBody.h"

using namespace std;

int main(int argc,char *argv[]){
    
    int i, bodies; // variable declaration 
    double radius;

    CelestialBody *body;

    sf::Image backgroundimage;
    sf::Texture background_texture;
    sf::Sprite background_sprite;
    
    sf::RenderWindow window1(sf::VideoMode(500, 500), "Meet Kothari's Starry Night:"); // load up an SFML window and call it Meet Kothari's Starry Night
    
    backgroundimage.loadFromFile("starrynight.jpg"); // gotta get that extra credit!
    
    background_texture.loadFromImage(backgroundimage); // load from the jpg of the starry night i provided
    
    background_sprite.setTexture(background_texture); // set that texture to be the background texture of the SFML window
    
    cout << scientific; 
    
    cin >> bodies >> radius;
    
    window1.draw(background_sprite);
    
    window1.display();
    
    cout << "Input: " << bodies << " radius: " << radius << endl;

    unique_ptr <universe> u (new universe()); // get ready to make the Universe
    
    for(i = 0; i < bodies; i++){ // start a for loop to allocate space for the Universe and use the smart pointer defined before it to avoid memory leaks.
      
      body = new CelestialBody();
      
      cin >> *body;

      (*u).pushback(*body);
      
      cout << *body;
    }
    
    (*u).draw(window1); // start drawing
    
    window1.display(); // start displaying the drawings
    
    while (window1.isOpen()){ // close the window once the drawing is done

      sf::Event event;
      
      while(window1.pollEvent(event)){
        
        if (event.type == sf::Event::Closed) window1.close();
        
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window1.close(); 

      }
      
      window1.display(); // display out to the SFML window
    }
    
    return 0;
}

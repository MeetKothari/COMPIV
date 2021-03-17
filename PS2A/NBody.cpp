#include "NBody.h"

CelestialBody::CelestialBody(){ return; } // default 

CelestialBody::CelestialBody(double x_position, double y_position, double x_velocity, double y_velocity, double bmass, string planet){
	
	sf::Sprite draw_plan; // get everything defined
	
	xpos = x_position; // set the new positions according to the old ones
	
	ypos = y_position; // ^^^^^^^^^^^^^^
	
	xvel = x_velocity; // ^^^^^^^^^^^^^^
	
	yvel = y_velocity; // ^^^^^^^^^^^^^^
	
	mass = bmass; // ^^^^^^^^^^^
	
	picture = planet; // ^^^^^^^^^^
	
	if(!pImage.loadFromFile(picture)){ return; } // return if it doesn't working
	
	pTexture.loadFromImage(pImage); // load from the input(s) given
	
	pSprite.setTexture(pTexture); // load from the texture(s) given
	
	xpos = ((window.x/radius) * xpos/2) + (window.x / 2);   // sets value of x and y axis
	
	ypos = ((window.y/radius) * ypos/2) + (window.y / 2);  // ^^^^^^^^^^^^
	
	pSprite.setPosition(sf::Vector2f(xpos,ypos)); // set position according to aformentioned values
	
	cout << xpos << endl << ypos << endl; // output the values
}

void CelestialBody::draw(sf::RenderTarget &obj, sf::RenderStates status) const { obj.draw(pSprite); } // draw

ostream &operator <<(ostream &output, CelestialBody &c){ // overlad the output operator
	
	output << "current x Position: " << c.xpos << endl; // output the current x position
	
	output << "current y Postion: " << c.ypos << endl;  // output the current y position
	
	output << "current x Velocity: " << c.xvel << endl; // output the current x velocity
	
	output << "current y Velocity: " << c.yvel << endl; // output the current y velocity 
	
	output << "Particle Mass: " << c.mass << endl; // output the current particle mass 
	
	output << "Particle Name: " << c.picture << endl; // output the current particle name
	
	return output; // return output
}

istream &operator >>(istream &input, CelestialBody &d){ // overload the input operator
        
        input >> d.xpos >> d.ypos >> d.xvel >> d.yvel >> d.mass >> d.picture; // get the positions, velocity, mass, and picture
        
        if(!d.pImage.loadFromFile(d.picture)){ cout << "Error! Something went wrong while loading the file..." << endl; } // in case something goes wrong
        
        d.pTexture.loadFromImage(d.pImage); // load the image from the .gif files
        
        d.pSprite.setTexture(d.pTexture); // use the textures provided
        
        d.xpos = ((window.x/radius) * d.xpos/2) + (window.x / 2); // set the positioning 
        
        d.ypos = ((window.y/radius) * d.ypos/2) + (window.y / 2);
        
        d.pSprite.setPosition(sf::Vector2f(d.xpos, d.ypos)); // use the with the values given
        
        return input; // return the input
    }


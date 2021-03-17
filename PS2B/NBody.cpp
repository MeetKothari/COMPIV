#include "NBody.hpp" // need the header file, of course

#include <iostream>
#include <cmath>


using namespace std;


Universe::Universe(){ // basic constructor
	
	r = 0; // initialize r to be 0 
	winsize = 0; // winsize to be 0, cause it's a default constructor
}

Universe::Universe(double radius, int window, int num_of_planets, istream &in){

	int i; // for the loop
	
	r = radius; // set radius, window, numplanets to their updated values
	winsize = window; // update windowsize 
	numplanets = num_of_planets; // update number of planets
	
	for (i = 0; i < num_of_planets; i++){ // initialize planets
	
		unique_ptr <CelestialBody> ptr(new CelestialBody()); // implementation of the smart pointer
		
		CelestialBody(); // assign a new CelestialBody to aformentioned pointer 
		planets.push_back(move(ptr)); // push back
		planets[i]->set_radius(r); // ith field to set radius
		planets[i]->set_window(window); // set window
		in >> *planets[i]; // take in planets[i], insertion is already overloaded
	}

}

void Universe::draw(sf::RenderTarget &target, sf::RenderStates states) const { // draw!

	int i; // for loop

	for (i = 0; i < numplanets; i++){ // as long as there are planets left...
		
		target.draw(*planets.at(i), states); // draw each of the planets 
	}
}


void Universe::step(double seconds){

	int i, k; // initialization variables 
	
	double ax; // for each planet, implement net forces
	double ay;

	double dx; // gonna need X and Y of each...
	double dy;

	double force; // gravitational forces
	double forcex;
	double forcey;
	
	double fx; // horizontal and vertical forces
	double fy;

	double G; // for the gravitational constant 
	
	double velx; // for velocity
	double vely;

	double x2; // updated values of x and y
	double y2;
	
	double r; // radius
	
	for (i = 0; i < numplanets; i++){  // as long as there are planets left...
		
		fx = 0; // horizontal forces on a body, initialize at 0
		fy = 0; // vertical forces on a body, initialize at 0
		
		for (k = 0; k < numplanets; k++){ //for each planet, calculate total outside force
			
			if (k != i){
				
				G = 6.67e-11; // gravitational constant

				dx = planets[k]->get_posx() - planets[i]->get_posx(); // updated value of dx and dy
				dy = planets[k]->get_posy() - planets[i]->get_posy(); 
				
				r = sqrt(pow(dx, 2) + pow(dy, 2)); // update r using the values of dx and dy for accuracy
				
				force = (G * planets[k]->get_mass() * planets[i]->get_mass())/ pow(r, 2); // calculate forces
				forcex = force * (dx / r);
				forcey = force * (dy / r);

				fy += forcey; // adding force to total net force acting on body
				fx += forcex;
				
			}
		}
		
		ax = fx / planets[i]->get_mass(); // final values
		ay = fy / planets[i]->get_mass(); 
		
		velx = planets[i]->get_velx() + seconds * ax;
		vely = planets[i]->get_vely() + seconds * ay;
		
		planets[i]->set_velx(velx);
		planets[i]->set_vely(vely);
		
		x2 = (planets[i]->get_posx()) + velx * seconds;
		y2 = (planets[i]->get_posy()) + vely * seconds;
		
		planets[i]->set_x_y_pos(x2, y2);
	}
}

void Universe::printInfo(){ // prints info out to screen

	int i; // for loop

	cout << numplanets << endl; // print out number of planets 
	cout << r << endl; // print out radius
	for (i = 0; i < numplanets; i++){ // as long as there are planets left...
		cout << planets[i]->get_posx() << " " << planets[i]->get_posy() << " " << planets[i]->get_velx() << " " << planets[i]->get_vely() << " " << planets[i]->get_mass() << " " << planets[i]->get_filename() << endl;
	} // print out x pos, y pos, velx, vely, mass, and name
}

double Universe::get_r(){ return r; } // return the radius value

int Universe::get_numPlanets(){ return numplanets; } // return the number of planets

CelestialBody::CelestialBody(){ // default constructor, set everything to 0 and blank filename
	
	winsize = 0;
	xpos = 0;
	ypos = 0;
	xvel = 0;
	yvel = 0; 
	mass = 0;
	radius = 0;  
	filename = ""; 
}  

CelestialBody::CelestialBody(double x_pos, double y_pos, double x_vel, double y_vel, double m, string name, double rad, double window_size){

	double radx;
	double rady;
	
	xpos = x_pos; // updated values of xpos
	ypos = y_pos; // updated values of ypos
	xvel = x_vel; // updated values of xvel
	yvel = y_vel; // updated values of yvel
	
	mass = m; // update mass
	radius = rad; // update radius
	winsize = window_size; // update window size
	filename = name; // update filename

	radx = (winsize / 2) * (xpos / radius) + (winsize / 2); // update radius positioning
	rady = (winsize / 2) * (ypos / radius) + (winsize / 2);


	texture.loadFromFile(filename);  // load texture from image


	sprite.setTexture(texture);
	sprite.setPosition(radx, rady);
}

istream &operator >>(istream &in, CelestialBody &ci){

	double radx;
	double rady;
	
	in >> ci.xpos >> ci.ypos >> ci.xvel >> ci.yvel >> ci.mass >> ci.filename;
	
	radx = (ci.winsize / 2) * (ci.xpos / ci.radius) + (ci.winsize / 2);
	rady = (ci.winsize / 2) * (ci.ypos / ci.radius) + (ci.winsize / 2);

	ci.texture.loadFromFile(ci.filename);  // load texture from image
    
	ci.sprite.setTexture(ci.texture); // set texture, position
	ci.sprite.setPosition(radx, rady);


	return in; // return input
}

void CelestialBody::draw(sf::RenderTarget &target, sf::RenderStates states) const { target.draw(sprite, states); } // draw

CelestialBody::~CelestialBody(){} // destructor

double CelestialBody::get_posx(){ return xpos; } // return the xpos
double CelestialBody::get_posy(){ return ypos; } // return the ypos
double CelestialBody::get_velx(){ return xvel; } // return the xvel
double CelestialBody::get_vely(){ return yvel; } // return the yvel
double CelestialBody::get_mass(){ return mass; } // return the mass

string CelestialBody::get_filename(){ return filename; } // return the updated filename

void CelestialBody::set_radius(double r){ radius = r; } // update with the new radius value
void CelestialBody::set_window(double size){ winsize = size; } // update the updated value
void CelestialBody::set_velx(double vx){ xvel = vx; } // update xvel
void CelestialBody::set_vely(double vy){ yvel = vy; } // update yvel
void CelestialBody::set_x_y_pos(double x_input, double y_input){ // get ready to feed the positions as inputs to set new position
	
	double radx; // declare variables for setting x_y pos
	double rady;
	
	xpos = x_input; // xpos becomes your x_input
	ypos = y_input; // ypos becomes your y_input
	
	radx = (winsize / 2) * (xpos / radius) + (winsize / 2);  // calculate the xpos in tandem with the radius
	rady = (winsize / 2) * (-ypos / radius) + (winsize / 2); // calculate the ypos in tandem with the radius
	
	sprite.setPosition(sf::Vector2f(radx, rady)); // set the position according to the given values
}

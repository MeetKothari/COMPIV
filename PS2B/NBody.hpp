#ifndef NBODY_HPP
#define NBODY_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

using namespace std;


class CelestialBody :public sf::Drawable {
    
    private:
    
    double winsize; // for the window
    
    double xpos; // same as before
    double ypos;
    
    double xvel;
    double yvel;
    
    double mass;
    double radius;
    
    double display_x;
    double display_y;
    
    string filename;
    
    sf::Sprite sprite;
    sf::Texture texture;

public:
    //constructors
    CelestialBody(); // default
    CelestialBody(double x_pos, double y_pos, double x_vel, double y_vel, double m, string name, double radius, double winsize); // improved positoning
    ~CelestialBody(); // destructor

    friend std::istream& operator >>(std::istream& input, CelestialBody& ci); // istream
    friend std::ostream& operator <<(std::ostream& out, CelestialBody& co);   // ostream

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const; // draw!
    
    //accessor functions
    double get_posx(); // same as before
    double get_posy();
    
    double get_velx();
    double get_vely();
    
    double get_mass();
    string get_filename();
    
    //mutators
    void set_x_y_pos(double x_input, double y_input); // newly added mutator functions for everything 
    
    void set_velx(double vx); // velocity
    void set_vely(double vy); // ^^^^^^^^
    
    void set_radius(double radius); // radius
    void set_window(double size); // window
    
    void set_position(); // set pos

};

class Universe : public sf::Drawable { // newly defined Universe class, as per comments on ps2a
    
    public:
    
    Universe(); // basic constructor
    Universe(double radius, int window, int num_of_planets, istream &in); // default constructor
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const; // draw func for universe
    
    friend ostream &operator <<(std::ostream& out, const Universe& co); // overlad <<
    
    void step(double seconds); // take a time parameter (double seconds) and move the CelestialBody object given its internal velocity for that much time
    
    double get_r();
    int get_numPlanets();

    void printInfo();
   
private:
    
    double r;
    
    int numplanets;
    int winsize;
    
    vector <std::unique_ptr <CelestialBody>> planets;

};

#endif //NBODY_HPP
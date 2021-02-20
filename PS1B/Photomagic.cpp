#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "FibLFSR.h"

using namespace std;

void transform(sf::Image &image, FibLFSR *bit){ // transforms image using FibLFSR

	int x, y; // variable declaration

	int size1, size2; // for the x and y, respectively

	sf::Sprite input, output; // self-explanatory input and output

	sf::Texture texture_input, texture_output; // SFML textures

	sf::Color p; // p for pixel
	
	sf::Vector2u size = image.getSize();
	
	sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Input:"); // create an SFML window for the input
	
	texture_input.loadFromImage(image); // get the input image
	
	input.setTexture(texture_input);   //  use the texture from the image
	
	size1 = image.getSize().x; // get size, two variables for the x and y
	
	size2 = image.getSize().y; // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

	for (x = 0; x < size1; x++){ // make the input negative
		
		for (y = 0; y < size2; y++){
			
			p = image.getPixel(x, y); // each pixel will be XOR'ed, shifting each bit a total of eight times.
			
			p.r = p.r ^ bit->generate(8);
			
			p.g = p.g ^ bit->generate(8);
			
			p.b = p.b ^ bit->generate(8);
			
			image.setPixel(x, y, p); // set it after the changes
		}
	}

	sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Output"); // create the SFML output window, labelled 'Output'
	
	texture_output.loadFromImage(image);
	
	output.setTexture(texture_output);

	while (window1.isOpen() && window2.isOpen()){ // draw it out to the output window that was previously created
		
		sf::Event event;
		
		while (window1.pollEvent(event)){ if (event.type == sf::Event::Closed) window1.close(); } // close the windows if the event is done 
		
		while (window2.pollEvent(event)){ if (event.type == sf::Event::Closed) window2.close(); } // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		
		window1.clear();
		
		window1.draw(input); // get to drawing
		
		window1.display();
		
		window2.clear();
		
		window2.draw(output);
		
		window2.display();
	}
}

int main(int argc, char *argv[]){ // The main()  function  takes  three  command-line  arguments:  a  picture  filename,  and a binary password (the initial LFSR seed). It should display the transformed picture on the screen.

    sf::Image image; // define an image for use 
	
	argv[0] = "./PhotoMagic"; // first argument will be the named executeable
	
	FibLFSR bit(argv[3]); // third argument will be the intial seed
	
	if (!image.loadFromFile (argv[1])) exit(1); // if something goes wrong, exit
	
	transform(image, &bit); // fingers crossed
	
	if (!image.saveToFile(argv[2])) exit(1); // take the second argument, save the transformed file with that name, if not, exit
	
	return 0;
}

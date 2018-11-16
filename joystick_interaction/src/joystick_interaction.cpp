/**************Developed by Paul Mouraud 2018***************************
	
	Developed at Pontificia Universidad Javeriana Nov 2018 
	"Centro Tecnologico de Automatizacion Industrial" CTAI
		Perception For Industrial Robots Project
			Joystick data retrieve node


	Edited by: Nicolás Barrero	n.barrero@javeriana.edu.co
***********************************************************************/

#include <SFML/Graphics.hpp> //Include from SFML library
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <ros/ros.h>

#include <joystick_interaction/joystick_state.h> //Created msg.


int main(int argc, char* argv[]){
	ros::init(argc, argv, "joystick_data_updater"); // init ROS node
	ros::NodeHandle n;

	//Window Creation (necessary)developed
	sf::Window window(sf::VideoMode(10, 10), "Joystick Use");
	window.setVisible(false); //Hide the window
	sf::Event e;
	
	if(!sf::Joystick::isConnected(0)){
		ROS_ERROR("No Joystick found... Please verify it is plugged in");
		return 0;
	}
	ROS_INFO("Joystick is connected, beginning data retrieval");

	//Initialization of the publisher "joystick_state"
	ros::Publisher pub = n.advertise<joystick_interaction::joystick_state>("joystick_state", 100);
	//Initialization of a message "msg" of type joystick_state
	joystick_interaction::joystick_state msg;
	
	while(ros::ok()){

		//Each time there is an event
		while (window.pollEvent(e)){

			//If there is a change in joystick's state
			if (e.type == sf::Event::JoystickMoved){
				//Write to the topic axes' values
				msg.axis[0] = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
				msg.axis[1] = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
				msg.axis[2] = sf::Joystick::getAxisPosition(0, sf::Joystick::Z);
				msg.axis[3] = sf::Joystick::getAxisPosition(0, sf::Joystick::R);
				msg.axis[4] = sf::Joystick::getAxisPosition(0, sf::Joystick::PovX);
				msg.axis[5] = sf::Joystick::getAxisPosition(0, sf::Joystick::PovY);
			}
			//update buttons' data
			for (int i=0; i<12; i++){
				if (sf::Joystick::isButtonPressed(0, i)){
					//Filling the message with buttons' data.
					msg.buttons[i] = 1;
				}
				else
					msg.buttons[i]=0;
			}
		//Publish
		pub.publish(msg);
		}
	}
	return 0;
}

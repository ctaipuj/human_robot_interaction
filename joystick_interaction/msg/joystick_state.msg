#joystick_state message for the Logitech EXTREME3DPRO Joystick,
#which has 6 axis and 12 buttons

#Publication of the state of each axis
#Value between -100 and 100
float32[6] axis
#Button state
#True when pressed
bool[12] buttons

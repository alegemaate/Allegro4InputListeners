#include "mouseListener.h"

unsigned char mouseListener::mouse_button = 0;
unsigned char mouseListener::mouse_pressed = 0;
unsigned char mouseListener::mouse_released = 0;
unsigned char mouseListener::mouse_old = 0;

int mouseListener::mouse_z_change = 0;
int mouseListener::mouse_z_old = 0;

// Check those buttons!
void mouseListener::update(){
  for( int i = 0; i < MAX_MOUSE_BUTTONS; i++ ){
    // Clear old values
    mouse_pressed &= ~(1 << i);
    mouse_released &= ~(1 << i);

    // Down or not
    int check_state = ((mouse_b >> i) & 1);
    mouse_button = (mouse_button & ~(1 << i)) | (check_state << i);

    // Pressed since last tick?
    if( ((mouse_button >> i) & 1) != 0 && ((mouse_old >> i) & 1) == 0 )
      mouse_pressed |= 1 << i;

    // Released since last tick?
    if( ((mouse_button >> i) & 1) == 0 && ((mouse_old >> i) & 1) != 0 )
      mouse_released |= 1 << i;

    // Button changed
    if( ((mouse_button >> i) & 1) != ((mouse_old >> i) & 1))
      mouse_old ^= 1 << i;
  }

  // Update scroll wheel
  mouse_z_change = 0;
  if( mouse_z != mouse_z_old){
    mouse_z_change = mouse_z - mouse_z_old;
    mouse_z_old = mouse_z;

    //std::cout << "Z: changed by " << mouse_z_change << ". \n";
  }
}

/**
 * Mouse Listener
 *   Allan Legemaate
 * Listens for mouse buttons JUST pressed or JUST released
 *   since the last tick
 * 18/01/2017
**/

#include <iostream>
#include <allegro.h>

#ifndef MOUSELISTENER_H
#define MOUSELISTENER_H

#define MAX_MOUSE_BUTTONS 3

class mouseListener{
  public:
    mouseListener() {};
    virtual ~mouseListener() {};

    static void update();

    static unsigned char mouse_button;
    static unsigned char mouse_pressed;
    static unsigned char mouse_released;
    static int mouse_z_change;
  protected:

  private:
    static unsigned char mouse_old;
    static int mouse_z_old;
};

#endif // MOUSELISTENER_H

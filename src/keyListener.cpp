#include "keyListener.h"
#include <allegro.h>

bool keyListener::keyPressed[KL_KEY_MAX] = { false };
bool keyListener::keyReleased[KL_KEY_MAX] = { false };
bool keyListener::lastTicksKey[KL_KEY_MAX] = { false };

void keyListener::update(){
  for( int i = 0; i < KL_KEY_MAX; i++ ){
    /* Clear old values */
    keyPressed[i] = false;
    keyReleased[i] = false;

    /* Pressed since last tick? */
    if( (bool)key[i] && !lastTicksKey[i] )
      keyPressed[i] = true;

    /* Released since last tick? */
    if( !(bool)key[i] && lastTicksKey[i] )
      keyReleased[i] = true;

    /* Get new values from board */
    if( lastTicksKey[i] != (bool)key[i] )
      lastTicksKey[i] = key[i];
  }
}

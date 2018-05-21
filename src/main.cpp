/*
 * Allegro 4 Input Listener
 *  Example Program
 * Allan Legemaate
 * 18/05/2018
 */
#include <allegro.h>
#include <stdio.h>

#include "keyListener.h"
#include "mouseListener.h"

/* Buffer for double buffering */
BITMAP *buffer;

/* Message */
char key_message[50];
char mouse_message[50];

void draw(){
  /* Clear the screen to white */
  clear_to_color( buffer, makecol(255, 255, 255) );

  /* Write messages to screen */
  textprintf_ex( buffer, font, 10, 10, makecol(0,0,0), -1, "LAST KEYBOARD ACTION:" );
  textprintf_ex( buffer, font, 15, 30, makecol(0,0,0), -1, "%s", key_message );

  textprintf_ex( buffer, font, 10, 60, makecol(0,0,0), -1, "LAST MOUSE ACTION:" );
  textprintf_ex( buffer, font, 15, 80, makecol(0,0,0), -1, "%s", mouse_message );

  /* Draw buffer to screen */
  draw_sprite( screen, buffer, 0, 0 );
}

void update(){
  /* Update keylistener */
  keyListener::update();

  /* Update mouselistener */
  mouseListener::update();

  /* Check if something changed */
  /* Keyboard */
  for( int i = 0; i < KL_KEY_MAX; i++ ){
    if( keyListener::keyPressed[i] )
      sprintf( key_message, "Key: %d pressed!", i );
    if( keyListener::keyReleased[i] )
      sprintf( key_message, "Key: %d released!", i );
  }

  /* Mouse */
  for( int i = 0; i < MAX_MOUSE_BUTTONS; i++ ){
    if( mouseListener::mouse_pressed & i )
      sprintf( mouse_message, "Button: %d pressed!", i );
    if( mouseListener::mouse_released & i )
      sprintf( mouse_message, "Button: %d released!", i );
  }
}

int main(){
  /* Init allegro */
  if (allegro_init() != 0)
    return 1;

  /* Set up the keyboard handler */
  install_keyboard();

  /* Set a graphics mode sized 320x200 */
  if( set_gfx_mode( GFX_AUTODETECT_WINDOWED, 320, 200, 0, 0 ) != 0 ){
    if( set_gfx_mode( GFX_SAFE, 320, 200, 0, 0 ) != 0 ){
      set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
      allegro_message( "Unable to set any graphic mode\n%s\n", allegro_error );
      return 1;
    }
  }

  /* Set the color palette */
  set_palette( desktop_palette );

  /* Create buffer */
  buffer = create_bitmap( SCREEN_W, SCREEN_H );

  /* Draw and update */
  while( !key[KEY_ESC] ){
    draw();
    update();
  }

  /* Exit allegro */
  allegro_exit();

  /* Done! */
  return 0;
}
END_OF_MAIN()

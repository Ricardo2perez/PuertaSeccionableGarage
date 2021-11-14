// Bot.cpp
/*

Copyright (C) 2014-2019 Escornabot - http://escornabot.com

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
USA.

See LICENSE.txt for details

*/

#include "Bot.h"
#include "Escornabot.h"

//////////////////////////////////////////////////////////////////////

void Bot::init()
{

    // init engine
    ENGINE->init();


    // init button set
    #if USE_BUTTONS
    BUTTONS->init();
    #endif

    // early console
    Serial.begin(9600);
    Serial.println(FIRMWARE_VERSION);
    delay(100);

    // init bluetooth
    #if USE_BLUETOOTH
    BLUETOOTH->init();
    #endif
/*
    // init buzzer
    #if USE_BUZZER
    BUZZER.init();
    BUZZER.beep();
    #endif
*/
    #if USE_SIMPLE_LED
    SIMPLE_LED.init();
    #endif
/*
    #if USE_KEYPAD_LEDS
    KEYPAD_LEDS.init();
    #endif

    // restore last program
    #if USE_PERSISTENT_MEMORY
    PROGRAM->load();
    #endif
*/
    EVENTS->add(this);
}

//////////////////////////////////////////////////////////////////////

void Bot::loop()
{
    EVENTS->indicateTick(micros());

   if (!ENGINE->isExecuting()) delay(10);
}

//////////////////////////////////////////////////////////////////////

void Bot::buttonPressed(BUTTON button)
{
   
    #if USE_SIMPLE_LED
    SIMPLE_LED.setStatus(true);
    #endif
}

//////////////////////////////////////////////////////////////////////

void Bot::buttonReleased(BUTTON button)
{
    #if USE_SIMPLE_LED
    SIMPLE_LED.setStatus(false);
    #endif
/*
    if (ENGINE->isExecuting())
    {
        ENGINE->cancelExecution();
        return;
    }
*/
    switch (button)
    {
        case BUTTON_OC:
          //  _storeMove(MOVE_FORWARD);
            #if DEBUG
                Serial.println("Pulsado botón Abrir/cerrar");
            #endif
            break;

        case BUTTON_MOD_RF:
            #if DEBUG
                Serial.println("Pulsado botón Mod_RF");
            #endif
            //_storeMove(MOVE_RIGHT);
            break;

        case BUTTON_CL:
            #if DEBUG
                Serial.println("Pulsado botón CL");
            #endif
            //_storeMove(MOVE_BACKWARD);
            break;

        case BUTTON_PUSH_RF:
            #if DEBUG
                Serial.println("Pulsado botón Push_RF");
            #endif
            //_storeMove(MOVE_LEFT);
            break;

        case BUTTON_OVERLOAD:
            #if DEBUG
                Serial.println("Sobrecarga Activada");
            #endif
            //_go();
            break;

        case BUTTON_FOTOCEL:
            #if DEBUG
                Serial.println("Activada Fotocelula");
            #endif
          //  PROGRAM->clear();
            break;
    }
}

//////////////////////////////////////////////////////////////////////

void Bot::buttonLongReleased(BUTTON button)
{

    

    #if USE_SIMPLE_LED
    SIMPLE_LED.setStatus(false);
    #endif
/*
    if (ENGINE->isExecuting())
    {
        ENGINE->cancelExecution();
        return;
    }
*/

    switch (button)
    {
        case BUTTON_OC:
          //  _storeMove(MOVE_FORWARD);
            #if DEBUG
                Serial.println("Soltado botón Abrir/cerrar");
            #endif
            break;

        case BUTTON_MOD_RF:
            #if DEBUG
                Serial.println("Soltado botón Mod_RF");
            #endif
            //_storeMove(MOVE_RIGHT);
            break;

        case BUTTON_CL:
            #if DEBUG
                Serial.println("Soltado botón CL");
            #endif
            //_storeMove(MOVE_BACKWARD);
            break;

        case BUTTON_PUSH_RF:
            #if DEBUG
                Serial.println("Soltado botón Push_RF");
            #endif
            //_storeMove(MOVE_LEFT);
            break;

        case BUTTON_OVERLOAD:
            #if DEBUG
                Serial.println("Soltado Sobrecarga Activada");
            #endif
            //_go();
            break;

        case BUTTON_FOTOCEL:
            #if DEBUG
                Serial.println("Soltado Activada Fotocelula");
            #endif
          //  PROGRAM->clear();
            break;
    }
    
/*
    switch (button)
    {
        case BUTTON_RIGHT:
            _storeMove(MOVE_ALT_RIGHT);
            break;

        case BUTTON_DOWN:
            _storeMove(MOVE_PAUSE);
            break;

        case BUTTON_LEFT:
            _storeMove(MOVE_ALT_LEFT);
            break;

        case BUTTON_GO:
            _next_game_mode();
            break;
    }
  */
}

//////////////////////////////////////////////////////////////////////

void Bot::programFinished()
{
/*
    #if PROGRAM_RESET_ALWAYS
    PROGRAM->clear();
    #endif

    #if USE_BUZZER
    BUZZER.playRttl(PROGRAM_FINISHED_RTTL);
    #endif

    if (_game_mode == GAME_MODE_GRID_90 && !ENGINE->isAligned(90))
    {
        // advise next advance is expected to be a diagonal:
        #if USE_SIMPLE_LED
        SIMPLE_LED.setStatus(true);
        #elif USE_KEYPAD_LEDS
        KEYPAD_LEDS.setLed(BUTTON_RIGHT, true);
        KEYPAD_LEDS.setLed(BUTTON_LEFT, true);
        #endif
    }
*/
}

//////////////////////////////////////////////////////////////////////

void Bot::programAborted(uint8_t executed, uint8_t total)
{
  /*
    #if PROGRAM_RESET_ALWAYS
    PROGRAM->clear();
    #endif
*/
}

//////////////////////////////////////////////////////////////////////

void Bot::_go()
{
  
    
    int movement = MOVE(0);
    

        ENGINE->execute(movement);
        
    

}

//////////////////////////////////////////////////////////////////////

void Bot::_storeMove(MOVE move)
{
  /*
    if (PROGRAM->getMoveCount() < MOVE_LIMIT)
    {
        PROGRAM->addMove(move);
    }
    else
    {
        // memory is full
        _go();
    }
  */
}

//////////////////////////////////////////////////////////////////////

void Bot::_next_game_mode()
{
    // select the next game mode (2 modes currently available)
    ++_game_mode %= 2;

    /* switch (_game_mode)
    {
        case GAME_MODE_GRID_90:
            PROGRAM->setTurnDegrees(90);
            PROGRAM->setAltTurnDegrees(45);
            ENGINE->setSquareDiagonals(true);
            break;

        case GAME_MODE_GRID_60:
            PROGRAM->setTurnDegrees(60);
            PROGRAM->setAltTurnDegrees(120);
            ENGINE->setSquareDiagonals(false);
            break;
    }

    EVENTS->indicateGameModeSelected(_game_mode);
*/
}

//////////////////////////////////////////////////////////////////////

// EOF

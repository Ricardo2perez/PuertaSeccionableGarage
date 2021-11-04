// Configuration.h
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

#ifndef _CONFIGURATION_H
#define _CONFIGURATION_H


//////////////////////////////////////////////////////////////////////
///// general configuration
//////////////////////////////////////////////////////////////////////

// engine to use
#define ENGINE

// button set to use (analog input, digital input)
#define BUTTONS_DIGITAL

// outputs
#define OUTPUTS

// milliseconds after a button is considered as pressed
#define BUTTON_MIN_PRESSED 30

// milliseconds after a button is considered as long pressed
#define BUTTON_LONG_PRESSED 1000

// put to false to add movements to the program after its execution
#define PROGRAM_RESET_ALWAYS true

// store configuration and program within internal EEPROM
#define USE_PERSISTENT_MEMORY false

// milliseconds for the "pause" movement
#define PAUSE_MOVE_MILLIS 1000

// milliseconds delay before starting to move
#define DELAY_BEFORE_GO 500

// milliseconds to pause after every movement
#define AFTER_MOVEMENT_PAUSE 0

// buzzer
#define USE_BUZZER true
#define BUZZER_PIN 10
#define PROGRAM_FINISHED_RTTL RTTL_FIDO
#define TONE_FREQ_UP 2637
#define TONE_FREQ_RIGHT 4434
#define TONE_FREQ_DOWN 3520
#define TONE_FREQ_LEFT 2217


// simple led
#define USE_SIMPLE_LED false
#define SIMPLE_LED_PIN 6


//////////////////////////////////////////////////////////////////////
///// Engine setup
//////////////////////////////////////////////////////////////////////

#ifdef ENGINE

// Relay motor (digital outputs)
#define MOTOR_OPEN 12
#define MOTOR_CLOSE 11

#endif



//////////////////////////////////////////////////////////////////////
///// Button set digital
//////////////////////////////////////////////////////////////////////

#ifdef BUTTONS_DIGITAL

// Digital inputs in the Arduino
#define BS_DIGITAL_OC 3
#define BS_DIGITAL_MOD_RF 4
#define BS_DIGITAL_CL 8
#define BS_DIGITAL_PULS_RF 2
#define BS_DIGITAL_OVERLOAD A0
#define BS_DIGITAL_FOTOCEL 7

#endif // BUTTONS_DIGITAL


#ifdef OUTPUTS

// Relay motor (digital outputs)
#define LED_STATUS 6
#define LUZ_CORTESIA 13


#endif




//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////


#endif // _CONFIGURATION_H

// EOF

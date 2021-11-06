// Escornabot.h
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

#ifndef _ESCORNABOT_H
#define _ESCORNABOT_H

#define FIRMWARE_VERSION "v1.6.2"

#include <Arduino.h>
#include "Configuration.h"
#include "Enums.h"
//#include "MoveList.h"
//#include "Engine.h"
#include "ButtonSet.h"
#include "EventManager.h"



#if defined(BUTTONS_DIGITAL)

    // digital button set
    #include "ButtonSetDigital.h"
    const ButtonSetDigital::Config BS_CONFIG = {
        pin_button_oc: BS_DIGITAL_OC,
        pin_button_mod_rf: BS_DIGITAL_MOD_RF,
        pin_button_cl: BS_DIGITAL_CL,
        pin_button_push_rf: BS_DIGITAL_PULS_RF,
        pin_button_overload: BS_DIGITAL_OVERLOAD,
        pin_button_fotocel: BS_DIGITAL_FOTOCEL,
    };
    ButtonSetDigital BUTTONS_INSTANCE (&BS_CONFIG);
    ButtonSet* BUTTONS = (ButtonSet*) &BUTTONS_INSTANCE;
    #define USE_BUTTONS true


#endif // Button set

/*
#if defined(USE_BLUETOOTH)

    #ifndef BLUETOOTH_SERIAL
        #define BLUETOOTH_SERIAL Serial
    #endif

    #include "BluetoothInterface.h"
    const BluetoothInterface::Config BT_CONFIG = {
        serial: &(BLUETOOTH_SERIAL),
        bauds: BLUETOOTH_BAUDS,
    };
    BluetoothInterface BLUETOOTH_INSTANCE (&BT_CONFIG);
    BluetoothInterface* BLUETOOTH = &BLUETOOTH_INSTANCE;

#endif // Bluetooth

*/

/*
#if USE_BUZZER
    #include "Buzzer.h"
    Buzzer BUZZER = Buzzer(BUZZER_PIN);
#endif
*/
/*
#if USE_SIMPLE_LED
    #include "SimpleLed.h"
    SimpleLed SIMPLE_LED = SimpleLed(SIMPLE_LED_PIN);
#endif
*/
/*
#if USE_KEYPAD_LEDS
    #include "KeypadLeds.h"
    const KeypadLeds::Config KEYPAD_LEDS_CONFIG = {
        pin_led_up: KEYPAD_LED_PIN_UP,
        pin_led_right: KEYPAD_LED_PIN_RIGHT,
        pin_led_down: KEYPAD_LED_PIN_DOWN,
        pin_led_left: KEYPAD_LED_PIN_LEFT,
        pin_led_go: KEYPAD_LED_PIN_GO,
    };
    KeypadLeds KEYPAD_LEDS = KeypadLeds(&KEYPAD_LEDS_CONFIG);
#endif
*/
///// global vars

// event manager
EventManager EVENTS_INSTANCE;
EventManager* EVENTS = &EVENTS_INSTANCE;

/*
// program
MoveList PROGRAM_INSTANCE;
MoveList* PROGRAM = &PROGRAM_INSTANCE;
*/

#endif // _ESCORNABOT_H

// EOF

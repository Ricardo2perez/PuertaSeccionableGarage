// ButtonSetDigital.cpp
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

#include "ButtonSetDigital.h"
#include "Configuration.h"
#include <Arduino.h>

ButtonSetDigital::ButtonSetDigital(const Config* config)
{
    this->_config = config;

    for (int b = 0; b < 6; b++) _btn_state[b] = false;
}


void ButtonSetDigital::init()
{
    ButtonSet::init();

    // configure Arduino pins
    pinMode(_config->pin_button_oc, INPUT);
    pinMode(_config->pin_button_mod_rf, INPUT);
    pinMode(_config->pin_button_cl, INPUT);
    pinMode(_config->pin_button_push_rf, INPUT);
    pinMode(_config->pin_button_overload, INPUT);
    pinMode(_config->pin_button_fotocel, INPUT);
}


void ButtonSetDigital::scanButtons()
{
    bool state;

    state = (digitalRead(_config->pin_button_oc) == HIGH);
    if (state ^ isPressed(BUTTON_OC))
    {
        
            if (state) pressed(BUTTON_OC); else released(BUTTON_OC);
    }

    state = (digitalRead(_config->pin_button_mod_rf) == HIGH);
    if (state ^ isPressed(BUTTON_MOD_RF))
    {
            if (state) pressed(BUTTON_MOD_RF); else released(BUTTON_MOD_RF);
    }

    state = (digitalRead(_config->pin_button_cl) == HIGH);
    if (state ^ isPressed(BUTTON_CL))
    {
            if (state) pressed(BUTTON_CL); else released(BUTTON_CL);
    }

    state = (digitalRead(_config->pin_button_push_rf) == HIGH);
    if (state ^ isPressed(BUTTON_PUSH_RF))
    {
            if (state) pressed(BUTTON_PUSH_RF); else released(BUTTON_PUSH_RF);
    }

    state = (digitalRead(_config->pin_button_overload) == HIGH);
    if (state ^ isPressed(BUTTON_OVERLOAD))
    {
            if (state) pressed(BUTTON_OVERLOAD); else released(BUTTON_OVERLOAD);
    }

    state = (digitalRead(_config->pin_button_fotocel) == HIGH);
    if (state ^ isPressed(BUTTON_FOTOCEL))
    {
            if (state) pressed(BUTTON_FOTOCEL); else released(BUTTON_FOTOCEL);
    }
}

// EOF

// ButtonSetDigital.h
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

#ifndef _BUTTON_SET_DIGITAL_H
#define _BUTTON_SET_DIGITAL_H

#include "ButtonSet.h"

/**
 * \brief Implementation of a button set connected to 6 digital inputs.
 * \author @caligari
 */
class ButtonSetDigital : ButtonSet
{
public:

    typedef struct {
        uint8_t pin_button_oc;
        uint8_t pin_button_mod_rf;
        uint8_t pin_button_cl;
        uint8_t pin_button_push_rf;
        uint8_t pin_button_overload;
        uint8_t pin_button_fotocel;
    } Config;

    

    ButtonSetDigital(const Config* config);

    /**
     * Does the hardware initialization.
     */
    virtual void init();

    /**
     * Reads the buttons
     */
    virtual void scanButtons();

private:

    const Config* _config;

    bool _btn_state[6];
};


#endif // _BUTTON_SET_DIGITAL_H

// EOF

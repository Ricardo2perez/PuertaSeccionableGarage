// EngineSteppers.cpp
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

#include "EngineSteppers.h"
#include "EventManager.h"
#include <Arduino.h>

//////////////////////////////////////////////////////////////////////

const static uint8_t step_pattern[] = {
    B00001, B00011, B00010, B00110, B00100, B01100, B01000, B01001
};

//////////////////////////////////////////////////////////////////////

extern EventManager* EVENTS;

//////////////////////////////////////////////////////////////////////

EngineSteppers::EngineSteppers(const Config* cfg)
{
    _config = cfg;

    _movement_steps_o = 0;
    _movement_steps_c = 0;

    _pattern_index_left = 0;
    _pattern_index_right = 0;
}

//////////////////////////////////////////////////////////////////////

void EngineSteppers::init()
{
    pinMode(_config->motor_open, OUTPUT);
    pinMode(_config->motor_close, OUTPUT);
    
    // set coils in row
    _movement_steps_o = 8;
    _movement_steps_c = 8;

    EVENTS->add(this);
}

//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////

void EngineSteppers::moveStraight(float advance_units)
{
    _movement_steps_o = _config->line_steps * advance_units;
    _movement_steps_c = -_movement_steps_o;
}

//////////////////////////////////////////////////////////////////////

void EngineSteppers::_motorStepOpen()
{
    digitalWrite(_config->motor_close, 0);
    digitalWrite(_config->motor_open, 1);
}

//////////////////////////////////////////////////////////////////////

void EngineSteppers::_motorStepClose()
{
    digitalWrite(_config->motor_open, 0);
    digitalWrite(_config->motor_close, 1);
    
}

//////////////////////////////////////////////////////////////////////

void EngineSteppers::tick(uint32_t micros)
{
    if (!isExecuting()) return;

    if (_movement_steps_c == 0 && _movement_steps_o == 0)
    {
        // already executing a pause movement
       

        // deactivate Darlingtons
        _motorStepClose();
        _motorStepOpen();

        EVENTS->indicateMoveExecuted(_getCurrentMove());

        // prepare next movement
        _program_index++;
        _prepareMove();
        return;
    }

    if (_movement_steps_c != 0)
    {
        // left motor step
        int8_t delta = (_movement_steps_c > 0 ? 1 : -1);
        _motorStepClose();
        _pattern_index_left += delta + 8;
        _pattern_index_left %= 8;
        _movement_steps_c -= delta;
    }

    if (_movement_steps_o != 0)
    {
        // right motor step
        int8_t delta = (_movement_steps_o > 0 ? 1 : -1);
        _motorStepOpen();
        _pattern_index_right += delta + 8;
        _pattern_index_right %= 8;
        _movement_steps_o -= delta;
    }

    if (_is_cancelling)
    {
        _movement_steps_o = 0;
        _movement_steps_c = 0;
    }
    else
    {
        delayMicroseconds(1000000 / _config->steps_per_second);
    }
}

//////////////////////////////////////////////////////////////////////

// EOF

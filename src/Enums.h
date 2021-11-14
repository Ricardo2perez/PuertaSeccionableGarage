// Enums.h
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

#ifndef _ENUMS_H
#define _ENUMS_H

#include <stdint.h>

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
// states 
enum
{
    CLOSE = 0,
    CLOSE_TO_OPEN = 1,
    OPEN = 2,
    OPEN_TO_CLOSE = 3,
    INDETERMINATE = 4,

};
typedef uint8_t STATE;

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
// movement commands
enum
{
    MOVE_NONE = 0,
    MOVE_OPEN = 1,
    MOVE_CLOSE = 2,
  };
typedef uint8_t MOVE;

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

// point of view in order to execute the movements
enum
{
    POV_ESCORNABOT = 1,
    POV_CHILD = 2,
};
typedef uint8_t POV;

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

// buttons
enum
{
    BUTTON_NONE = 0,
    BUTTON_OC = 1,
    BUTTON_MOD_RF = 2,
    BUTTON_CL = 3,
    BUTTON_PUSH_RF = 4,
    BUTTON_OVERLOAD = 5,
    BUTTON_FOTOCEL = 6,
};
typedef uint8_t BUTTON;

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

// game modes
enum
{
    GAME_MODE_GRID_90 = 0, // squared grid (classical mode)
    GAME_MODE_GRID_60 = 1, // triangled grid
};
typedef uint8_t GAME_MODE;

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

#endif // _ENUMS_H

// EOF

#include <Arduino.h>
#include "Bot.h"



//////////////////////////////////////////////////////////////////////

// instance
Bot ESCORNABOT;

//////////////////////////////////////////////////////////////////////

void setup()
{
    ESCORNABOT.init();
}

//////////////////////////////////////////////////////////////////////

void loop()
{
    ESCORNABOT.loop();
}

//////////////////////////////////////////////////////////////////////


// EOF

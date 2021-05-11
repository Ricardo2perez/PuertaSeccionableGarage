/*
protocolo
 C _ _ P _ _ V _ _ _ _ Q _ _
 Byte
 0  C (Comando)
 1-2 Valor del Comando
 3 P (Parametro)
 4-5 Tipo de Parametro
 6 V (Value)
 7-10 Valor Del Parametro
 11 Q (Paridad)
 12-13 Valor de la paridad
*/

#include <Arduino.h>
#include "Protocolo.h"
#include "define.h"

/// <summary>
/// Constructor
/// </summary>
Protocolo::Protocolo() : _inputChar()
{
  _inComingPacketComplete = false;
  _incomingCounter=0;
  incomingPacket.commandID=0;
  incomingPacket.parameter=0;
  incomingPacket.value=0;
  incomingPacket.parity=0;
  newPacket = false;
}

/// <summary>
/// Begin using default settings:
///  - speed: 115200 baud
///  - nodeID: 0
/// </summary>
void Protocolo::begin()
{
  begin (DEFAULT_BAUDRATE);
}

/// <summary>
/// Begin using custom settings
/// </summary>
void Protocolo::begin(long speed)
{
  Serial.begin(speed);
}

/// <summary>
/// Send a single command
/// </summary>
void Protocolo::sendCommand(uint8_t commandID, uint8_t value)
{
  setCommandID(commandID);
  sendPacket(value);
}

/// <summary>
/// Send a single command, reuses commandID from previous packets
/// </summary>
void Protocolo::sendCommand(uint8_t value)
{
  sendPacket(value);
}

/// <summary>
/// Send a reply to a command
/// </summary>
void Protocolo::sendCommandReply(uint8_t commandID, uint8_t value)
{
  setCommandID(commandID);
  sendPacket(value);
}



/// <summary>
/// Send a single 8-bit data value (Arduino 'byte' type), reuses sensorID from previous packets
/// </summary>
void Protocolo::sendData(uint8_t value)
{
  sendPacket(value);
}

/// <summary>
/// Send a single 16-bit data value (Arduino 'int' type), reuses sensorID from previous packets
/// </summary>
void Protocolo::sendData(int16_t value)
{
  sendPacket(value);
}

/// <summary>
/// Send out the actual 8-bit data packet (called from other 'send' functions)
/// </summary>
void Protocolo::sendPacket(uint8_t& value)
{
  Serial.print("C");
  hexPrinting(_commandID);
  _parity= _commandID^_parameter^value;
  Serial.print("P");
  hexPrinting(_parameter);
  Serial.print("V");
  hexPrinting(value);
  Serial.print("Q");
  hexPrinting(_parity);
  Serial.println("");
}

/// <summary>
/// Send out the actual 16-bit data packet (called from other 'send' functions)
/// </summary>
void Protocolo::sendPacket(int16_t& value)
{
  _parity=_commandID^_parameter^value;
  Serial.print("C");
  hexPrinting(_commandID);   
  Serial.print("P");
  hexPrinting(_parameter);
  Serial.print("V");                                              
  hexPrinting(value);
  Serial.print("Q");
  hexPrinting(_parity);
  Serial.println("");
}


/// <summary>
/// Set commandID
/// </summary>
void Protocolo::setCommandID(uint8_t& commandID)
{
  _commandID=commandID;
}

/// <summary>
/// Set parameter
/// </summary>
void Protocolo::setParameter(uint8_t& parameter)
{
  _parameter=parameter;
}

/// <summary>
/// HexPrinting: helper function to print data with a constant field width (2 hex values)
/// </summary>
void Protocolo::hexPrinting(uint8_t& data)
{
  if(data<16) {
    Serial.print(0, HEX);
  }
  Serial.print(data, HEX);
}

/// <summary>
/// HexPrinting: helper function to print data with a constant field width (2 hex values)
/// </summary>
void Protocolo::hexPrinting(int16_t& data)
{
  if(data<4096 && data>0) {
    Serial.print(0, HEX);
  }
  if(data<256 && data>0) {
    Serial.print(0, HEX);
  }
  if(data<16 && data>0) {
    Serial.print(0, HEX);
  }
  Serial.print(uint16_t(data), HEX);              //casting to suppress FFFF for negative int values
}


/// <summary>
/// Set readSerialData
/// </summary>
boolean Protocolo::readSerialData()
{
  while (Serial.available() && _inputChar[_incomingCounter] != '\n' ) {
    _inputChar[_incomingCounter]=(char)Serial.read();
    

    #if DEBUG_SERIAL
    Serial.println();
    Serial.print("_incoming = ");
    Serial.print(_incomingCounter);
    Serial.print(" -> ");
    Serial.print(_inputChar[_incomingCounter]);
    #endif

    _incomingCounter++;
    // This checks for a minimum lenght (longer is also ok.. problem?)
    if (_incomingCounter == 12) {
      newPacket = true;
    }
  }
  

  //Flush buffer
  while (Serial.read() >= 0){}

  #if DEBUG_SERIAL
    Serial.println();
    Serial.print("Paquete Recibido : ");
    Serial.println(_inputChar);
    Serial.println("---------------------------");
    Serial.print("Caracteres de entrada = ");
    Serial.println(_incomingCounter);
  #endif


  if (_incomingCounter <= 2){
    #if DEBUG_SERIAL
      Serial.println();
      Serial.println("paquete");
    #endif
    _incomingCounter =0;
    incomingPacket.commandID = HELP;
    if (newPacket) {
    newPacket=false;
    return true;
  }
  }
 
  

  //   parseSerialData();
  // Does not work when parsing is called in the return statement
  _incomingCounter=0;
  return (parseSerialData());
}

/// <summary>
/// Set parseSerialData
/// </summary>
/// @todo: error handling: illegal values is now handled by char position (G2 -> 02, 2G -> 20, GG -> 00), requires hextodec reimplementation (when HEX_DEC_ERROR=0)
boolean Protocolo::parseSerialData()
{
  incomingPacket.value =hex_to_dec(_inputChar[7])*16 + hex_to_dec(_inputChar[8]);
  // casting error hex vs decimal (in if)
 
  incomingPacket.commandID = hex_to_dec(_inputChar[1])*16 + hex_to_dec(_inputChar[2]);

  incomingPacket.parameter = hex_to_dec(_inputChar[4])*16 + hex_to_dec(_inputChar[5]);

  
  //Serial.println(incomingPacket.commandID);
   _checkedParity = incomingPacket.commandID^incomingPacket.parameter^incomingPacket.value;
  
  incomingPacket.parity = hex_to_dec(_inputChar[10])*16 + hex_to_dec(_inputChar[11]);
  //printInfo();
  #if DEBUG_SERIAL
  Serial.println();
  Serial.print("Imprimo debug info");
  printInfo();
  #endif
  
  if (newPacket) {
    newPacket=false;
    return checkParity();
  }
  else {
    return false;
  }
}

/// <summary>
/// Check if all the field in the packet have acceptable value
/// @TODO: implement this
/// </summary>
boolean Protocolo::validatePacketFields()
{
  if (true){
    return true;
  }
  else{
    return false;
  }
}


/// <summary>
/// Convert HEX to Decimal
/// </summary>
#define HEX_DEC_ERROR 0
uint8_t Protocolo::hex_to_dec(uint8_t in)
{
  if(((in >= '0') && (in <= '9'))) return in-'0';
  in |= 0x20;
  if(((in >= 'a') && (in <= 'f'))) return in-'a' + 10;
  return HEX_DEC_ERROR;
}

/// <summary>
/// printInfo:
/// </summary>
void Protocolo::printInfo()
{
 
  
  Serial.print("CommandID ");
  Serial.println(incomingPacket.commandID,HEX);
  Serial.print("Parameter");
  Serial.println(incomingPacket.parameter,HEX);
  Serial.print("Value:  ");
  Serial.println(incomingPacket.value,HEX);
  Serial.print("Parity:   ");
  Serial.println(incomingPacket.parity,HEX);
  Serial.println("------------");
  Serial.print("Checked parity:   ");
  Serial.println(_checkedParity,HEX);
  Serial.println("------------");
}

/// <summary>
/// Check parity
/// </summary>
boolean Protocolo::checkParity()
{
  if (_checkedParity == incomingPacket.parity){
    #ifdef DEBUG_SERIAL
    Serial.println("Parity ok");
    Serial.println("----------------");
    #endif
    return true;
  }
  else{
    #ifdef DEBUG_SERIAL
    Serial.println("Parity wrong");
    #endif
    return false;
  }
}

/// <summary>
/// Get commandID
/// </summary>
uint8_t Protocolo::getCommandID()
{
  return incomingPacket.commandID;
}

/// <summary>
/// Get parameter
/// </summary>
uint8_t Protocolo::getParameter()
{
  return incomingPacket.parameter;
}

/// <summary>
/// Get getvalue
/// </summary>
uint8_t Protocolo::getvalue()
{
  return incomingPacket.value;
}

void Protocolo::getInfo()
{


  
  printInfo();
}
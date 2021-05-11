

#ifndef Protocolo_h
#define Protocolo_h
#include <Arduino.h>

class Protocolo
{
  public:
    Protocolo();

    void begin();
    void begin(long speed);

    void sendCommand(uint8_t commandID, uint8_t value);
    void sendCommand(uint8_t value);
    void sendCommandReply(uint8_t commandID, uint8_t value);

    void sendDataRequest(uint8_t sensorID, uint8_t value);
    void sendData(uint8_t sensorID, uint8_t value);
    void sendData(uint8_t sensorID, int16_t value);

    void sendData(uint8_t value);
    void sendData(int16_t value);

    void sendDataArrayRequest(uint8_t arrayID, uint8_t length);
    void sendDataArray(uint8_t *dataArray, uint8_t length);
    void getInfo();
    boolean readSerialData();
    boolean readSerialData2();
    uint8_t getCommandID();
    uint8_t getvalue();
    uint8_t getParameter();

  private:
    struct packet
    {
      uint8_t commandID;
      uint8_t parameter;
      uint16_t value;
      uint8_t parity;
    } incomingPacket, outgoingPacket;             //TODO: also use this struct to send packets? (todo underscore)

    uint8_t _commandID;
    uint8_t _parameter;
    uint16_t _value;
    uint8_t _parity;
    uint8_t _checkedParity;

    boolean _inComingPacketComplete;
    char _inputChar[20];
    uint8_t _incomingCounter;

    void sendPacket(uint8_t& value);
    void sendPacket(int16_t& value);
    void setPacketType(uint8_t type);
    void setCommandID(uint8_t& commandID);
    void setParameter(uint8_t& parameter);
    void hexPrinting(uint8_t& data);
    void hexPrinting(int16_t& data);
    uint8_t hex_to_dec(uint8_t in);
    boolean parseSerialData();
    void printInfo();
    boolean checkParity();
    boolean newPacket;
    boolean validatePacketFields();
};
#endif

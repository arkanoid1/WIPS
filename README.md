# WIPS
WIPS - Wow injector packet sniffer for (x86, x64 client)

#Dump format

```
struct MainHeader
{
  char signature[3]; // 'PKT'
  byte version[2]; // 0x01, 0x03
  byte snifferID; 
  uint build; 
  char language[4]; // Client locale: 'enGB', 'enUS', 'deDE', 'ruRU' and ect.
  byte sessionKey[40]; // all zero
  uint unixTime;
  uint tickCount;
  uint optionalHeaderLength; 
};
byte[optionalHeaderLength] optionalData;
```
```
struct ChunkHeader
{
  char direction[4]; // 'SMSG', 'CMSG'
  uint sessionID;
  uint tickCount;
  uint optionalDataLength;
  uint dataLength;
};
byte[optionalDataLength] optionalData;
byte[dataLength] data;
```

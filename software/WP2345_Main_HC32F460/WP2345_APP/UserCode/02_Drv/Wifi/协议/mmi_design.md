WIFI module MMI design
==

# MMI container
#### packet format
```
<`>[encoded payload]<\n>
```
#### remark
- `: 1 byte character, packet start mark
- encoded payload: SLIP encoded payload 
    - ```<\> -> <\><0x1>```
    - ```<`> -> <\><0x2>```
    - ```<\n> -> <\><0x3>```
- \n: 1 byte character, packet end mark

# MMI IOT payload design
## * p2p channel
#### packet format
```
<FP><name><\0>[RemoteClientID]<\0><type><ReqRespID><\0><PayloadType>[Payload]<crc8>
```
#### remark
- FP: 2 bytes characters
- RemoteClientID: string, represents remote ClientID
- type: p2p type, 1 byte character
    - q: request
    - p: response
    - m: message
- ReqRespID: if type is q or p , 4 bytes random string, used to match request and response. if type is m ReqRespID should be set to 0000.
- PayloadType: payload type
    - j: JSON
    - b: binary
    - x: xml
- Payload: payload
- crc8: 1 byte, CRC8 result from RemoteClientID to Payload

## Report channel
#### packet format
```
<FR><name><\0><PayloadType>[Payload]<crc8>
```
#### remark
- PayloadType: payload type
    - j: JSON
    - b: binary
- Payload: payload
- crc8: 1 byte, CRC8 result from RemoteClientID to Payload

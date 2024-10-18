
## 获取设备能力
### [Request]
```
{
    "td": "GetDeviceCap"
}
```
### [Response]
```
{
    "ret": "",
    "errno": ERR_NUMBER,
    "error": "",

    "name": ""，
    "type": "",
    "sc":
}
```
### [Parameters]
* td: GetDeviceCap
* ret:
    * ok: 成功
    * fail: 失败
    * errno: 错误号，只有ret=fail时需要
    * error: 具有可读性的错误信息, 只有ret=fail时需要, 可选
* name: 可以是SN
* type: 机器类型, 物联网服务注册设备类型时获得
* sc: 智能配网方式
    * 0 - SP
    * 1 - AP
    * 2 - SPA
### [Remark]
此请求用于IOT模块与从机通信，当IOT模块启动时会每一秒发送一次本协议重复获取设备相关信息，直到成功获取信息即停止发送。


### [Remark]
## 获取模块版本
###  [Request]
```
{
    "td": "GetWKVer",
}
```
### [Response]
```
{
    "ret": "",
    "errno": ERR_NUMBER,
    "error": "",

    "ver": ""
}
```
### [Parameters]
* td: GetWKVer
* ret:
    * ok: 成功
    * fail: 失败
* errno: 错误号，只有ret=fail时需要
    * 1 - GetVersion error
* error: 具有可读性的错误信息, 只有ret=fail时需要, 可选
* ver: 模块版本信息
### [Remark]


## 模块恢复出厂设置
###  [Request]
```
{
    "td": "FactoryReset",
    "RbtDelay": 
}
```
### [Response]
```
{
    "ret": "",
    "errno": ERR_NUMBER,
    "error": ""
}
```
### [Parameters]
* td: FactoryReset
* ret:
    * ok: 成功
    * fail: 失败
* errno: 错误号，只有ret=fail时需要
    * 1 - recv json format error
    * 2 - CFConfigReset() fail
    * 3 - CFTimerNew(restartTmrCb) failed
* error: 具有可读性的错误信息, 只有ret=fail时需要, 可选
* RbtDelay: 收到命令后多长时间重启，单位毫秒; 可选参数，若不填则默认3s
### [Remark]


## 设置WIFI配置信息
###  [Request]
```
{
    "td": "SetWifiCfg",
    "s": "",
    "p": ""
}
```
### [Response]
```
{
    "ret": "",
    "errno": ERR_NUMBER,
    "error": ""
}
```
### [Parameters]
* td: SetWifiCfg
* ret:
    * ok: 成功
    * fail: 失败
* errno: 错误号，只有ret=fail时需要
    * 1 - recv json format error
    * 2 - CFConfigSave() fail
    * 3 - CFNetWifiStaConnect() fail
* error: 具有可读性的错误信息, 只有ret=fail时需要, 可选
* s: WIFI ssid
* p: WIFI passphrase
### [Remark]


## 开始配网
###  [Request]
```
{
    "td": "StartWifiConfig",
    "sc": 
}
```
### [Response]
```
{
    "ret": "",
    "errno": ERR_NUMBER,
    "error": ""
}
```
### [Parameters]
* td: StartWifiConfig
* ret:
    * ok: 成功
    * fail: 失败
* errno: 错误号，只有ret=fail时需要
    * 1 - recv json format error
    * 2 - clearWifiCfg() failed
    * 3 - doWifiConfig() failed
* error: 具有可读性的错误信息, 只有ret=fail时需要, 可选
* sc: 智能配网方式, 可选, 默认为DeviceCap返回的配网方式.
    * 0 - SP
    * 1 - AP
    * 2 - SPA
### [Remark]


## 获取网络信息
###  [Request]
```
{
    "td": "GetNetInfo"
}
```
### [Response]
```
{
    "ret": "",
    "errno": ERR_NUMBER,
    "error": "",

    "s": "",
    "p": "",
    "wi": "",
    "wm": ""
}
```
### [Parameters]
* td: FactoryReset
* ret:
    * ok: 成功
    * fail: 失败
* errno: 错误号，只有ret=fail时需要
    * 1 - recv json format error
* error: 具有可读性的错误信息, 只有ret=fail时需要, 可选
* s: WIFI ssid
* p: WIFI passphrase
* wi: WIFI IP address
* wm: WIFI chipset MAC address
### [Remark]


## 获取系统信息
###  [Request]
```
{
    "td": "GetSysInfo"
}
```
### [Response]
```
{
    "ret": "",
    "errno": ERR_NUMBER,
    "error": "",

    "am": "",
    "lm": "",
    "t": ""
}
```
### [Parameters]
* td: FactoryReset
* ret:
    * ok: 成功
    * fail: 失败
* errno: 错误号，只有ret=fail时需要
    * 1 - recv json format error
* error: 具有可读性的错误信息, 只有ret=fail时需要, 可选
* am: all memory in bytes
* lm: memory available in bytes
* t: seconds since boot
### [Remark]


## 获取WIFI模块当前状态		(FR)
###  [Request]
```
{
    "td": "GetWIFIStat"
}
```
### [Response]
```
{
    "ret": "",
    "errno": ERR_NUMBER,
    "error": "",

    "st": "",
    "s": "",
    "p": ""
}
```
### [Parameters]
* td: GetWIFIStat
* ret:
    * ok: 成功
    * fail: 失败
* errno: 错误号，只有ret=fail时需要
    * 1 - CFJsonObjectGet(wifiCfg, WIFI) fail
* error: 具有可读性的错误信息, 只有ret=fail时需要, 可选
* st: WIFI当前状态  (i:idle s:smartConfig c:connecting o:connected a:ap)
* s: ssid  (没有网络配置即为NULL)
* p: passphrase  (没有网络配置即为NULL)
### [Remark]


## 获取IOT Server当前状态		(FR)
###  [Request]
```
{
    "td": "GetIOTConnStatus"
}
```
### [Response]
```
{
    "ret": "",
    "errno": ERR_NUMBER,
    "error": "",

    "on": 1,
    "conn": ,
    "ip": ""
}
```
### [Parameters]
* td: GetIOTConnStatus
* ret:
    * ok: 成功
    * fail: 失败
* errno: 错误号，只有ret=fail时需要
    * 1 - recv json format error
* error: 具有可读性的错误信息, 只有ret=fail时需要, 可选
* on: 1  
* conn: IOT服务连接状态  (0：DISCONN 1：CONNECTING 2：CONNECTED)
* ip: 当前连接的IOT服务器的IP地址
### [Remark]


## 校准时间
### [Request]
```
{
    "td": "SetTime",
    "ts": ,
    "tsInSec": 
}
```
### [Response]
```
{
    "ret": "",
    "errno": ERR_NUMBER,
    "error": ""
}
```
### [Parameters]
* ts: A number representing the milliseconds elapsed between 1 January 1970 00:00:00 UTC and the given date.
* tsInSec: A number representing the seconds elapsed between 1 January 1970 00:00:00 UTC and the given date.
* ret:
    * ok: 成功
    * fail: 失败
* errno: 错误号，只有ret=fail时需要
* error: 具有可读性的错误信息, 只有ret=fail时需要, 可选

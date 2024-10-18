
## 获取模块版本			(FP  Device->WIFI  RemoteClientID为空)
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


## 获取模块帐号信息
###  [Request]
```
{
    "td": "GetCredential",
}
```
### [Response]
```
{
    "ret": "",
    "errno": ERR_NUMBER,
    "error": "",

    "did": "",
    "password": "",
    "lb": ""
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
* did: 设备did
* password: 设备密码
* lb: 设备的接入域名，国内为mq.ecouser.net, 国际为 mq-ww.ecouser.net
### [Remark]

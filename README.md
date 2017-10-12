## 依赖安装

* 操作系统：centos 7
* node版本：5.1.1
* npm版本：3.8.6

安装`node-gyp`、`gcc`、`g++`。

```bash
npm install -g node-gyp@3.5.0
yum install -y gcc
yum install -y gcc-c++
```

## 安装

```bash
npm install node-checksum
```

## 使用

```js
var checksum = require('node-checksum');
var buffer = Buffer.from('hello');
var bodyChecksum = checksum.cal(buffer, 4);  // -53717
```
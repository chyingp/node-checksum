function cal (buf, size) {
    var cksum = 0, start = 0;
    while (size > 1) {
        cksum += buf.readUInt16LE(start);
        start += 2;
        size -= 2;
    }
    if (size) {
        cksum += buf.readUInt8LE(start);
    }
    while (cksum >> 16)
        cksum = (cksum >> 16) + (cksum & 0xffff);
    return ~cksum;    
};

exports.cal = cal;

// var buff = Buffer.from([1, 2, 3, 4]);
// var ret = cal(buff, 4);
// console.log(ret); // -1541

// var buff = Buffer.from([1, 2, 3, 4, 5, 6]);
// var ret = cal(buff, 6);
// console.log(ret); // -3082
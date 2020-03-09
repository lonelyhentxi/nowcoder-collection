// [二进制转换](https://www.nowcoder.com/practice/2c7f25d532aa4e20b67af9d3c93dc65f)

function valueAtBit(num, bit) {
    const bits = num.toString(2);
    return Number(bits[bits.length - bit]);
}

const assert = require('assert');
assert.deepEqual(valueAtBit(128, 8), 1);
// [二进制转换](https://www.nowcoder.com/practice/4123561150114d119ba41f28219a454f)

function base10(str) {
    return Number.prototype.toString.call(parseInt(str,2),10);
}

const assert = require('assert');
assert.deepEqual(base10('11000000'), 192);
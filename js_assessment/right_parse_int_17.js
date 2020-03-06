// [正确的使用 parseInt](https://www.nowcoder.com/practice/a14f83473c384abba1bb51017d0dbd42)

function parse2Int(num) {
    return parseInt(num, 10);
}

const assert = require('assert');
assert.deepEqual(parse2Int('12'), 12);
assert.deepEqual(parse2Int('12px'), 12);
assert.deepEqual(parse2Int('0x12'), 0);
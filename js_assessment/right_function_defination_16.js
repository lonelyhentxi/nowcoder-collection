// [正确的函数定义](https://www.nowcoder.com/practice/a5de760a7cf24c0e890eb02eed34bc02)

function functions(flag) {
    let getValue;
    if (flag) {
        getValue = function() { return 'a'; };
    } else {
        getValue = function() { return 'b'; };
    }
    return getValue();
}

const assert = require('assert');
assert.deepEqual(functions(true), 'a');
assert.deepEqual(functions(false), 'b');
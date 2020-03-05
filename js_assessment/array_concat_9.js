// [数组合并](https://www.nowcoder.com/practice/ba9ee11affbd44539a4104d7f098f06b)

function concat(arr1, arr2) {
    return [...arr1, ...arr2];
}

const assert = require('assert');
const src1 = [1, 2, 3, 4];
const src2 = ['a','b','c','1'];
const tar = concat(src1, src2);
assert.deepEqual(tar,[1, 2, 3, 4, 'a', 'b', 'c', 1]);
assert(tar!=src1);
assert(tar!=src2);
// [添加元素](https://www.nowcoder.com/practice/941bcfa5b87940869fda681c1597fd3a)

function insert(arr, item, index) {
    return [...arr.slice(0, index),item, ...arr.slice(index, arr.length)];
}

const assert = require('assert');
const src = [1, 2, 3, 4];
const tar = insert(src, 'z', 2);
assert.deepEqual(tar,[1, 2, 'z', 3, 4]);
assert(tar!=src);
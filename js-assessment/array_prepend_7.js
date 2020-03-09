// [添加元素](https://www.nowcoder.com/practice/93994cb28b1c4ec5ad7da4f9c33ebfbe)

function prepend(arr, item) {
    return [item, ...arr];
}

const assert = require('assert');
const src = [1, 2, 3, 4];
const tar = prepend(src, 10);
assert.deepEqual(tar,[10, 1, 2, 3, 4]);
assert(tar!=src);
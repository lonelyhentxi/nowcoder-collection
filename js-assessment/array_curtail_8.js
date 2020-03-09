// [删除数组第一个元素](https://www.nowcoder.com/practice/0323822699da497b8822898e90025882)

function curtail(arr) {
    return arr.slice(1, arr.length);
}


const assert = require('assert');
const src = [1, 2, 3, 4];
const tar = curtail(src);
assert.deepEqual(tar,[2, 3, 4]);
assert(tar!=src);
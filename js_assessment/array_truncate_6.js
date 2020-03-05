// [删除数组最后一个元素](https://www.nowcoder.com/practice/df4b0b7a459447538351c4c7008b34e7)

function truncate(arr) {
    return arr.slice(0, Math.max(0, arr.length-1));
}

const assert = require('assert');
const src = [1, 2, 3, 4];
const tar = truncate(src);
assert.deepEqual(tar,[1, 2, 3]);
assert(tar!=src);
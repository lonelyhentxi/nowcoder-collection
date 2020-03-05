// [添加元素](https://www.nowcoder.com/practice/3c7905cea3264ddaac4bf637ab3a19f9)

function append(arr, item) {
    const res = [];
    res.splice(0, 0, ...arr, item);
    return res;
}

const assert = require('assert');
const src = [1, 2, 3, 4];
const tar = append(src, 10);
assert.deepEqual(tar,[1, 2, 3, 4, 10]);
assert(tar!=src);
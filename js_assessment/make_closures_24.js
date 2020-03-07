// [使用闭包](https://www.nowcoder.com/practice/578026cd24e3446bbf27fe565473dc26)

function makeClosures(arr, fn) {
    return arr.map(x=> () => fn(x));
}

const assert = require('assert');
const src = [1, 2, 3];
const fn = (x) => x*x;
const tar = makeClosures(src, fn);
assert.deepEqual(tar.map(x=>x()), src.map(x=>fn(x)));
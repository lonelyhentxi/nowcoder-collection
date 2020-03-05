// [求二次方](https://www.nowcoder.com/practice/b7a8647e33d84f5c88acdd7c81a85fdf)

function square(arr) {
    return arr.map(v=>v*v);
}

const assert = require('assert');
const src = [1, 2, 3, 4];
const tar = square(src);
assert.deepEqual(tar, [1, 4, 9, 16]);
assert(src!=tar);
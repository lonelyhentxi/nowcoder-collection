// [计数](https://www.nowcoder.com/practice/628339bd8e6e440590ad86caa7ac6849)

function count(arr, item) {
    return arr.reduce((counter, curr) => counter + (curr===item?1:0), 0);
}

const assert = require('assert');
assert.equal(count([1, 2, 4, 4, 3, 4, 3], 4), 3);
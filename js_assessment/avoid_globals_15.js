// [避免全局变量](https://www.nowcoder.com/practice/e362110c727347048f350bd90af31c62)

function globals() {
    const myObject = {
      name : 'Jory'
    };

    return myObject;
}

const assert = require('assert');
assert.deepEqual(globals(), {name : 'Jory'});
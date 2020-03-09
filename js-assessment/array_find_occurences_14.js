// [查找元素位置](https://www.nowcoder.com/practice/0a9af9cb20c34babb6232126e019c74d)

function findAllOccurrences(arr, target) {
    const res = [];
    arr.forEach((e,i)=>{
        if(e===target) {
            res.push(i);
        }
    });
    return res;
}

const assert = require('assert');
const src = ['a','b','c','d','e','f','a','b','c'];
const tar = findAllOccurrences(src, 'a');
assert.deepEqual(tar, [0, 6]);
assert(src!=tar);
// [查找重复元素](https://www.nowcoder.com/practice/871a468deecf453589ea261835d6b78b)

function duplicates(arr) {
    const exists = new Map();
    arr.forEach( elem => {
        const v = exists.get(elem);
        if(v==null) {
            exists.set(elem, 1);
        } else {
            exists.set(elem, v+1);
        }
    });
    const res = [];
    for(const [k,v] of exists.entries()) {
        if(v>1) {
            res.push(k);
        }
    }
    return res;
}

const assert = require('assert');
const src = [1, 2, 4, 4, 3, 3, 1, 5, 3];
const tar = duplicates(src);
assert.ok(new Set(tar), new Set([1, 3, 4]));
assert(src!=tar);
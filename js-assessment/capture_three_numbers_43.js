// [获取指定字符串](https://www.nowcoder.com/practice/4ec56ad04a9a4402a01e50a390a8060a)

function captureThreeNumbers(str) {
    const allMatches = str.match(/\d{3}/g);
    return allMatches==null?false:allMatches[0];
}


const assert = require('assert');
assert.deepEqual(captureThreeNumbers('9876543'), '987');
// [查找数组元素位置](https://www.nowcoder.com/practice/e7835a8113dd48afb15f77ef8d1dcb1d)

function indexOf(arr, item) {
    for(let i=0; i<arr.length; i=i+1) {
        const elem = arr[i];
        if(elem===item) {
            return i;
        }
    }
    return -1;
}
// [函数的上下文](https://www.nowcoder.com/practice/5e97b94794bd438f893137b2d3b28a6a)

function speak(fn, obj) {
    return fn.call(obj);
}
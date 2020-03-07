// [函数传参](https://www.nowcoder.com/practice/80365a2685144559817e3d5e0c27f3a8)

function argsAsArray(fn, arr) {
    return fn(...arr);
}

// or

function anotherAsArray(fn, arr) {
    return fn.apply(this, arr);
}
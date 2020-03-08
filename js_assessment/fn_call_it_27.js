// [使用 apply 调用函数](https://www.nowcoder.com/practice/d47b482e7148497582c7a995df51f393)

function callIt(fn) {
    const [_, ...trueArgs] = arguments;
    return fn.apply(this, trueArgs);
}
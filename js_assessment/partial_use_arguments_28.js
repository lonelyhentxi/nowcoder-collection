// [二次封装函数](https://www.nowcoder.com/practice/694afeb930f74392bda01a815219d81b)

function partialUsingArguments(fn) {
    return (...args2) => fn(...Array.prototype.slice.call(arguments, 1, arguments.length),...args2);
}
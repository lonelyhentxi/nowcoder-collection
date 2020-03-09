// [改变上下文](https://www.nowcoder.com/practice/dfcc28bf243642b795eaf5a2a621acc5)

function alterContext(fn, obj) {
    return fn.call(obj);
}
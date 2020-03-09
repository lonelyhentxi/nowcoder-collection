// [使用 arguments](https://www.nowcoder.com/practice/df84fa320cbe49d3b4a17516974b1136)

function useArguments() {
    return Array.prototype.reduce.call(arguments, (s,x)=>s+x, 0);
}
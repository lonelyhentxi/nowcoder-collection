// [判断是否符合 USD 格式](https://www.nowcoder.com/practice/667dd00250d04d06989ed1b69102c9ab)

function isUSD(str) {
    return /^\$\d{1,3}(,\d{3})*(\.\d{2})?$/.test(str);
}
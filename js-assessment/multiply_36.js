// [乘法](https://www.nowcoder.com/practice/6429776e4630435cbc3eeb36bdf41f83)

function multiply(a, b) {
    const stra = a.toString(10).split('.')[1] || '';
    const strb = b.toString(10).split('.')[1] || '';
    const fix = stra.length + strb.length;
    return (a * b).toFixed(fix);
}
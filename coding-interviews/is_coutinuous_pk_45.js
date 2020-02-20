// [扑克牌顺子](https://www.nowcoder.com/practice/762836f4d43d43ca9deb273b3de8e1f4)

function IsContinuous(numbers)
{
    if(numbers.length==0) {
        return false;
    }
    let min = Number.MAX_SAFE_INTEGER;
    let max = Number.MIN_SAFE_INTEGER;
    const counter = new Array(14).fill(0);
    for(const n of numbers) {
        if(n!=0) {
            min = Math.min(n, min);
            max = Math.max(n, max);
        }
        counter[n] ++;
    }
    let blanks = 0;
    for(let i=min;i<=max;i++) {
        if(counter[i]>1) {
            return false;
        } else if(counter[i]==0) {
            blanks += 1;
        }
    }
    return counter[0]>=blanks;
}
module.exports = {
    IsContinuous : IsContinuous
};
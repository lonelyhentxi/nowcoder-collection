// [栈的压入、弹出序列](https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106)

function IsPopOrder(pushV, popV)
{
    const N = pushV.length;
    const stack = [];
    let j = 0;
    for(const x of pushV) {
        stack.push(x);
        while(stack.length && j < N && stack[stack.length-1] == popV[j] ){
            stack.pop();
            j++;
        }
    }
    return j==N;
}
module.exports = {
    IsPopOrder : IsPopOrder
};
// [包含min函数的栈](https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49)

const elemStack = [];
const stateStack = [];

function push(node)
{
    elemStack.push(node);
    let currentMin = node;
    if(stateStack.length>0 && node > stateStack[stateStack.length-1]) {
        currentMin = stateStack[stateStack.length-1]
    }
    stateStack.push(currentMin);
}
function pop()
{
    stateStack.pop();
    return elemStack.pop();
}
function top()
{
    return elemStack[elemStack.length-1];
}
function min()
{
    return stateStack[stateStack.length-1];
}
module.exports = {
    push : push,
    pop : pop,
    top : top,
    min : min
};
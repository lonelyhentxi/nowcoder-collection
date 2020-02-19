// [翻转单词顺序列](https://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3)

function ReverseSentence(str)
{
    const fragments = str.split(' ');
    fragments.reverse();
    return fragments.join(' ');
}
module.exports = {
    ReverseSentence : ReverseSentence
};
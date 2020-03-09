// [检查重复字符串](https://www.nowcoder.com/practice/5ef31f11adf64d9fb18d74860e9ab873)

function containsRepeatingLetter(str) {
    return /([a-zA-Z])\1/.test(str);
}
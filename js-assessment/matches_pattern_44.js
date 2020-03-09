// [判断是否符合指定格式](https://www.nowcoder.com/practice/eb86f08c478749868a01861f5ddad28b)

function matchesPattern(str) {
    return /^\d{3}-\d{3}-\d{4}$/.test(str);
}
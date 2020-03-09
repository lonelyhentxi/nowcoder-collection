// [判断是否以元音字母结尾](https://www.nowcoder.com/practice/c141ec7458f244a1ba1bb334c71e0f27)

function endsWithVowel(str) {
    return /[aeiouAEIOU]$/.test(str);
}
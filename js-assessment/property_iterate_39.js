// [属性遍历](https://www.nowcoder.com/practice/0158a4f165154f2eaf27d1907aa55e57)

function iterate(obj) {
    return Object.getOwnPropertyNames(obj).map(s=> `${s}: ${obj[s]}`);
}
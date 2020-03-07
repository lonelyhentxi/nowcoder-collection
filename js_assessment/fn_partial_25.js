// [二次封装函数](https://www.nowcoder.com/practice/fb2d46b99947455a897f2e9fe2268355)

function partial(fn, str1, str2) {
    return (str3) => fn(str1, str2, str3);
}
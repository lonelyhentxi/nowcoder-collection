// [柯里化](https://www.nowcoder.com/practice/bb78d69986794470969674a8b504ac00)

function curryIt(fn) {
    return (x) => (y) => (z) => fn(x,y,z);
}
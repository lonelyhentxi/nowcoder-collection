// [二进制转换](https://www.nowcoder.com/practice/7b74386695cc48349af37196f45e62a8)

function convertToBinary(num) {
    const s = Number.prototype.toString.call(num,2);
    if(s.length<8) {
        return '0'.repeat(8-s.length) + s;
    }
    return s;
}
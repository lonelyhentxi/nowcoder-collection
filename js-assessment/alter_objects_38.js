// [批量改变对象的属性](https://www.nowcoder.com/practice/4f7d25a30eb1463cbf1daac39ec04f8d)

function alterObjects(constructor, greeting) {
    constructor.prototype.greeting = greeting;
}
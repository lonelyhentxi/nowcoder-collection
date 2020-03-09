// [模块](https://www.nowcoder.com/practice/48e53feaabe94506a61300edadb5496d)

function createModuleWithPrototype(str1, str2) {
    function Obj() {
        this.greeting = str1;
        this.name = str2;
    }
    Obj.prototype.sayIt = function() { return `${this.greeting}, ${this.name}`; };
    return new Obj();
}

function createModuleWithLiterals(str1, str2) {
    return {
        greeting: str1, 
        name: str2, 
        sayIt: function() { return `${this.greeting}, ${this.name}`;  };
    };
}
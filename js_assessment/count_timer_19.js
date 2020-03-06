// [计时器](https://www.nowcoder.com/practice/72c661d926494bd8a50608506915268c)

function count(start, end) {
    console.log(start++);
    const timer = setInterval(()=>{
        if(start <= end) {
            console.log(start++);
        } else {
            clearInterval(timer);
        }
    });
    return {
        cancel: () => {
            clearInterval(timer)
        }
    };
}
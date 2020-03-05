//[数组求和](https://www.nowcoder.com/practice/cc3ce199461c4c4cb8f63db61d7eba30)

function sum(arr) {
    let sum_value=0;
    for(const elem of arr){
        sum_value += elem;
    }
    return sum_value;
}
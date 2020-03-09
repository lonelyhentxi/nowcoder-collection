//[移除数组中的元素](https://www.nowcoder.com/practice/edbc7496a36e433c89d298b9256af856)
function remove(arr, item) {
    const result=[];
    for(const elem of arr){
        if(elem!==item){
            result.push(elem);
        }
    }
    return result;

}
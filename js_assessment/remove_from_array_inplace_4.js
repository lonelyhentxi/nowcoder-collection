//[移除数组中的元素](https://www.nowcoder.com/practice/a93dd26ebb8c425d844acc17bcce9411)

function removeIndex(arr, index){
    if(index<0 || index>=arr.length){
        return;
    }
    for(let i=index+1;i<arr.length;i=i+1) {
        arr[i-1] = arr[i];
    }
    arr.pop();
}

function removeWithoutCopy(arr, item) {
    for(let i=0;i<arr.length;i=i+1){
        while(item===arr[i]){
            removeIndex(arr,i);
        }
    }
    return arr;

}

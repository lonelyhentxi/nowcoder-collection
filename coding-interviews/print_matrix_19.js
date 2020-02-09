// [顺时针打印矩阵](https://www.nowcoder.com/practice/9b4c81a02cd34f76be2659fa0d54342a)

function printMatrix(matrix)
{
    const res = [];
    if(matrix.length<=0) {
        return res;
    }
    const rows = matrix.length;
    if(matrix[0].length<=0) {
        return res;
    }
    const cols = matrix[0].length;
    let rs = 0;
    let re = rows - 1;
    let cs = 0;
    let ce = cols - 1;
    while(true) {
        if(rs>re) {
            break;
        }
        for(let c=cs;c<=ce;c++) {
            res.push(matrix[rs][c]);
        }
        rs += 1;
        if(cs>ce) {
            break;
        }
        for(let r=rs;r<=re;r++) {
            res.push(matrix[r][ce]);
        }
        ce -= 1;
        if(rs>re) {
            break;
        }
        for(let c=ce;c>=cs;c--) {
            res.push(matrix[re][c]);
        }
        re -= 1;
        if(cs>ce) {
            break;
        }
        for(let r=re;r>=rs;r--) {
            res.push(matrix[r][cs]);
        }
        cs += 1;
    }
    return res;
}
module.exports = {
    printMatrix : printMatrix
};
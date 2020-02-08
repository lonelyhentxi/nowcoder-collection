// [树的子结构](https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88)

/* function TreeNode(x) {
    this.val = x;
    this.left = null;
    this.right = null;
} */
function HasSubtree(pRoot1, pRoot2)
{
    if(pRoot2==null || pRoot1==null) {
        return false;
    }
    return same_struct(pRoot1, pRoot2) || same_struct(pRoot1.left, pRoot2) || same_struct(pRoot1.right, pRoot2);
}

function same_struct(root1, root2) {
    if(root2!=null) {
        if(root1==null) {
            return false;
        }
        if(root1.val!=root2.val) {
            return false;
        }
        return same_struct(root1.left, root2.left) &&  same_struct(root1.right, root2.right);
    }
    else {
        return true;
    }
}
module.exports = {
    HasSubtree : HasSubtree
};
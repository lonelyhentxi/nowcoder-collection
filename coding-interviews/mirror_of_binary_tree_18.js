// [二叉树的镜像](https://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011)

/* function TreeNode(x) {
    this.val = x;
    this.left = null;
    this.right = null;
} */
function Mirror(root)
{
    if(root!=null)
    {
        const newLeft = Mirror(root.left);
        const newRight = Mirror(root.right);
        root.left = newRight;
        root.right = newLeft;
    }
    return root;
}


module.exports = {
    Mirror : Mirror
};
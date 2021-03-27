/**
 * 剑指 Offer 07. 重建二叉树
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorder ;
    unordered_map<int,int> hashMap;
    
    TreeNode* build(int pre_root ,int in_left ,int in_right){
        //超出范围
        if(in_left>in_right){
            return NULL;
        }
        //构建头节点
        TreeNode *root =new TreeNode(preorder[pre_root]);
        //得到头节点在中序遍历中的下下标
        int root_pos = hashMap.find(preorder[pre_root])->second;
        //递归构建左子树(从in_left到root_pos前一个)
        root->left = build(pre_root+1,in_left,root_pos-1);
        //递归构建右子树(从root_pos+1到in_right),pre_root:从之前的pre_root加上左子树的个数
        root->right = build(root_pos-in_left+pre_root+1,root_pos+1,in_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //赋值到成员变量
        this->preorder = preorder;
        //构造哈希表加快查找
        for(int i = 0;i < inorder.size();i++){
            this->hashMap.insert({inorder[i],i});
        }
       //赋值到成员变量
       return build(0,0,inorder.size()-1);
    }
};
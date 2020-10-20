#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot==NULL)
            return true;
        int l=dfs(pRoot->left);
        int r=dfs(pRoot->right);
        // 注意平衡二叉树的定义：任意节点左右子数高度不能相差超过1
        if(abs(l-r) > 1)
            return false;
        else;
            return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
    int dfs(TreeNode* pRoot){
        if(pRoot==NULL)
            return 0;
        int l=dfs(pRoot->left);
        int r=dfs(pRoot->right);
        return l>r?l+1:r+1;
    }
};

int main(){
    return 0;
}
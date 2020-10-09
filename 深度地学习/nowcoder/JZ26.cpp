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
    TreeNode* leftHead = NULL;
    TreeNode* rightHead  = NULL;
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        
        if(pRootOfTree==NULL)  return pRootOfTree;//递归边界
        Convert(pRootOfTree->left);
        if(rightHead==NULL){
            leftHead=rightHead=pRootOfTree;
        }else{
            rightHead->right=pRootOfTree;
            pRootOfTree->left=rightHead;
            rightHead=pRootOfTree;
        }
        Convert(pRootOfTree->right);
        return leftHead;

        


        // if(pRootOfTree==NULL)  return NULL;//递归边界
        // if(pRootOfTree->left==NULL && pRootOfTree->right==NULL)  return pRootOfTree;//递归边界
        
        // TreeNode* left = Convert(pRootOfTree->left);//递归左边
        // TreeNode* p = left;
        // while(p!=NULL && p->right!=NULL)//找左子树最右节点
        //     p = p->right;//当p->right为NULL的时候跳出循环
        // if(left)//若左子树不空
        // {
        //     p->right = pRootOfTree;
        //     pRootOfTree->left = p;
        // }
        // TreeNode* right = Convert(pRootOfTree->right);//递归右边
        // if(right)//若右子树不空
        // {
        //     pRootOfTree->right = right;
        //     right->left = pRootOfTree;
        // }
        // return left ? left : pRootOfTree;
    }
};
int n=1;
void buildTree(TreeNode* root) {
	if(n==7)
        return;
    root->left=new TreeNode(++n);
    root->right=new TreeNode(++n);
    buildTree(root->left);
    buildTree(root->right);
};
int main(){
    TreeNode* root=new TreeNode(1);
    buildTree(root);
    Solution A;
    A.Convert(root);
    
    return 0;
}
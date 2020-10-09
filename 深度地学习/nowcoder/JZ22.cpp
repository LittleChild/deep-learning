#include<iostream>
#include<queue>
#include<vector>
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int>re;
        if(root==NULL){
            return re;
        }
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty())
        {
            root=q.front();
            q.pop();
            re.push_back(root->val);
            if(root->left!=NULL)
                q.push(root->left);
            if(root->right!=NULL)
                q.push(root->right);
        }
        return re;

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
    Solution s;
    TreeNode* root=new TreeNode(1);
    buildTree(root);
    vector<int> re=s.PrintFromTopToBottom(root);
    for(int i=0;i<re.size();i++){
        cout<<re[i]<<"--";
    }
    return 0;
}
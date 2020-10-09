// 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
// 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
// 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
#include<iostream>
#include<vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        return rebuilt(0, 0, pre.size() - 1, pre, vin);
    }
    TreeNode* rebuilt(int prestart, int vinstart, int size, vector<int> pre, vector<int> vin) {
        if (prestart >= pre.size() || vinstart > size) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(pre[prestart]);
        int ii = 0;
        for (int i = vinstart; i <= size; i++) {
            if (pre[prestart] == vin[i]) {
                ii = i;
                break;
            }
        }
        root->left = rebuilt(prestart + 1, vinstart, ii - 1, pre, vin);
        root->right= rebuilt(prestart + 1 + ii - vinstart, ii + 1, size, pre, vin);
        return root;
    }
};

void display(TreeNode* root) {
    if (root == NULL)
        return;
    else
    {
        cout << root->val << ' ';
        display(root->left);
        display(root->right);
    }
};
int main() {
    vector<int>pre = { 1,2,4,7,3,5,6,8 };
    vector<int>vin = { 4,7,2,1,5,3,8,6 };
    Solution a;
    TreeNode* root = a.reConstructBinaryTree(pre, vin);
    display(root);
    return 0;
}
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>re;
        if(root==NULL)
            return re;
        queue<TreeNode*>q;
        queue<TreeNode*>q2;
        q.push(root);
        int i=0;
        // while(!q.empty())
        // {
        //     //一次性将一整行的节点全部都遍历完
        //     vector<int> level;
        //     size_t levelsize = q.size();
        //     for(size_t j=0;j<levelsize;++j)
        //     {
        //         TreeNode* cur = q.front();
        //         level.push_back(cur->val);
        //         //如果存在左孩子，将其入队列
        //         if(cur->left)
        //         q.push(cur->left);
        //         //如果存在右孩子，将其入队列
        //         if(cur->right)
        //         q.push(cur->right);
        //         q.pop();
        //     }
        //     if(i%2==0)
        //         re.push_back(level);
        //     else{
        //         reverse(level.begin(),level.end());
        //         re.push_back(level);
        //     }
        // }
        while(!q.empty()||!q2.empty()){
            vector<int>temp;
            if(i%2==0){
                while(!q.empty()){
                    TreeNode* t=q.front();
                    temp.push_back(t->val);
                    if(t->left)
                    q2.push(t->left);
                    if(t->right)
                    q2.push(t->right);
                    q.pop();
                }
            }
            else{
                while(!q2.empty()){
                    TreeNode* t=q2.front();
                    temp.push_back(t->val);
                    if(t->left)
                    q.push(t->left);
                    if(t->right)
                    q.push(t->right);
                    q2.pop();
                }
                reverse(temp.begin(),temp.end());
            }
            i++;
            re.push_back(temp);
        }
        return re;
    }
};

int main(){

    return 0;
}
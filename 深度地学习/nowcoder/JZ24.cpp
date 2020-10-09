#include<iostream>
#include<vector>
#include<map>
#include<iterator>
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		vector< vector<int> > re;
        vector<int>pn;
		if(root)
			dfs(root,expectNumber,re,pn);
		return re;
		
		/*
		vector< vector<int> > re;
        vector<int>pn;
		TreeNode* temp;

		if(!root)
			return re;
		// pn.push_back(root->val);
		// re.push_back(pn);
		map<TreeNode*,vector<int>>s;
		s[root]=pn;
		int sum=0;
		while(!s.empty()){
			temp=s.end()->first;
			pn=s.end()->second;
			s.erase(temp);
			if(temp->left==NULL && temp->right==NULL){
				sum=0;
				for(int i=0;i<pn.size();i++)
					sum+=pn[i];
				if(sum==expectNumber)
					re.push_back(pn);
				
				// else
				// {
				// 	sum-=temp->val;
				// }
			}
			if(temp->left!=NULL){
				pn.push_back(temp->left->val);
				s[temp->left]=pn;
				// sum+=temp->left->val;
			}
			if(temp->right!=NULL){
				pn.push_back(temp->right->val);
				s[temp->right]=pn;
				// sum+=temp->right->val;
			}
		}
		return re;
		*/
    }
	void dfs(TreeNode* root,int s,vector<vector<int>>&re,vector<int> &trace){
		trace.push_back(root->val);
		if(root->left==NULL && root->right==NULL){
			if(root->val==s)
				re.push_back(trace);
		}
		if(root->left)
			dfs(root->left,s-root->val,re,trace);
		if(root->right)
			dfs(root->right,s-root->val,re,trace);
		trace.pop_back();
	}
};

int main(){

    return 0;
}
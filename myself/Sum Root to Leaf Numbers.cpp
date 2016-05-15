// Sum Root to Leaf Numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int travel(TreeNode* nodeRoot,int pathsum,int &totalsum)
	{
		if(nodeRoot->left==NULL&&nodeRoot->right==NULL) totalsum+=pathsum+nodeRoot->val;
		if(nodeRoot->left){
			travel(nodeRoot->left,(pathsum+nodeRoot->val)*10,totalsum);
		}
		if(nodeRoot->right){
			travel(nodeRoot->right,(pathsum+nodeRoot->val)*10,totalsum);
		}
		return totalsum;
	}
	int sumNumbers(TreeNode* root) {
		if(root==NULL) return 0;
		int total=0,pathsum=0;
		total=travel(root,pathsum,total);
		return total;
	}
};


class Solution2{
public:
	int helper(TreeNode*root,int sum){
		if(root==NULL){
			return 0;
		}
		if(root->left==NULL&&root->right==NULL){
			return (sum*10+root->val);
		}
		else{
			return helper(root->left,sum*10+root->val)+helper(root->right,sum*1+root->val);
		}
	}
	int sumNumbers(TreeNode* root)
	{
		return helper(root,0);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	return 0;
}


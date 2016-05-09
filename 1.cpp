// 1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "vector"
#include "iostream"
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int vsize=nums.size();
		vector<int> v_tmp;
		int i,j;
		for(i=0;i<vsize-1;i++)
		{
			for(j=i+1;j<vsize;j++)
			{
				if(nums[i]+nums[j]==target)
				{
					v_tmp.push_back(i);
					v_tmp.push_back(j);
					return v_tmp;
				}
			}
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{	
	int a[4]={3,2,4};
	vector<int> nums(a,a+4);
	vector<int> tmp;
	int target = 6;
	Solution s;
	tmp=s.twoSum(nums,target);
	cout<<"["<<tmp[0]<<","<<tmp[1]<<"]"<<endl;
	return 0;
}


// Container with most master.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "vector"
#include "math.h"
using namespace std;
int objright=-1,objleft=-1;
class Solution{
public:
	int computeAreas(int left,int right,vector<int> heights)
	{
		return (right-left)*min(heights[right],heights[left]);
	}
	int maxArea(vector<int> &heights){
		int left=0;int ans=0;
		int right=heights.size()-1;
		objright=right,objleft=left;

		while(left<=right)
		{
			//ans=max(ans,computeAreas(left,right,heights));
			if(ans<computeAreas(left,right,heights))
			{
				objright=right,objleft=left;
				ans=computeAreas(left,right,heights);
			}
			if(heights[left]<=heights[right])
				left++;
			else
				right--;
		}
		return ans;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	int ans;
	vector<int> v_height;
	v_height.push_back(1);
	v_height.push_back(3);
	v_height.push_back(5);
	v_height.push_back(2);
	v_height.push_back(4);
	ans=s.maxArea(v_height);
	cout <<ans<<endl;
	cout<<objleft<<" "<<objright<<endl;
	return 0;
}


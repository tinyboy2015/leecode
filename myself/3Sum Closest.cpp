class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(),nums.end());
		int result=nums[0]+nums[1]+nums[2];
		for(int i=0;i<nums.size();i++)
		{
			int start=i+1,end=nums.size()-1;
			while(start<end)
			{
				if(abs(result-target)>abs(nums[i]+nums[start]+nums[end]-target))
				{
					result=nums[i]+nums[start]+nums[end];
				}
				if(nums[i]+nums[start]+nums[end]<target)
				{
					start++;
				}
				else
					end--;
			}
		}
		return result;
	}
};
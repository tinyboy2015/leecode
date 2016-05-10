class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int,int>hash;
		for(int i=0;i<nums.size();i++)
		{
		    hash[nums[i]]=i;
		}
		vector<int> ans(2);
		for(int i=0;i<nums.size();i++)
		{
		    if(hash.find(target-nums[i])!=hash.end()&&hash[target-nums[i]]!=i)
		    {
		        ans[1]=i;
		        ans[0]=hash[target-nums[i]];
		    }
		}
		return ans;
	}
};
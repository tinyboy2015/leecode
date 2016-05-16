class SolutionMy {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		int result=nums[1]+nums[2]+nums[3];
		vector<int> v_temp;
		vector<vector<int>> vec;
		for(int i=0;i<nums.size();i++)
		{
			int start=i+1;
			int end=nums.size()-1;
			while(start<end)
			{
				if((nums[i]+nums[start]+nums[end])==0)
				{
					v_temp.push_back(nums[i]);
					v_temp.push_back(nums[start]);
					v_temp.push_back(nums[end]);
					vec.push_back(v_temp);
					while(nums[start]=nums[start+1]&&start<end)
					{
						start++;
					}
					start++;
					while(nums[end]=nums[end-1]&&start<end)
					{
						end--;
					}
					end--;
				}
				
				if((nums[i]+nums[start]+nums[end])>0)
				{
					end--;
				}
				else if((nums[i]+nums[start]+nums[end])<0)
				{
					start++;
				}
			}
		}
		return vec;
	}
};


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>>result;
		sort(nums.begin(),nums.end());
		for(int i=0;i<nums.size();i++)
		{
			if(i>0&&nums[i]==nums[i-1]){
				continue;
			}
			int start=i+1,end=nums.size()-1;
			int targat=-nums[i];
			while(start<end)
			{
				if(start>i+1&&nums[start-1]==nums[start])
				{
					start++;
					continue;
				}
				if(nums[start]+nums[end]<targat)
				{
					start++;
				}else if(nums[start]+nums[end]>targat)
				{
					end--;
				}else{
					vector<int> triple;
					triple.push_back(nums[i]);
					triple.push_back(nums[start]);
					triple.push_back(nums[end]);
					result.push_back(triple);
					start++;
				}
			}
		}
		return result;
	}
};
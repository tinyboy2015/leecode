my code，but somemistake：
class Solution {
public:
	//i index the most mini
	int getMin(int index,int len,vector<int>& nums)
	{
		if(index==len-2) return 1;
		if(nums[index]>=len-1-index) return 1;//just need one step can arrive
		else{
			int minstep=INT_MAX;
			for(int i=1;i<=nums[index]&&(index+i)<len;i++){
				minstep=min(minstep,getMin(index+i,len,nums));
			}
			return minstep+1;
		}
	}

	int jump(vector<int>& nums) {
		int len=nums.size();
		return getMin(0,len,nums);
	}
};

standard code:比我写的要精妙多了。
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), step = 0, start = 0, end = 0;
        while (end < n - 1) {
            step++; 
            int maxend = end + 1;
            for (int i = start; i <= end; i++) {
                if (i + nums[i] >= n - 1) return step;
                maxend = max(maxend, i + nums[i]);
            }
            start = end + 1;
            end = maxend;
        }
        return step;
    }
};
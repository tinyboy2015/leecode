class Solution {
public:
	void sortColors(vector<int>& nums) {
		int iSize=nums.size();
		//处理蓝色
		for(int i=0;i<iSize;i++)
		{
			//如果尾部本来就是蓝色，不用交换，直接iSize--；
			if(nums[iSize-1]==2)
			{
				iSize--;
				continue;
			}
			if(nums[i]==2)
			{
				swap(nums[i],nums[iSize-1]);
				iSize--;
			}
		}
		//处理红色，iSize保持原来的
		for(int i=0;i<iSize;i++)
		{
			//如果尾部本来就是蓝色，不用交换，直接iSize--；
			if(nums[iSize-1]==1)
			{
				iSize--;
				continue;
			}
			if(nums[i]==1)
			{
				swap(nums[i],nums[iSize-1]);
				iSize--;
			}
		}
		
	}
};
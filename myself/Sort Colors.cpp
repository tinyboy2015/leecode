class Solution {
public:
	void sortColors(vector<int>& nums) {
		int iSize=nums.size();
		//������ɫ
		for(int i=0;i<iSize;i++)
		{
			//���β������������ɫ�����ý�����ֱ��iSize--��
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
		//�����ɫ��iSize����ԭ����
		for(int i=0;i<iSize;i++)
		{
			//���β������������ɫ�����ý�����ֱ��iSize--��
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
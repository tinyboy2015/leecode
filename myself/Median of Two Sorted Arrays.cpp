class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int M=nums1.size();
		int N=nums2.size();
		int k=(M+N)/2;
		if(k%2==0)
		{
			return (ReturnKValue(nums1,0,nums2,0,k)+ReturnKValue(nums1,0,nums2,0,k+1))/2;
		}
		else{
			return ReturnKValue(nums1,0,nums2,0,k+1);
		}
	}
	//�������������е�kС����
	int ReturnKValue(vector<int>&A,int Abegin,vector<int>&B,int Bbegin,int kValue)
	{
		if(kValue==1)
		{
			if(A[Abegin]<=B[Bbegin])
			{
				return A[Abegin];
			}
			else
				return B[Bbegin];
		}

		if(A[Abegin+kValue/2-1]<=B[Bbegin+kValue/2-1])
		{
			//˵��A�Ĳ��ֿ���ȫ��������
			ReturnKValue(A,Abegin+kValue/2,B,Bbegin,kValue-kValue/2);//���ﲻд��kvalue/2����ʽ����Ϊ����3���ǲ����ó����������������1��2.
		}
		else if(A[Abegin+kValue/2-1]>B[Bbegin+kValue/2-1])
		{
			//˵��B�Ĳ��ֿ���ȫ��������
			ReturnKValue(A,Abegin,B,Bbegin+kValue/2,kValue-kValue/2);
		}

		return 0;
	}
};
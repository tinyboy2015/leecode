class Solution{
public:
	vector<int> searchRange(vector<int>&nums,int target){
		int len =nums.size();
		vector<int> res;
		int i,j;
		int first=-1,end=-1;
		for(i=0;i<len;i++){
			if(nums[i]==target){
				first=i;
				break;
			}
		}
		for(j=len-1;j>first;j--){
			if(nums[j]==target){
				end=j;
				break;
			}
		}
		if(j==first){
		    end=first;
		}
		res.push_back(first);
		res.push_back(end);
		return res;
	}
};
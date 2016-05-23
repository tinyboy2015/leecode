解法1：
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
            auto end_unique = unique(nums.begin(), nums.end());
            return end_unique-nums.begin();
     }
};
解法2：
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		vector<int>::iterator it;
		it=nums.begin();
		while((it+1)!=nums.end()){
			if(*it==*(it+1)){
				nums.erase(it+1);
				continue;
			}
			it++;
		}
		return nums.size();
	}
};
解法3：
static int removeDuplicates(vector<int>& nums)
{
    if (nums.empty()) return 0;

    int count = 0, size = nums.size() & INT_MAX;
    for (int j = 1; j < size; j++) {
        if (nums[count] != nums[j]) {
            nums[++count] = nums[j];
        }
    }
    return count+1;
}
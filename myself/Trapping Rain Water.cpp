class Solution {
public:
    int trap(vector<int>& height) {
        int len=height.size();
        if(len<=1) return 0;
        height.push_back(0);
        height.insert(height.begin(), 0);
        vector<int> left(len, 0), right(len, 0);
        int cur_left=0, cur_right=0;
        for(int i=1; i<=len; i++){
            cur_left=max(cur_left, height[i-1]);
            left[i-1]=cur_left;
        }
        for(int i=len-1; i>=0; i--){
            cur_right=max(cur_right, height[i+1]);
            right[i]=cur_right;
        }
        int result=0;
        for(int i=0; i<len; i++){
            result+=(min(left[i], right[i])>height[i] ? min(left[i], right[i])-height[i] : 0);
        }
        return result;
    }
};
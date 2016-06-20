void plusone(vector<int> &digits)
{
    int n = digits.size();
    for (int i = n - 1; i >= 0; --i)
    {
        if (digits[i] == 9)
        {
            digits[i] = 0;
        }
        else
        {
            digits[i]++;
            return;
        }
    }
        digits[0] =1;
        digits.push_back(0);

}

my:
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int len=digits.size();
		vector<int >::iterator it;
		vector<int> temp;
		int carry=1,i;
		for(i=len-1;i>=0;i--){
			if(digits[i]+carry>=10){
				digits[i]=0;
				carry=1;
			}else{
				digits[i]=digits[i]+carry;
				carry=0;
			}
		}
		if(carry==1&&i<0){
			temp.push_back(1);
		}
		for(int i=0;i<len;i++){
			temp.push_back(digits[i]);
		}
		return temp;
	}
};
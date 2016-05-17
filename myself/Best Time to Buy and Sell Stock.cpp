自写第一种，执行时间过长，不满足要求。
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len=prices.size();
		int j;
		int max=0;
		for(int i=0;i<len;i++){
			for(j=i+1;j<len;j++)
			{
				if(prices[j]-prices[i])
				{
					max=(prices[j]-prices[i])>max?(prices[j]-prices[i]):max;
				}
			}
		}
		return max;
	}
};

第二种：这种从尾部开始算，因为每次都算当前与之后日子最大的值的比较，所以省了很多步。

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if(prices.empty()) return 0;
		int i=prices.size()-1,ans=0,maxp=prices[i];
		for(--i;i>=0;--i)
		{
			ans=max(ans,maxp-prices[i]);
			maxp=max(maxp,prices[i]);
		}
		return ans;
	}
};
��д��һ�֣�ִ��ʱ�������������Ҫ��
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

�ڶ��֣����ִ�β����ʼ�㣬��Ϊÿ�ζ��㵱ǰ��֮����������ֵ�ıȽϣ�����ʡ�˺ܶಽ��

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
// Count and Say.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "stack"
using namespace std;
class Solution {
public:
	int begin_count;
	stack<int> v_digit;
	int getNumberList(int n,stack<int>&nums)
	{
		while(n/10){
			nums.push(n%10);
			n/=10;
		}
		//处理最高一位数
		if(0<n<10)
			nums.push(n%10);
		return 0;
	}
	string countAndSay(int n) {
		char ctmpBuf[10];
		getNumberList(n,v_digit);
		int count=0,preNum=-1;
		string strTemp;
		while(!v_digit.empty())
		{
			if(preNum==v_digit.top())
			{
				count++;
			}
			else{
				//第一次特殊处理
				if(count==0){
					preNum=v_digit.top();
					count=1;
					v_digit.pop();
					continue;
				}
				memset(ctmpBuf,0x00,sizeof(ctmpBuf));
				sprintf(ctmpBuf,"%d%d",count,preNum);
				strTemp+=ctmpBuf;
				preNum=v_digit.top();
				count=1;
			}
			v_digit.pop();
		}
		memset(ctmpBuf,0x00,sizeof(ctmpBuf));
		sprintf(ctmpBuf,"%d%d",count,preNum);
		strTemp+=ctmpBuf;
		return strTemp;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{ 
	Solution s;
	string str;
	str=s.countAndSay(223334444);
	cout<<str<<endl;
}


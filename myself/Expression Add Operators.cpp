// Expression Add Operators.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "iostream"
#include "vector"
#include "queue"
#include "string"
using namespace std;
char operatorChar[4]={'+','-','*','0'};
class Solution{
public:
	vector<string> calcString;
	int calcNum(int pre,int now, char op)
	{
		int result;
		switch (op){
		case '+':
			result=pre+now;
			break;
		case '-':
			result=pre-now;
			break;
		case '*':
			result=pre*now;
			break;
		default:
			result=-1;
			break;
		}
		return result;
	}
	int returnCalcString(string prefix,string num)
	{
		string temp;
		if(num.size()==0) return -1;
		else if(num.size()==1){
			temp=prefix+num;
			calcString.push_back(temp);
		}
		else{
			char newstr[4];
			string tempstr;
			for(int i=0;i<4;i++){
				tempstr.clear();
				memset(newstr,0,sizeof(newstr));
				if(operatorChar[i]=='0') sprintf(newstr,"%c",num[0]);
				else{
					sprintf(newstr,"%c%c",num[0],operatorChar[i]);
				}
				tempstr=prefix+newstr;
				returnCalcString( tempstr,&num[1]);
			}
		}
		return 0;
	}
	int splitAndCalc(string numberStr)
	{
		queue<int> num;
		queue<char> op;
		int number;
		int pre=0,now=0,flag=0;
		char opt,last;
		int len=numberStr.size();
		for(int i=0;i<len;i++)
		{
			number=0;
			while(i<len&&numberStr[i]>='0'&&numberStr[i]<='9')
			{
				number=number*10 + numberStr[i]-'0';
				i++;
			}
			num.push(number);
			if(i<len){
				op.push(numberStr[i]);
			}
		}

		while(!op.empty()){
			if(flag==0){
				pre=num.front();
				num.pop();
				now=num.front();
				num.pop();
				opt=op.front();
				op.pop();
				flag=1;
			}
			if(op.front()=='+'||op.front()=='-'){
				pre=calcNum(pre,now,opt);
				opt=op.front();
				last=op.front();
				op.pop();
				now=num.front();
				num.pop();
			}
			else{
				now=calcNum(now,num.front(),op.front());
				num.pop();
				last=op.front();
				op.pop();
			}
		}
		return calcNum(pre,now,last);
	}

	vector<string>addOpperators(string num,int target)
	{
		returnCalcString("",num);
		int len=calcString.size();
		vector<string> resultstr;
		for(int i=0;i<len;i++)
		{
			if(splitAndCalc(calcString[i])==target)
			{
				resultstr.push_back(calcString[i]);
			}
		}
		return resultstr;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	vector<string> v_str;
	v_str=s.addOpperators("2145",2);

	return 0;
	vector<string>::iterator it;
	for(it=v_str.begin();it!=v_str.end();it++)
	{
		cout<<it->c_str()<<endl;
	}
	return 0;
}


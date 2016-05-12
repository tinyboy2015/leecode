// Longest Palindromic Substring.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;
bool IstPalindromeStr(string str)
{
	int k=str.length();
	if(k==1){
		return true;
	}
	for(int i=0;i<k/2;i++)
	{
		if(str[i]!=str[k-i-1])
		{
			return false;
		}
	}
	return true;
}

class Solution {
public:
	int max;
	string MaxString;
	string longestPalindrome(string s) {
		int iLen=s.length();
		for(int len=2;len<iLen;len++)
		{
			for(int i=0;i<iLen-len+1;i++)
			{
				string tempStr(s,i,len);
				if(IstPalindromeStr(tempStr))
				{
					// Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000,for c convenient;
					//and there exists one unique longest palindromic substring.so when finded can be break;
					if(max<len){
						max=len;
						MaxString=tempStr;
						break;
					}
				}
			}
		}
		return MaxString;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	string str("dasdfMfoofMggaed");

	string temp=s.longestPalindrome(str);
	cout<<temp<<endl;
	return 0;
}


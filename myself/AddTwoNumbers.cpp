// Add Two Numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int addvalue,flag=0;
		int iValue;
		ListNode* returnVal=NULL,*pNext;
		ListNode* temp,*exchange;
		ListNode*p1=l1,*p2=l2;//
		temp=returnVal;
		while(p1!=NULL&&p2!=NULL)
		{
			if((addvalue=p1->val+p2->val+flag)>=10)
			{	
				flag=1;
				iValue=addvalue%10;
			}
			else{
				flag=0;
				iValue=addvalue;
			}			
			p1=p1->next;
			p2=p2->next;
			if(returnVal==NULL)
			{
				temp=new ListNode(iValue);//new use
				pNext=returnVal=temp;
			}
			else{
				temp=new ListNode(iValue);//new use
				pNext->next=temp;
				pNext=temp;
			}
		}
		if(p1==NULL&&p2==NULL)
		{
			if(flag==1)
			{
				iValue=1;
				temp=new ListNode(iValue);
				pNext->next=temp;
				pNext=temp;
			}
		}
		else if(p1!=NULL||p2!=NULL)
		{
			if(p1!=NULL)
				exchange=p1;
			else 
				exchange=p2;
			while(exchange!=NULL||flag==1)
			{
				if(exchange==NULL)
				{
					iValue=flag;
					flag=0;
				}
				else if(exchange->val+flag>=10)
				{
					flag=1;
					iValue=addvalue%10;
				}
				else{
					flag=0;
					iValue=addvalue;
				}
				temp=new ListNode(iValue);//new use
				pNext->next=temp;
				pNext=temp;
				exchange=exchange->next;
			}
		}
		return returnVal;
	}
};

void printList(ListNode *listtmp)
{
	ListNode* pNode=listtmp;
	while(pNode!=NULL)
	{
		cout<<pNode->val;
		pNode=pNode->next;
	}
	cout<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ListNode *lhead,*phead1=NULL,*phead2=NULL,*pNext=NULL,*pTemp;
	phead1=pNext=new ListNode(2);
	pTemp=new ListNode(4);pNext->next=pTemp;
	pNext=pTemp;
	pTemp=new ListNode(3);pNext->next=pTemp;
	pNext=pTemp;
	printList(phead1);
	phead2=pNext=new ListNode(5);
	pTemp=new ListNode(6);pNext->next=pTemp;
	pNext=pTemp;
	pTemp=new ListNode(4);pNext->next=pTemp;
	pNext=pTemp;
	printList(phead2);

	Solution s;
	lhead=s.addTwoNumbers(phead1,phead2);
	printList(lhead);
	return 0;
}
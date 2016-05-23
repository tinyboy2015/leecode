Swap Nodes in Pairs :mycode
class Solution {
public:
	ListNode* swapTwo(ListNode* head) {
		ListNode *leftNode=head->next;
		if(leftNode->next==NULL){
			return leftNode;
		}
		ListNode* rightNode=leftNode->next;
		ListNode* temp=rightNode->next;
		rightNode->next=leftNode;
		leftNode->next=temp;
		head->next=rightNode;
		return leftNode;
	}
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy=new ListNode(0);
		dummy->next=head;
		head=dummy;
		while(head->next!=NULL){
			head=swapTwo(head);
		}
		return dummy->next;
    }
};

//lizi
class Solution {
public:
    /**
     * @param head a ListNode
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
        if(head==NULL || head->next==NULL) return head;
        ListNode *helper=new ListNode(0);
        ListNode *ret=head;
        ListNode *cur=helper;
        while(ret  && ret->next) {
            ListNode *next=ret->next->next;
            cur->next=ret->next;
            //此步为关键性的连接
            cur=cur->next;
            //cur走了，但连接并没断，还在被helper连接着。
            //通过之上的操作此时形成了ret，cur，next分别指向头，第二个，第三个
            cur->next=ret;
            //之上，第二个与第三个断开，与第一个相连
            cur=cur->next;
            //cur又指向了ret，第一个。
            cur->next=NULL;
            //此为切断1,2联系
            ret=next;
        }
        if(ret) cur->next=ret;
        return helper->next;
    }
};
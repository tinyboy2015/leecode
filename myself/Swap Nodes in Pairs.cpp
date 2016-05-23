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
            //�˲�Ϊ�ؼ��Ե�����
            cur=cur->next;
            //cur���ˣ������Ӳ�û�ϣ����ڱ�helper�����š�
            //ͨ��֮�ϵĲ�����ʱ�γ���ret��cur��next�ֱ�ָ��ͷ���ڶ�����������
            cur->next=ret;
            //֮�ϣ��ڶ�����������Ͽ������һ������
            cur=cur->next;
            //cur��ָ����ret����һ����
            cur->next=NULL;
            //��Ϊ�ж�1,2��ϵ
            ret=next;
        }
        if(ret) cur->next=ret;
        return helper->next;
    }
};
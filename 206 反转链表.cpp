/*
��תһ��������

����:
������Ե�����ݹ�ط�ת�����ܷ�������ʵ��һ�飿
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//�͵����÷�
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *new_head=NULL;//ָ��������ͷ����ָ��
		while(head){
		ListNode *next=head->next;//����head->next
		head->next=new_head;//����head->next
		new_head=head;//�ƶ�new_head
		head=next;//��������
    }
	return new_head;//����������ͷ���
};

//ͷ�巨
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		ListNode temp_head(0);
		while(head){
			ListNode *next=head->next;
			head->next=temp_head.next;
			temp_head.next=head;
			head=next;
		}
		return temp_head.next;
	}
};
//�Ƚ�
1��
	ListNode temp_head(0);//��ʱ�ڵ�
	ListNode *new_head=NULL;//ָ�����




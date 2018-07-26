/*
��ת��λ�� m �� n ��������һ�α�����ԭ����ɷ�ת��

���磺
���� 1->2->3->4->5->NULL, m = 2 �� n = 4,

���� 1->4->3->2->5->NULL.

ע��:
���� m��n ��������������

1 �� m �� n �� �б��ȡ�
**/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int change_len=n-m+1;//������Ҫ���õĽ�����
		ListNode *pre_head=NULL;//��ʼ����ʼ���õĽڵ��ǰ��
		ListNode *result=head;//����ת���������ͷ�������������Ϊhead
		while(head&&--m){
			pre_head=head;//��¼head��ǰ��
			head=head->next;
		}
		ListNode *modify_list_tail=head;//��modify_list_tailָ��ǰ��head�������ú������β
		ListNode *new_head=NULL;
		while(head&&change_len){//����change_len�����
			ListNode *next=head->next;
			head->next=new_head;
			new_head=head;
			head=next;
			change_len--;//ÿ���һ��������ã�change_len--
		}
		
		modify_list_tail->next=head;//�������ú������β�����öεĺ�һ�����
		if(pre_head){
			pre_head->next=new_head;//���pre_head���գ�˵�����Ǵӵ�һ���ڵ㿪ʼ���õ�m>1
									//����������ʼ�Ľ��ǰ�������ú��ͷ�������
		}
		else{
			result=new_head;//���pre_headΪ�գ�˵��m==1�ӵ�һ���ڵ㿪ʼ���ý����Ϊ���ú��ͷ���
		}
		return result;
};
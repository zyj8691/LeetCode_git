/*
��дһ�������ҵ������������ཻ����ʼ�ڵ㡣
���磬�������������
A:          a1 �� a2
                   �K
                     c1 �� c2 �� c3
                   �J            
B:     b1 �� b2 �� b3
�ڽڵ� c1 ��ʼ�ཻ��
ע�⣺
�����������û�н��㣬���� null.
�ڷ��ؽ���������������뱣��ԭ�еĽṹ��
�ɼٶ���������ṹ��û��ѭ����
���������� O(n) ʱ�临�Ӷȣ��ҽ��� O(1) �ڴ档
**/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//����һ
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		std::set<ListNode*> node_set;//���ò��Ҽ���node_set
		while(headA){
			 node_set.insert(headA);//������A�еĽ�����node_set
			 headA=headA->next;//��������A
		}
		while(headB){
			if(node_set.find(headB)!=node_set.end()){
				return headB;//����headB���ҵ���һ��������node_set�еĽ��ʱ
			}
			headB=headB->next;//��������B
		}
		return NULL;
    }
};
//������
int get_list_length(ListNode *head){
	int len=0;
	while(head){
		len++;
		head=head->next;
	}
	return len;
}

ListNode *forward_long_list(int long_len,int short_len,ListNode *head){
	int delta=long_len-short_len;
	while(head&&delta){
		head=head->next;
		delta--;
	}
	return head;
}

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int list_A_len=get_list_length(headA);
		int list_B_len=get_list_length(headB);
		if(list_A_len>list_B_len){
			headA=forward_long_list(list_A_len,list_B_len,headA);
			//�������A�����ƶ�headA����Ӧλ��
		}
		else{
			headB=forward_long_list(list_B_len,list_A_len,headB);
			//�������B�����ƶ�headA����Ӧλ��
		}
		while(headA&&headB){
			if(headA==headB)
				return headA��
			headA=headA->next;
			headB=headB->next;
		}
		return NULL;
	}
};


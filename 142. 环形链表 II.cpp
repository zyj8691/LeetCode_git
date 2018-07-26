/*
��һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
˵������Ӧ�޸ĸ���������
���䣺
���Ƿ���Բ��ö���ռ������⣿
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//����һ ����Ҫ��
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *re_head=head;
        ListNode *pre_tail=NULL;
        while(head){
            pre_tail=head;
            head=head->next;
        }
        ListNode *tail=pre_tail;
        while(re_head){
            if(tail=re_head)
                return re_head;
            re_head=re_head->next;
        }
        return NULL;
    }
};
//������
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        std::set<ListNode*>node_set;//����node_set
		while(head){
			if(node_set.find(head)!=node_set.end()){
				return head;
			}
			node_set.insert(head);//��������node_set
			head=head->next;	
		}
		return NULL;//û�����������򷵻�NULL		
    }	
};

//������ ����ָ��
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
	ListNode *fast = head;
	ListNode *slow = head;
	ListNode *meet = NULL;
	while (fast){
		fast = fast->next;
		slow = slow->next;
		if (!fast){
			return NULL;
		}
		fast = fast->next;
		if (fast == slow){
			meet = fast;
			break;
		}
	}
	if (meet == NULL){
		return NULL;
	}
	while (head&&meet){
		if (head == meet){
				return head;
		}
		head = head->next;
		meet = meet->next;
	}
		
	
	return NULL;
}
};
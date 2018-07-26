/*
给一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
说明：不应修改给定的链表。
补充：
你是否可以不用额外空间解决此题？
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//方法一 不合要求
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
//方法二
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        std::set<ListNode*>node_set;//设置node_set
		while(head){
			if(node_set.find(head)!=node_set.end()){
				return head;
			}
			node_set.insert(head);//将结点插入node_set
			head=head->next;	
		}
		return NULL;//没有遇到环，则返回NULL		
    }	
};

//方法三 快慢指针
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
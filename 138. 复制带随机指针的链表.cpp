/*
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的深度拷贝。 

*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 /*
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
    }
};
*/
/*solution*/
#include <iostream>
#include <map>
#include <vector>

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
	
};



class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		std::map<RandomListNode*, int>node_map;
		std::vector<RandomListNode*>node_vec;
		RandomListNode *ptr = head;
		int i = 0;
		while (ptr){
			node_vec.push_back(new RandomListNode(ptr->label));
			node_map[ptr] = i;
			ptr = ptr->next;
			i++;
		}
		node_vec.push_back(0);
		ptr = head;
		i = 0;
		while (ptr)
		{
			//ptr->random = node_vec[i];
			node_vec[i]->next = node_vec[i + 1];
			if (ptr->random)
			{
				int id = node_map[ptr->random];
				node_vec[i]->random = node_vec[id];
			}
			ptr = ptr->next;
			i++;
		}
		return node_vec[0];
	}
};


int main()
{
	RandomListNode a(1);
	RandomListNode b(2);
	RandomListNode c(3);
	RandomListNode d(4);
	RandomListNode e(5);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	
	a.random = &c;
	b.random = &d;
	c.random = &c;
	e.random = &d;

	Solution solve;
	RandomListNode*head = solve.copyRandomList(&a);
	while (head){
		printf("label = %d  ", head->label);
		if (head->random){
			printf("rand = %d\n", head->random->label);
		}
		else
		{
			printf("rand = NULL\n");
		}
		head = head->next;
	}
	
	return 0;
}

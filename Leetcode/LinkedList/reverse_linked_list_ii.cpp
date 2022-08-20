/* Linked List */

/* Reverse Linked List II
 *
 * Reverse a linked list from m to n
 * in-place and one-pass
 *
 * */

// basic reverse problem
// point is edge cases checking

#include "listNode.h"

using namespace std;

class Solution{
public:
	ListNode *reverseBetween(ListNode *head, int m, int n){
		
		ListNode dummy(-1); 
		dummy.next = head;

		ListNode *prev = &dummy; // classic way of defining a ListNode pointer

		for(int i = 1; i < m ; i++){ // counts from 1
			prev = prev->next;
		}

		ListNode* const head2 = prev; // m-1 ListNode pointer

		prev = head2->next; // m
		ListNode *cur = prev->next; // m+1
		for(int i = m; i<n; ++i){
			prev->next = cur->next; // move first node's next pointer to head of next round
			cur->next = head2->next; // move current node's next pointer to first node
			head2->next = cur; // move fixed head's next pointer to current node
			cur = prev->next; // change current node to the head of next round
		}

		return dummy.next;
	}
};

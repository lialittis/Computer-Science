/*LinkedList*/

/* two linked lists, representing two non-negative numbers,
 * digits are stored in reverse order and each of their nodes
 * contain a single digit.
 *
 * Add the two numbers and return it as a linked list
 *
 * */

// O(m+n) and O(1)

#include "listNode.h"

class Solution{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
		ListNode dummy(-1);
		int carry = 0;
		ListNode *prev = &dummy;
		for(ListNode *pa = l1, *pb = l2; pa != nullptr || pb != nullptr; 
				pa = pa==nullptr ? nullptr : pa->next,
				pb = pb==nullptr ? nullptr : pb->next,
				prev = prev->next) {
			const int ai = pa==nullptr?0:pa->val;
			const int bi = pb==nullptr?0:pb->val;
			const int value = (ai+bi+carry) % 10;
			carry = (ai+bi+carry)/10;
			prev->next = new ListNode(value);
		}
		if(carry>0)
			prev->next = new ListNode(carry);
		return dummy.next;
	}
};

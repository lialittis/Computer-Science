#include <unordered_set>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(): val(0),next(nullptr){}
	ListNode(int x): val(x),next(nullptr){}
	ListNode(int x, ListNode *p):val(x),next(p){}
};

using namespace std;

bool hasCycle(ListNode *head){
	unordered_set<ListNode*> table;
	while(head != NULL){
		if(table.find(head)!=table.end())
			return true;
		table.insert(head);
		head = head->next;
	}
	return false;
}



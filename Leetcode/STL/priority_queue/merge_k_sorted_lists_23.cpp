#include <queue>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode():val(0),next(nullptr){}
	ListNode(int x):val(x),next(nullptr){}
	ListNode(int x,ListNode* p): val(x), next(p){}
};

struct Comp{
	bool operator() (ListNode* l1, ListNode*l2){
		return l1->val > l2->val; // min heap
	}
};

ListNode* mergeKLists(vector<ListNode*>& lists){
	if(lists.empty()) return nullptr;
	priority_queue<ListNode*,vector<ListNode*>,Comp> q;
	for(ListNode* list:lists){
		if(list) q.push(list);
	}

	ListNode* dummy = new ListNode(0), *cur = dummy;
	while(!q.empty()){
		cur->next = q.top();
		q.pop();
		cur = cur->next;
		if(cur->next) q.push(cur->next);
	}
	return dummy->next;
}


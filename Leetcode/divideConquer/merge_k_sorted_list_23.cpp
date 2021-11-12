#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution_pq{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.empty()) return NULL;
        ListNode* output = new ListNode(0);
        // comparer
        auto comp = [](ListNode* l1,ListNode* l2) {return l1->val > l2->val;};
        // create priority queue
        priority_queue<ListNode*,vector<ListNode*>,decltype(comp)> heap(comp);

        for(int i = 0; i<lists.size(); i++){
            if(lists[i] != NULL) heap.push(lists[i]);
        }

        ListNode* cur = output;
        while(!heap.empty()){
            cur->next = heap.top();
            heap.pop();
            cur = cur->next;
            if(heap.empty()) break;
            if(cur->next != NULL) heap.push(cur->next);
        }
        return output->next;
    }
};

// 133/133 cases passed (16 ms)
// Your runtime beats 97.77 % of cpp submissions
// Your memory usage beats 83.58 % of cpp submissions (13.1 MB)


class Solution_dc{
    /* divide-and-conquer with recursion */
    ListNode* mergeKLists(vector<ListNode*>& lists){
        return partition(lists,0,lists.size()-1);
    }

    ListNode* partition(vector<ListNode*> lists,int left, int right){
        if(left == right) return lists[left];
        if(left < right) {
            int mid = left + (right - left) /2;
            ListNode* l1 = partition(lists,left,mid);
            ListNode* l2 = partition(lists,mid+1,right);
            return mergeTwoLists(l1,l2);
        }
        return NULL;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* output = new ListNode(0);
        if(l1!=NULL && l2!=NULL){
            if(l1->val > l2->val){
                l2->next = mergeTwoLists(l1,l2->next);
                return l2;
            }
            else {
                l1->next = mergeTwoLists(l1->next,l2);
                return l1;
            }
        }
        if(l1==NULL) return l2;
        return l1;
    }
};
// 133/133 cases passed (312 ms)
// Your runtime beats 12.7 % of cpp submissions
// Your memory usage beats 5.01 % of cpp submissions (386.7 MB)


class Solution_dc_norec{
        ListNode* mergeKLists(vector<ListNode*>& lists) {
        /* divide-and-conquer without recursion */
        if(lists.empty()) return NULL;

        int n = lists.size();

        while (n>1)
        {
            int k = (n+1)/2;
            for(int i = 0; i < n/2; i++){
                lists[i] = mergeTwoLists(lists[i],lists[i+k]);
            }
            n = k;
        }
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode *new_list = new ListNode(-1);
        ListNode *temp = new_list;
        while(l1 && l2){
            if(l1->val > l2->val) {
                temp->next = l2;
                l2 = l2->next;
            }else {
                temp->next = l1;
                l1 = l1->next;
            }
            temp = temp->next;
        }
        if(l1==nullptr) {temp->next = l2;}
        else {temp->next = l1;}

        return new_list->next;

    }
};
// 133/133 cases passed (16 ms)
// Your runtime beats 97.77 % of cpp submissions
// Your memory usage beats 75.27 % of cpp submissions (13.2 MB)


int main(){
    return 0;
}
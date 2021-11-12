#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0),next(nullptr){}
    ListNode(int i):val(i),next(nullptr){}
    ListNode(int i, ListNode* p): val(i),next(p){};
};


class Solution{
private:
    // use fast and slow pointer to find the mid node
    ListNode* findMid(ListNode* head){
        ListNode* slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;   
    }

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (left!=nullptr && right != nullptr)
        {
            if(left->val < right->val){
                cur->next = left;
                left = left->next;
            }
            else{
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        if(left != nullptr) cur->next = left;
        if(right != nullptr) cur->next = right;

        return dummy->next;
        
    }
public:
    ListNode* sortList(ListNode* head){
        if(head==nullptr || head->next ==nullptr) return head; // edge cases
        // to find the mid pointer
        ListNode* mid = findMid(head);

        ListNode* right = sortList(mid->next);
        mid->next = nullptr; // cut it off
        ListNode* left = sortList(head);

        return merge(left,right);
    }
};
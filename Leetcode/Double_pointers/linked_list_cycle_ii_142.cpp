/* Floyd */
#include <vector>
#include "listNode.h"

using namespace std;

class Solution{
public:
    ListNode* floyd(ListNode* head){
        ListNode* fast = head, *slow = head;
        do{
            if(!fast || !fast->next) return nullptr; // there is no cycle
            fast = fast->next->next;
            slow = slow->next;
        }while(fast != slow);

        // reset the fast pointer
        fast = head;
        while (fast != slow)
        {
            fast=fast->next; // move only one step this time
            slow=slow->next;
        }
        // the second time of rencontrer is the start node
        return slow;
        
    }
// Your runtime beats 83.16 % of cpp submissions
// Your memory usage beats 89.11 % of cpp submissions (7.4 MB)
};

int main() {

}
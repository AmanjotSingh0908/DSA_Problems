/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* curr = head;

        while(curr && curr -> next) {
            ListNode* nxtPair = curr->next->next;
            ListNode* second = curr->next;

            //reverse the Pair
            second->next = curr;
            curr->next = nxtPair;
            prev->next = second;

            //update pointers
            prev = curr;
            curr = nxtPair;
        }
        
        return dummy.next;
    }
};

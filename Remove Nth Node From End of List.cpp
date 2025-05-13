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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* res = new ListNode(0, head);
        ListNode* dummy = res;

        //Move the head pointer n steps forward
        for(int i = 0; i < n; i++){
            head = head->next;
        }

        //Move both pointers until head reaches the end
        while(head != nullptr){
            head = head->next;
            dummy = dummy->next;
        }

        //remove the nth node from the end
        dummy->next = dummy->next->next;

        return res->next;
    }
};

// #include <vector>
// using namespace std;

// // Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Base case: if lists is empty, return nullptr
        if (lists.empty()) return nullptr;

        // Keep merging the lists pair by pair
        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;

            // Merge two lists at a time
            for (int i = 0; i < lists.size(); i += 2) {
                if (i + 1 < lists.size()) {
                    mergedLists.push_back(mergeTwoLists(lists[i], lists[i + 1]));
                } else {
                    mergedLists.push_back(lists[i]);
                }
            }

            // Update lists with the new merged lists
            lists = mergedLists;
        }

        // Return the final merged list (the only element left in lists)
        return lists[0];
    }

private:
    // Helper function to merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;

        // Merge the two lists
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        // If any list is not fully traversed, append the remaining elements
        if (l1 != nullptr) {
            current->next = l1;
        } else {
            current->next = l2;
        }

        return dummy->next;
    }
};

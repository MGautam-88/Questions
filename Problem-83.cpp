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
    ListNode* deleteDuplicates(ListNode* a) {
        ListNode* head = a;//keep track of head of the list
        while (a != nullptr && a->next !=nullptr) {
            if (a->val == a->next->val) {
                a->next = a->next->next;
            }
            else{
                a=a->next;
            }
        }

        return head;//return the head of the list
    }
};

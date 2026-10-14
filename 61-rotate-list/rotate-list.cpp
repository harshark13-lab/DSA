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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // 1. Find the length of the list and get the tail node
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        // 2. Optimize k if it's greater than the list length
        k = k % len;
        if (k == 0) return head;

        // 3. Connect tail to head to make it a circular linked list
        tail->next = head;

        // 4. Find the new tail: (len - k - 1) steps from the head
        ListNode* newTail = head;
        for (int i = 0; i < len - k - 1; ++i) {
            newTail = newTail->next;
        }

        // 5. Set the new head and break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
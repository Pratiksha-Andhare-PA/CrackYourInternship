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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr || left == right) {
            return head;
        }

        int cnt = 1;
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (cnt < left) {
            prev = temp;
            temp = temp->next;
            cnt++;
        }

        ListNode* revStart = temp;
        ListNode* next = nullptr;
        ListNode* prevptr = nullptr;
        ListNode* currptr = temp;
        while (cnt <= right) {
            next = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = next;
            cnt++;
        }

        if (revStart != nullptr) {
            revStart->next = currptr;
        } else {
            head = prevptr;
        }

        if (prev != nullptr) {
            prev->next = prevptr;
        } else {
            head = prevptr;
        }

        return head;
    }
};

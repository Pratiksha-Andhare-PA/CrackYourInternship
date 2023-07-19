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
    ListNode* partition(ListNode* head, int x) {
        ListNode lessNode(0);
        ListNode greatNode(0);

        ListNode* lessptr = &lessNode;
        ListNode* greatptr = &greatNode;

        ListNode* temp = head;
        while(temp){
            if(temp->val < x){
                lessptr->next = temp;
                lessptr = lessptr->next;
            }
            else{
                greatptr->next = temp;
                greatptr = greatptr->next;
            }
            temp = temp->next;
        }
        lessptr->next = greatNode.next;
        greatptr->next = NULL;

        ListNode* newHead = lessNode.next;
        return newHead;
    }
};

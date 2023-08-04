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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prevptr = NULL;
        ListNode* currptr = head;
        ListNode* nextptr;

        int count = 0;
        while(count<k && currptr){
            nextptr = currptr->next;
            currptr->next = prevptr;

            prevptr = currptr;
            currptr = nextptr;

            count++;
        }

        if(count == k){
            head->next = reverseKGroup(currptr, k);
            return prevptr;
        }
        else{
            ListNode* newHead = NULL;
            while(prevptr){
                nextptr = prevptr->next;
                prevptr->next = newHead;

                newHead = prevptr;
                prevptr = nextptr;
            }
            return newHead;
        }
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    int len(ListNode* &head){
        ListNode* temp = head;
        int l = 0;
        while(temp != NULL){
            temp = temp->next;
            l++;
        }
        return l;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = len(headA);
        int l2 = len(headB);

        ListNode* ptr1;
        ListNode* ptr2;

        if(l1 > l2){
            ptr1 = headA;
            ptr2 = headB;
        }
        else{
            ptr1 = headB;
            ptr2 = headA;
        }
        int d = abs(l1-l2);
        while(d && ptr1!=NULL){
            ptr1 = ptr1->next;
            d--;
        }

        while(ptr1 && ptr2){
            if(ptr1 == ptr2){
                return ptr1;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return NULL;
    }
};

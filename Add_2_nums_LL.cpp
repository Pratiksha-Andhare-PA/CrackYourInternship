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

    ListNode* rev(ListNode* &head){
        ListNode* prevptr = nullptr;
        ListNode* currptr = head;
        ListNode* nextptr;

        while(currptr != nullptr){
            nextptr = currptr->next;
            currptr->next = prevptr;

            prevptr = currptr;
            currptr = nextptr;
        }
        return prevptr;
    } 

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = rev(l1);
        l2 = rev(l2);
        
        ListNode* dummyNode = new ListNode(-1);
        ListNode* l3 = dummyNode;

        int carry=0, sum=0;
        while(l1!=nullptr || l2!=nullptr || carry != 0){
            sum = carry;
            if(l1 != nullptr){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            sum %= 10;

            l3->next = new ListNode(sum);
            l3 = l3->next;
        }
        l3 = rev(dummyNode->next);
        return l3;
    }
};

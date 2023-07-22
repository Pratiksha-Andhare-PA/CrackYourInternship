#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    
    node(int val){
        data = val;
        next = NULL;
    }
};

void Insert(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* &head){
    node* temp = head;
    while(temp){
        cout<< temp->data <<"->";
        temp = temp->next;
    }
    cout<< "NULL" <<endl;
}

int len(node* &head){
    node* temp = head;
    int l=0;
    while(temp){
        temp = temp->next;
        l++;
    }
    return l;
}

node* revLL(node* &head){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    
    while(currptr != NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;
        
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

void RearrangeLL(node* &head){
    int l = len(head);
    if (l <= 2) return; // Nothing to rearrange if the length is 0, 1, or 2.

    node* temp = head;
    for (int i = 0; i < l/2; i++) {
        temp = temp->next;
    }
    node* head1 = head;
    node* head2 = temp->next;
    temp->next = NULL; // Break the original list into two halves.
    head2 = revLL(head2);

    node* newHead = new node(0); // Using a dummy node
    node* newLL = newHead;
    while (head1 || head2) {
        if (head1) {
            newLL->next = head1;
            newLL = newLL->next;
            head1 = head1->next;
        }
        if (head2) {
            newLL->next = head2;
            newLL = newLL->next;
            head2 = head2->next;
        }
    }
    head = newHead->next; // Update the head of the linked list.
    delete newHead; // Free the dummy node.
}

int main(){
    node* head = NULL;
    Insert(head, 1);
    Insert(head, 2);
    Insert(head, 3);
    Insert(head, 4);
    Insert(head, 5);
    Insert(head, 6);
    
    cout << "Original Linked List: ";
    display(head);

    RearrangeLL(head);
    
    cout << "Rearranged Linked List: ";
    display(head);

    return 0;
}

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

node* SegregateLL(node* &head){
    node* evenLL = NULL;
    node* oddLL = NULL;
    node* evenTail = NULL;
    node* oddTail = NULL;
    
    node* temp = head;
    while(temp){
        if(temp->data % 2 == 0){
            if(evenLL == NULL){
                evenLL = temp;
                evenTail = temp;
            }
            else{
                evenTail->next = temp;
                evenTail = evenTail->next;
            }
        }
        else{
            if(oddLL == NULL){
                oddLL = temp;
                oddTail = temp;
            }
            else{
                oddTail->next = temp;
                oddTail = oddTail->next;
            }
        }
        temp = temp->next;
    }
    
    if(evenLL){
        evenTail->next = oddLL;
    }
    if(oddLL){
        oddTail->next = NULL;
    }
    else{
        evenTail->next = NULL;
    }
    return evenLL? evenLL : oddLL;
}

int main(){
    node* head = NULL;
    Insert(head,8);
    Insert(head,12);
    Insert(head,10);
    Insert(head,5);
    Insert(head,4);
    Insert(head,1);
    Insert(head,6);
    
    display(head);
    node* newHead = SegregateLL(head);
    display(newHead);
    
    return 0;
}
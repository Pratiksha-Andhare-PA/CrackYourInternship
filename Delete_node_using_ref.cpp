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
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<< endl;
}

void deleteNode(node* &head){
    node* prev;
    if(head == NULL){
        return;
    }
    node* todelete = head->next;
    head->data = todelete->data;
    
    head->next = todelete->next;
    delete todelete;
}

int main(){
    node* head = NULL;
    Insert(head,1);
    Insert(head,2);
    Insert(head,3);
    Insert(head,4);
    
    display(head);
    deleteNode(head->next->next);    // 3rd node to be deleted
    display(head);
    
    return 0;
}
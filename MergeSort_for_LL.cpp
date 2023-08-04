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

int len(node* &head){
    int l = 0;
    node* temp = head;
    while(temp){
        l++;
        temp = temp->next;
    }
    return l;
}

void Insert(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return ;
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
        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<< endl;
}

void split(node* &head, node* &a, node* &b) {
    a = head;
    node* slow = head;
    node* fast = head->next; // Move fast ahead of slow initially
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    b = slow->next; // b starts from the middle of the list
    slow->next = NULL; // Terminate the first sublist
}


node* Merge(node* &a, node* &b){
    node* ans = NULL;
    if(!a){
        return b;
    }
    if(!b){
        return a;
    }
    
    if(a->data < b->data){
        ans = a;
        ans->next = Merge(a->next, b);
    }
    else{
        ans = b;
        ans->next = Merge(a, b->next);
    }
    
    return ans;
}


void MergeSort(node* &head){
    node* newhead = head;
    node* a;
    node* b;
    
    if(head == NULL || head->next == NULL){
        return;
    }
    
    split(head, a, b);
    
    MergeSort(a);
    MergeSort(b);
    
    head = Merge(a,b);
}

int main(){
    node* head = NULL;
    Insert(head,15);
    Insert(head,10);
    Insert(head,5);
    Insert(head,20);
    Insert(head,3);
    Insert(head,2);
    
    //display(head);
    MergeSort(head);
    display(head);
    
    return 0;
}
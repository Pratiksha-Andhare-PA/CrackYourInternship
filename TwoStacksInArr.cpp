#include<iostream>
using namespace std;

class twoStacks{
    int *arr;
    int size;
    int top1,top2;
    
public:
    twoStacks(int n){
        arr = new int[n];
        top1 = -1;
        size = n;
        top2 = size;
    }
    
    void push1(int x){
        if(top1 < top2-1){
            top1++;
            arr[top1] = x;
        }
        else{
            cout<< "Stack Overflow!" <<endl;
            exit(1);
        }
    }
    
    void push2(int x){
        if(top1 < top2-1){
            top2--;
            arr[top2] = x;
        }
        else{
            cout<< "Stack Overflow!" <<endl;
            exit(1);
        }
    }
    
    int pop1(){
        if(top1 >= 0){
            int temp = arr[top1];
            top1--;
            return temp;
        }
        else{
            return -1;
        }
    }
    
    int pop2(){
        if(top2 < size){
            int temp = arr[top2];
            top2--;
            return temp;
        }
        else{
            return -1;
        }
    }
};

int main(){
    twoStacks ts(5);
    ts.push1(10);
    ts.push2(20);
    ts.push1(30);
    ts.push1(40);
    ts.push2(50);
    // ts.push1(60);
    
    int x = ts.pop1();
    if(x == -1)
        cout<< "Stack Underflow!" <<endl;
    else
        cout<< "Element popped from stack1 = "<< x <<endl;
        
    int y = ts.pop2();
    if(y == -1)
        cout<< "Stack Underflow!" <<endl;
    else
        cout<< "Element popped from stack2 = "<< y <<endl;
    
    return 0;
}
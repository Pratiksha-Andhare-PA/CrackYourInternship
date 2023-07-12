#include<iostream>
using namespace std;

void CombinationUtil(int arr[],int data[],int idx,int n,int r,int i){
    if(idx == r){
        for(int j=0;j<r;j++){
            cout<< data[j] << " ";
        }
        cout<< endl;
        return ;
    }
    
    if(i >= n){
        return ;
    }
    
    data[idx] = arr[i];
    CombinationUtil(arr,data,idx+1,n,r,i+1);
    CombinationUtil(arr,data,idx,n,r,i+1);
}

void printCombination(int arr[],int n,int r){
    int data[r];
    CombinationUtil(arr,data,0,n,r,0);
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    int r = 3;
    printCombination(arr,n,r);
    
    return 0;
}
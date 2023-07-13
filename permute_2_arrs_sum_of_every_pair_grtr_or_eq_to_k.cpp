#include<iostream>
#include<algorithm>
using namespace std;

bool isPossible(int a[],int b[],int n,int k){
    sort(a,a+n);
    sort(b,b+n,greater<int>());
    
    for(int i=0;i<n;i++){
        if(a[i] + b[i] < k){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cout<< "Enter size: ";
    cin>> n;
    int a[n],b[n];
    
    cout<< "Enter elements of an array a : ";
    for(int i=0;i<n;i++){
        cin>> a[i];
    }
    
    cout<< "Enter elements of an array b : ";
    for(int i=0;i<n;i++){
        cin>> b[i];
    }
    
    int k;
    cout<< "Enter k : ";
    cin>> k;
    
    if(isPossible(a,b,n,k)){
        cout<< "Yes" <<endl;
    }
    else{
        cout<< "No" <<endl;
    }
    
    return 0;
}
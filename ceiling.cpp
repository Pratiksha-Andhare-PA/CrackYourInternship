#include<iostream>
using namespace std;

int ceilingNum(int arr[],int x,int start,int end){
    if(x > arr[end]){
        return -1;
    } 
    if(x <= arr[start]){
        return start;
    }
    int mid = (start+end)/2;
    if(arr[mid] == x){
        return mid;
    }
    else if(arr[mid] < x){
        if(arr[mid+1] >= x && mid+1<=end){
            return mid+1;
        }
        return ceilingNum(arr,x,mid+1,end);
    }
    else{
        if(arr[mid-1] < x && mid-1>=start){
            return mid;
        }
        return ceilingNum(arr,x,mid-1,end);
    }
}

int main(){
    int n;
    cout<< "Enter size of an array : ";
    cin>> n;
    int arr[n];
    cout<< "Enter an array : ";
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }
    int x;
    cout<< "Enter x : ";
    cin>> x;
    if(ceilingNum(arr,x,0,n-1) == -1){
        cout<< "No ceiling exists for this number!" <<endl;
    }
    else{
        cout<<"Ceiling of "<< x <<" is " <<ceilingNum(arr,x,0,n-1) <<endl;
        
    }
    
    
    return 0;
}
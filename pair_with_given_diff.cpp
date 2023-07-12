#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void findPair(vector<int> &arr,int k,int start,int end){
    sort(arr.begin(),arr.end());
    for(int i=start;i<=end;i++){
        int dif = abs(arr[start]-arr[end]);
        if(dif == k){
            cout<< arr[start] << " " <<arr[end] <<endl;
            return;
        }
        else if(dif > k){
            end--;
        }
        else{
            start++;
        }
    }
    cout<< "No such pair exist!" <<endl;
}

int main(){
    vector<int> arr = {5, 20, 3, 2, 50, 80};
    int n = arr.size();
    int k = 78;
    
    int start = 0;
    int end = n-1;
    
    findPair(arr,k,start,end);
    
    return 0;
}
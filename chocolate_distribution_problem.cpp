#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int minDiff(vector<int> &arr,int m){
    
    vector<int> res;
    sort(arr.begin(),arr.end());
    int n = arr.size();
    
    if(m ==0 || n == 0){
        return 0;
    }
    
    if(n < m){
        return -1;
    }
    
    for(int i=0;i<=n-m;i++){
        int mx = INT_MIN;
        int mn = INT_MAX;
        for(int j=i;j<m+i;j++){
            if(arr[j] > mx){
                mx = arr[j];
            }
            if(arr[j] < mn){
                mn = arr[j];
            }
        }
        res.push_back(mx - mn);
    }
    sort(res.begin(),res.end());
    return res[0];
}

int main(){
    int n;
    cout<< "Enter n : ";
    cin >>n;
    cout<< "Enter vector : ";
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>> v[i];
    }
    // 7, 3, 2, 4, 9, 12, 56
    int m;
    cout<< "Enter m : ";
    cin>> m; // 3
    
    cout<< minDiff(v,m);
    
    return 0;
}
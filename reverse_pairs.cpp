class Solution {
public:

    int mergeSort(vector<int> &nums,int start,int end){
        if(start >= end){
            return 0;
        }
        int mid = start+(end-start)/2;
        int count = mergeSort(nums,start,mid) + mergeSort(nums,mid+1,end);

        int i = start;
        int j = mid+1;
        while(i <= mid && j<=end){
            if(static_cast<long long>(nums[i]) > static_cast<long long>(2)*nums[j]){
                count += mid-i+1;
                j++;
            }
            else{
                i++;
            }
        }
        sort(nums.begin()+start, nums.begin()+ end +1);
        return count;

    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums,0,n-1);        
    }
};

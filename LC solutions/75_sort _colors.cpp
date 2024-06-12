#include <bits/stdc++.h>
using namespace std;
class Solution {
    int pivot(vector<int> &arr,int s,int e){
        int pivotindex=s;
        int pivot=arr[s];

        int i=s;
        int j=e;

        while(i<j){
            while(arr[i]<=pivot and i<e){
                i++;
            }
            while(arr[j]>pivot and j>=s){
                j++;
            }

            if (i<j){
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[pivotindex],arr[j]);
        return j;
    }
    void quick(vector<int> &arr,int low,int high){
        if (low<high){
            int pi=pivot(arr,low,high);

            quick(arr,low,pi-1);
            quick(arr,pi+1,high);
        }
    }
public:
    void sortColors(vector<int>& nums) {
        int n=size(nums);
        int zero=0;
        int one=0;
        int two=n-1;

        // while(one<=two){
        //     if(nums[one]==1){
        //         one++;
        //     }
        //     else if(nums[one]==0){
        //         swap(nums[one],nums[zero]);
        //         zero++;
        //     }
        //     else {
        //         swap(nums[one],nums[two]);
        //         two--;
        //     }
        // }

        quick(nums,0,n-1);

    }
};


#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3", "unroll-loops")
auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    void bubbleSort(vector<int> &temp){
        for (int i=0;i<size(temp)-1;i++){
            // int element=temp[i];
            for (int j=0;j<size(temp)-i-1;j++){
                if (temp[j]>temp[j+1]){
                    swap(temp[j],temp[j+1]);
                }
            }
        }
    }
    void selectionsort(vector<int> &temp){
        for (int i=0;i<size(temp);i++){
            int element=temp[i];
            int ind=i;
            for (int j=i+1;j<size(temp);j++){
                if (temp[j]<temp[ind]){
                    ind=j;
                }
            }
            swap(temp[ind],temp[i]);
        }
    }
    void insertionsort(vector<int> &temp){
        for (int i=0;i<size(temp);i++){
            int currind=i;
            while(currind>0 and temp[currind-1]>temp[currind]){
                swap(temp[currind-1],temp[currind]);
                currind--;
            }
        }
    }

    void countsort(vector<int> &temp){
        int max_ele=-1e9;
        for (auto i:temp){
            max_ele=max(max_ele,i);
        }

        vector<int> counts(max_ele+1,0);

        for (int i=0;i<size(temp);i++){
            counts[temp[i]]++;
        }   
        int startindex=0;
        for (int i=0;i<=max_ele;i++){
            int count=counts[i];
            counts[i]=startindex;
            startindex+=count;
        }
        vector<int> sorted(temp);
        for (int i=0;i<size(temp);i++){
            sorted[counts[temp[i]]]=temp[i];
            counts[temp[i]]++;
        }
        temp=sorted;
    }

    void radixcount(vector<int> &temp,int placeval){
        vector<int> counts(10,0);
        for (int i=0;i<size(temp);i++){
            int element=(temp[i]/placeval);
            counts[element%10]++;
        }
        int startindex=0;
        for (int i=0;i<size(counts);i++){
            int count=counts[i];
            counts[i]=startindex;
            startindex+=count;
        }
        vector<int> sorted(temp);
        for (int i=0;i<size(temp);i++){
            int element=(temp[i]/placeval);

            sorted[counts[element%10]]=temp[i];
            counts[element%10]++;
        }
        temp=sorted;
    }

    void radix(vector<int> &temp){
        int max_ele=-1e9;
        for(auto i:temp){
            max_ele=max(max_ele,i);
        }

        int placeval=1;

        while(max_ele/placeval>0){
            radixcount(temp,placeval);
            placeval*=10;
        }
    }
    int pivot(vector<int> &arr,int low,int high){
        int pivotindex=low;
        int val=arr[pivotindex];

        int i=low;
        int j=high;

        while(i<j){
            while(arr[i]<=val and i<high){
                i++;
            }
            while(arr[j]>val and j>=low){
                j--;
            }
            if (i<j){swap(arr[i],arr[j]);}
        }

        swap(arr[pivotindex],arr[j]);
        return j;
    }
    void quicksort(vector<int> &arr,int low,int high){
        if (low<high){
            int pi=pivot(arr,low,high);

            quicksort(arr,low,pi-1);
            quicksort(arr,pi+1,high);
        } 
    }

    void merge(vector<int> &arr,int low,int high){
        int mid=low+(high-low)/2;
        vector<int> left;
        vector<int> right;

        for (int i=low;i<=mid;i++){
            left.push_back(arr[i]);
        }
        for (int i=mid+1;i<=high;i++){
            right.push_back(arr[i]);
        }
        int m=size(left),n=size(right);
        int i=0;
        int j=0;
        int k=low;
        while(i<m and j<n){
            if (left[i]<=right[j]){
                arr[k++]=left[i++];
            }
            else {
                arr[k++]=right[j++];
            }
        }
        while(i<m){
            arr[k++]=left[i++];
        }
        while(j<n){
            arr[k++]=right[j++];
        }
    }
    void mergesort(vector<int> &arr,int low,int high){
        if (low<high){
            int mid=low+(high-low)/2;

            mergesort(arr,low,mid);
            mergesort(arr,mid+1,high);
            merge(arr,low,high);
        }
    }
    int heightChecker(vector<int>& heights) {
        vector<int> temp(heights);
        mergesort(temp,0,size(heights)-1);
        // countsort(temp);
        int count=0;

        for (int i=0;i<size(heights);i++){
            cout<<temp[i]<<" ";
            if (heights[i]!=temp[i]){
                count++;
            }
        }
        return count;
    }
};


int main() {
    Solution s;
    vector<int> heights={1,4,3,5,6,7,3};
    s.heightChecker(heights);
    return 0;
}


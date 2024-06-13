
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void countsort(vector<int>& arr){
        int maxele=-1e9;
        for (auto i:arr){
            maxele=max(maxele,i);
        }
        vector<int> counts(maxele+1,0);
        for (int i=0;i<arr.size();i++){
            counts[arr[i]]++;
        }
        int startindex=0;
        for (int i=0;i<=maxele;i++){
            int count=counts[i];
            counts[i]=startindex;
            startindex+=count;
        }
        vector<int> sorted(arr);
        for(int i=0;i<size(arr);i++){
            sorted[counts[arr[i]]]=arr[i];
            counts[arr[i]]++;
        }
        arr=sorted;
    }
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        countsort (seats);
        countsort (students);
        int ans=0;
        for (int i=0;i<size(students);i++){
            ans+=abs(seats[i]-students[i]);
        }
        return ans;

    }
};
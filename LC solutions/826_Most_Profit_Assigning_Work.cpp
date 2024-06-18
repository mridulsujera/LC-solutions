#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=size(profit);
        vector<pair<int,int>> combine(n);

        for (int i = 0; i < n; i++)
        {
            combine[i]={difficulty[i],profit[i]};
        }
        int  ans=0;
        sort(combine.begin(),combine.end());
        sort(worker.begin(),worker.end());
        priority_queue<int> pq;
        int j=0;
        for (int i=0;i<size(worker);i++){
            while(j<size(combine) and combine[j].first<=worker[i]){
                pq.push(combine[j].second);
            }

            if (pq.empty()){
                ans+=0;
            }
            else{
                ans+=pq.top();
            }
        }
        return ans;

        
    }
};
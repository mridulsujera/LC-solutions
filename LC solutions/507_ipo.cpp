#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n=size(profits);
        vector<pair<int,int>> res;
        for (int i=0;i<n;i++){
            res.push_back({capital[i],profits[i]});
        }

        sort(begin(res),end(res));
        priority_queue<int> pq;
        int j=0;
        for (int i=0;i<k;i++){
            while (j<n and w>=res[j].first)
            {
                pq.push(res[j].second);
                j++;
            }

            if (!pq.empty()){
                w+=pq.top();
                pq.pop();
            }else{
                break;
            }
        }

        return w;

    }
};
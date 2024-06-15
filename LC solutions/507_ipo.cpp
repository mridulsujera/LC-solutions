#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profit, vector<int>& capital) {
        vector<pair<int,int>> tosort;
        for (int i=0;i<size(profit);i++){
            tosort.push_back({capital[i],profit[i]});
        }

        sort(tosort.begin(),tosort.end(),[](auto a,auto b) {
            if (a.first!=b.first){
                return a.first<b.first;
            }else{
                return a.second>b.second;
            }
        });
    }
};

int main() {
    
    return 0;
}
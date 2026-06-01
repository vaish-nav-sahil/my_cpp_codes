class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int n=cost.size(),i=0,total_cost=0;
        while(i<n ){
            if (i+1<n) total_cost=total_cost+cost[i]+cost[i+1];
            else total_cost+=cost[i];
            i=i+3;
        }
        return total_cost;
    }
};

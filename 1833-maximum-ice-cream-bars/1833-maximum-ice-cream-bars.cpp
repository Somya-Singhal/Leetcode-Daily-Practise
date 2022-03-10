class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int amount=0,taken=0;
        for(int i=0;i<costs.size();i++)
        {
            amount+=costs[i];
            if(amount>coins)
                break;
            taken++;
        }
        return taken;
    }
};
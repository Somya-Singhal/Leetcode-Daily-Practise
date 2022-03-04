class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        if(n<=2)
            return n;
        int lastFruit=-1,secondLastFruit=-1;
        int lastFruitCount=0;
        int currmax=0,ans=0;
        for(int i=0;i<n;i++)
        {
            if(fruits[i]==lastFruit || fruits[i]==secondLastFruit)
            {
                currmax++;
            }
            else
            {
                currmax=lastFruitCount+1;
            }
            if(fruits[i]==lastFruit)
            {
                lastFruitCount++;
            }
            else
            {
                secondLastFruit=lastFruit;
                lastFruit=fruits[i];
                lastFruitCount=1;
            }
            ans=max(ans,currmax);
        }
        return ans;
        
    }
};
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>res;
        stack<int>s;
        res.push_back(0); //always 0 for last element
        s.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!s.empty() && temperatures[s.top()]<=temperatures[i])
                s.pop();
            int a=s.empty()?0:s.top()-i;
            res.push_back(a);
            s.push(i);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int>res;
        stack<int>s;
        s.push(asteroids[0]);
        int i=1;
        while(i<n)
        {
            bool flag=false;
            while(!s.empty() && s.top()>0 && asteroids[i]<0)
            {
                int num=abs(asteroids[i]);
                if(s.top()<num)
                {
                    s.pop();
                }
                else
                {
                    if(s.top()==num)
                        s.pop();
                    flag=true;
                    break;
                }
            }
            if(asteroids[i]>0 || !s.empty() && (!flag && s.top()<0 && asteroids[i]<0) || (s.empty() && !flag))
            s.push(asteroids[i]);
            i++;
        }
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
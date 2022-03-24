class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>count(26,0);
        int n=s.length();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            count[s[i]-'a']++;
        }
        int prev=0;
        unordered_set<char>st;
        for(int i=0;i<n;i++)
        {
            st.insert(s[i]);
            count[s[i]-'a']--;
            bool flag=false;
            for(auto x: st)
            {
                if(count[x-'a']!=0)
                {
                    flag=true;
                     break;
                }
            }
            if(flag==false)
            {
               ans.push_back(i-prev+1);
               prev=i+1; 
               st.clear();
            }     
            
        }
        return ans;
    }
};
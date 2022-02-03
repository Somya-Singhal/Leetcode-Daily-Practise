class Solution {
public:
    //window sliding
    bool aresame(vector<int>count1,vector<int>count2)
    {
        for(int i=0;i<26;i++)
        {
            count1[i]-=count2[i];
        }
        for(int i=0;i<26;i++)
        {
            if(count1[i]!=0)
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>count1(26,0),count2(26,0);
        vector<int>idx;
        int n1=s.length(),n2=p.length();
        if(n1<n2)
            return idx;
        for(int i=0;i<n2;i++)
        {
            count1[s[i]-'a']++;
            count2[p[i]-'a']++;
        }
        int i;
        for(i=n2;i<n1;i++)
        {
            if(aresame(count1,count2))
                idx.push_back(i-n2);
            count1[s[i-n2]-'a']--;
            count1[s[i]-'a']++;
        }
        if(aresame(count1,count2))
                idx.push_back(i-n2);
        return idx;
    }
};
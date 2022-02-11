class Solution {
public:
    bool aresame(vector<int>& count1,vector<int>& count2)
    {
        vector<int>temp=count2;
        for(int i=0;i<26;i++)
        {
            if(count1[i]!=0)
                temp[i]-=count1[i];
        }
        for(int i=0;i<26;i++)
        {
            if(temp[i]!=0)
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();
        if(n1>n2)
            return false;
        vector<int>count1(26,0),count2(26,0);
        for(int i=0;i<n1;i++)
        {
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;
        }
        for(int i=n1;i<n2;i++)
        {
            if(aresame(count1,count2))
                return true;
            count2[s2[i-n1]-'a']--;
            count2[s2[i]-'a']++;
        }
        return aresame(count1,count2);
    }
};
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        int n=words.size();
        vector<string>freq{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string>s;
        for(int i=0;i<n;i++)
        {
            string curr="";
            for(int j=0;j<words[i].length();j++)
            {
                curr+=freq[words[i][j]-'a'];
            }
            s.insert({curr});
        }
        return s.size();
    }
};
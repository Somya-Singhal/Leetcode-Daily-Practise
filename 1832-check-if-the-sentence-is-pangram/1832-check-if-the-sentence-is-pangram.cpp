class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n=sentence.length();
        set<char>s;
        for(int i=0;i<n;i++)
            s.insert(sentence[i]);
        return s.size()==26;
    }
};
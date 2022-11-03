class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>words_map;
        for(auto w: words)
        {
            words_map[w]+=1;
        }
        int count=0,odd=0;
        for(auto w: words_map)
        {
            string orig=w.first;
            string rev=orig;
            reverse(rev.begin(),rev.end());
            
            if(orig[0]==orig[1])
            {
                if(words_map[orig]%2)
                    count+=words_map[orig]-1;
                else
                    count+=words_map[orig];
                odd |= words_map[orig]%2;
            }  
            else if(words_map.find(rev)!=words_map.end())
            {
                
                count+=min(words_map[orig],words_map[rev]);
            }
        }
        return (count+odd)*2;
    }
};
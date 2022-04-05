class Encrypter {
public:
//     unordered_map<char,string>m;
//     unordered_map<string,vector<char>>dec;
//     unordered_set<string>s;
//     Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
//         int k=keys.size(),v=values.size();
//         int d=dictionary.size();
//         for(int i=0;i<k;i++)
//         {
//             m.insert({keys[i],values[i]});
//         }
//         for(int i=0;i<v;i++)
//         {
//             dec[values[i]].push_back(keys[i]);
//         }
//         for(int i=0;i<d;i++)
//         {
//             s.insert(dictionary[i]);
//         }
//     }
    
//     string encrypt(string word1) {
//         int n=word1.length();
//         string res="";
//         for(int i=0;i<n;i++)
//         {
//             res+=m[word1[i]];
//         }
//         return res;
//     }
//     unordered_set<string>coll;
//     void solve(string str,int idx,string word2){
//         if(idx==word2.length())
//         {
//             coll.insert({str});
//             return;
//         }
//         for(auto x: dec[word2.substr(idx,2)])
//         {
//             solve(str+x,idx+2,word2);
//         }
//     }
//     int decrypt(string word2) {
//         solve("",0,word2);
//         // for(auto x: coll)
//         //     cout<<x<<" ";
//         // cout<<"\n";
//         int count=0;
//         for(auto x: coll){
//             if(s.find(x)!=s.end())
//                 count++;
//         }
//          coll.clear();
//         return vis[word2]=count;
//     }
// };

    
     unordered_map<char,string>m;
    unordered_map<string,int>dec;
   
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        int k=keys.size(),v=values.size();
        int d=dictionary.size();
        for(int i=0;i<k;i++)
        {
            m.insert({keys[i],values[i]});
        }
       for(auto x: dictionary){
           string str=x,decrypt_str="";
           bool flag=false;
           for(int i=0;i<str.length();i++)
           {
               if(m.find(str[i])==m.end())
               {
                   flag=true;
                   break;
               }
               decrypt_str+=m[str[i]];
           }
           if(!flag)
           dec[decrypt_str]++;
       }
    }
    
    string encrypt(string word1) {
        int n=word1.length();
        string res="";
        for(int i=0;i<n;i++)
        {
            res+=m[word1[i]];
        }
        return res;
    }
    int decrypt(string word2) {
       return dec[word2];
    }
};

    
/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
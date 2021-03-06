/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
   //     vector<int>res;
//     int curr=0;
//     void helper(vector<NestedInteger> &nestedList)
//     {
//         for(int i=0;i<nestedList.size();i++)
//         {
//             if(nestedList[i].isInteger())
//                 res.push_back(nestedList[i].getInteger());
//             else
//                 helper(nestedList[i].getList());
//         }
//     }
//     NestedIterator(vector<NestedInteger> &nestedList) {
//         helper(nestedList);
//     }
    
//     int next() {
//         int ans=-1;
//         if(curr<res.size())
//         {
//             ans=res[curr];
//             curr++;
//         }
//         return ans;
//     }
    
//     bool hasNext() {
//         return curr<res.size();
//     }
    
    
    stack<NestedInteger>s;
    NestedIterator(vector<NestedInteger> &nestedList) {
       prepare(nestedList);
    }
    
    int next() {
      if(!hasNext())
      {
         return -1; 
      }
       int ans=s.top().getInteger();
        s.pop();
        return ans;
    }
    
    bool hasNext() {
        while(!s.empty() && !s.top().isInteger())
        {
            NestedInteger curr=s.top();
            s.pop();
            vector<NestedInteger>list=curr.getList();
            prepare(list);
        }
        return !s.empty();
    }
    
    void prepare(vector<NestedInteger> &nestedList)
    {
       for(int i=nestedList.size()-1;i>=0;i--)
       {
           s.push(nestedList[i]);
       } 
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

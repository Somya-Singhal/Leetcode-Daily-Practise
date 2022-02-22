/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* solve(int s,int e,int len,vector<vector<int>>& grid){
        if(len==1)
        {
            return new Node(grid[s][e]!=0,true,NULL,NULL,NULL,NULL);
        }
        Node* currNode=new Node();
        Node* topl=solve(s,e,len/2,grid);
        Node* topr=solve(s,e+len/2,len/2,grid);
        Node* bottoml=solve(s+len/2,e,len/2,grid);
        Node* bottomr=solve(s+len/2,e+len/2,len/2,grid);
        if(topl->isLeaf && topr->isLeaf && bottoml->isLeaf && bottomr->isLeaf && topl->val==topr->val && topr->val==bottoml->val && bottoml->val==bottomr->val){
           
            currNode->val=topr->val;
            currNode->isLeaf=true;
        }
        else {
            currNode->topLeft=topl;
            currNode->topRight=topr;
            currNode->bottomLeft=bottoml;
            currNode->bottomRight=bottomr;
        }
        return currNode;
    }
    Node* construct(vector<vector<int>>& grid) {
        int row=grid.size();
        return solve(0,0,row,grid);
    }
};
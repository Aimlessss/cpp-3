#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int input){
        this->val = input;
        this->right = nullptr;
        this->left = nullptr;
    }
};
    unordered_map<TreeNode*, TreeNode*> mp;
    TreeNode* startNode;
    void buildGraph(TreeNode* root, int start){
        if(!root) return;

        if(start == root->val){
            startNode = root;
        }
        if(root->left){
            mp[root->left] = root;
        }
        buildGraph(root->left, start);
        if(root->right){
            mp[root->right] = root;
        }
        buildGraph(root->right, start);
    }
    void bfs(TreeNode* startNode, int time){
        queue<TreeNode*>q;
        unordered_set<int>vis;
        q.push(startNode);
        vis.insert(startNode->val);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode* curr = q.front(); q.pop();
                if(curr->left && !vis.count(curr->val)){
                    q.push(curr->left);
                }
                if(curr->right && !vis.count(curr->val)){
                    q.push(curr->right);
                }
                if(mp.count(curr) && !vis.count(mp[curr]->val)){
                    q.push(mp[curr]);
                }
            }
            time++;
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;
        startNode = NULL;
        buildGraph(root, start);
        int time = 0;
        bfs(startNode, time);
        return time;
    }

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    return 0;
}
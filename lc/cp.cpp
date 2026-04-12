#include<bits/stdc++.h>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        this->val = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};
    unordered_map<TreeNode*, TreeNode*>parent;
    set<int>toDel;
    vector<TreeNode*>res;
    void solve(TreeNode* root){
        if(!root)return;

        if(root->left){
            parent[root->left] = root;
        }
        if(root->right){
            parent[root->right] = root;
        }
        solve(root->left);
        solve(root->right);
    }

    void toDelete(vector<int>& toDelete){
        for(int i = 0; i < toDelete.size(); i++){
            toDel.insert(toDelete[i]);
        }
    }
    void dfs(TreeNode* root){
        if(!root) return;

        if(root->left){
            dfs(root->left);
        }
        if(toDel.find(root->val) != toDel.end()){
            parent[root] = nullptr;
            res.push_back(root->left);
            res.push_back(root->right);
        }
        if(root->right){
            dfs(root->right);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root)return{};
        solve(root);
        toDelete(to_delete);
        dfs(root);
    }

int main(){
    vector<int>v = {4,5,2,1};
    vector<int>q = {3, 10, 21};

}
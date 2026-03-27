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

    unordered_map<TreeNode*, TreeNode*>mp;
    void createGraph(TreeNode* root){
        if(!root)return;
        if(root->left){
            mp[root->left] = root;
        }
        if(root->right){
            mp[root->right] = root;
        }
        createGraph(root->left);
        createGraph(root->right);
    }
    TreeNode* findStartValue(TreeNode* root, int startValue){
        if(!root) return nullptr;

        if(root->val == startValue){
            return root;
        }

        TreeNode* leftResult = findStartValue(root->left, startValue);
        if(leftResult) return leftResult;

        TreeNode* rightResult = findStartValue(root->right, startValue);
        return rightResult;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        if(!root) return "";
        createGraph(root);
        TreeNode* startValueNode = findStartValue(root, startValue);
        queue<pair<TreeNode* ,string>>q;
        q.push({startValueNode, ""});
        unordered_set<TreeNode*>vis;
        vis.insert(startValueNode);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto [curr, currPath] = q.front();q.pop();
                if(curr->val = destValue) return currPath;
                if(curr->left && !vis.count(curr->left)){
                    q.push({curr->left, currPath + 'L'});
                    vis.insert(curr->left);
                }
                if(curr->right && !vis.count(curr->left)){
                    q.push({curr->right, currPath + 'L'});
                    vis.insert(curr->right);
                }
                if(mp.find(curr)!= mp.end() && !vis.count(mp[curr])){
                    q.push({mp[curr], currPath + 'U'});
                    vis.insert(mp[curr]);
                }
            }
        }
        return "";
    }


int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(4);
    cout<<getDirections(root, 3, 6);
    return 0;
}
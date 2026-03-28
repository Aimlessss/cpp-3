#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        this->val = x;
        left = nullptr;
        right = nullptr;
    }
};

    struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    unordered_map<TreeNode*, TreeNode*>parent;
    vector<TreeNode* >leafs;
    bool check(ListNode* head, TreeNode* root){
        if(!head || !root)return false;
        if(head->val != root->val)[
            return false;
        ]
        return check(head->next, root->left) || check(head->next, root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head || !root)return false;

        return check(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
    void createGraph(TreeNode* root, ListNode* list){
        if(!root)return;
        if(root->left){
            parent[root->left] = root;
        }
        if(root->right){
            parent[root->right] = root;
        }

        if(!root->left && !root->right){
            leafs.push_back(root);
        }
        createGraph(root->left);
        createGraph(root->right);
    }
    int dfs(TreeNode* leaf, int distance, unordered_map<TreeNode*, int>& visLeafs){
        if(!leaf)return 0;
        int count = 0;
        queue<pair<TreeNode*, int>>q;
        unordered_set<TreeNode*>vis;
        int currDist = 0;
        q.push({leaf, currDist});
        vis.insert(leaf);
        while(!q.empty()){
            auto [currLeaf, currDist] = q.front();q.pop();
            if(currDist > distance) continue;
            if(!currLeaf->left && !currLeaf->right){
                if(visLeafs.find(currLeaf) == visLeafs.end()){
                    count++;
                }
            }
            if(currLeaf->left && !vis.count(currLeaf->left)){
                q.push({currLeaf->left, currDist + 1});
                vis.insert(currLeaf->left);
            }
            if(currLeaf->right && !vis.count(currLeaf->right)){
                q.push({currLeaf->right, currDist + 1});
                vis.insert(currLeaf->left);
            }
            if(parent[currLeaf] && !vis.count(parent[currLeaf])){
                q.push({parent[currLeaf], currDist + 1});
                vis.insert(parent[currLeaf]);
            }
        }
        return count;
    }
    int countPairs(TreeNode* root, int distance) {
        if(!root)return 0;
        createGraph(root);
        int n = leafs.size();
        unordered_map<TreeNode*, int>visLeaf;
        int pairs = 0;
        for(int i = 0; i < leafs.size(); i++){
            TreeNode* currLeaf = leafs[i];
            visLeaf[currLeaf] = 1;
            pairs+=dfs(currLeaf, distance, visLeaf);
        }
        return pairs;
    }


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
     cout<<countPairs(root, 3);
}
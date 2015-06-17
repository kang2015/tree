    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode *p = root;
        stack<TreeNode *> s;
        vector<int> ans;
        while(p||!s.empty()){
            if(p){
                ans.push_back(p->val);
                s.push(p);
                p = p->right;
            }else{
                p = s.top();
                s.pop();
                p = p->left;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

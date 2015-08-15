/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
    //cur+stk+last
    vector<int> trickyPostorderTraversal(TreeNode* root) {
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

    vector<int> realPostorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode *p = root;
        vector<int> ans;
        while(!stk.empty() || p){
            if(p == NULL){
                if(stk.top()->right == NULL){
                    p = stk.top();stk.pop();ans.push_back(p->val);
                    while(!stk.empty() && p == stk.top()->right){
                        p = stk.top();stk.pop();ans.push_back(p->val);
                    }
                    p = NULL;//important!!
                 }else{
                    p = stk.top()->right;
                }
            } else{
                stk.push(p);
                p=p->left;
            }
            
        }
        return ans;
    }


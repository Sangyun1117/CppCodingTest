/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* answer = nullptr;
bool isFind = false; // 찾았으면 바로 종료
int findCount(TreeNode* root, TreeNode *p, TreeNode *q){

    int count = 0;
    if(root->val == p->val || root->val == q->val)
        ++count;
    if(root->left){
        int leftCount = findCount(root->left, p, q);
        if(isFind)
            return 0;
        count += leftCount;
    }
    if(root->right){
        int rightCount = findCount(root->right, p, q);
        if(isFind)
            return 0;
        count += rightCount;
    }
    if(count==2){
        answer = root;
        isFind = true;
    }
    return count;
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        answer = nullptr;
        isFind = false;
        if(findCount(root,p,q)==2)
            return root;
        else
            return answer;

    }
};
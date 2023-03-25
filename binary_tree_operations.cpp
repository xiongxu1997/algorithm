//
// Created by xx on 2023/3/25.
//
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 前序遍历，中序遍历，后续遍历
    void preorder(vector<int>&res, TreeNode*root){
        if(root == nullptr)
            return;
        res.push_back(root->val);
        preorder(res, root->left);
        preorder(res, root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        // write code here
        vector<int>res;
        preorder(res, root);
        return res;
    }

    // 层次遍历
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!empty(q)){
            vector<int> row;
            int n = q.size();
            for(int i=0;i<n;i++){
                row.push_back(q.front()->val);
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            res.push_back(row);
        }
        return res;
    }

    // 之字形打印二叉树
    vector<vector<int> > Print(TreeNode* pRoot) {
        TreeNode* root = pRoot;
        vector<vector<int>> res;
        if(root==nullptr)
            return res;
        bool flag = true;
        queue<TreeNode*> q;
        q.push(root);
        while(!empty(q)){
            int k = q.size();
            vector<int> layer;
            for(int i=0;i<k;i++){
                TreeNode* top = q.front();
                layer.push_back(top->val);
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
                q.pop();
            }
            if(flag){
                res.push_back(layer);
            }else{
                reverse(layer.begin(),layer.end());
                res.push_back(layer);
            }
            flag = !flag;
        }
        return res;
    }

    // 二叉树的最大深度
    int maxDepth(TreeNode* root) {
        //空节点没有深度
        if(root == nullptr)
            return 0;
        //返回子树深度+1
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    // 判断是否存在和为给定值的路径
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==nullptr)
            return false;
        if(root->left==nullptr and root->right==nullptr and sum-root->val==0){
            return true;
        }
        return hasPathSum(root->left, sum-root->val) or hasPathSum(root->right, sum-root->val);
    }

    // 将二叉搜索树转化为排序的双向链表
    TreeNode* pre = nullptr;
    TreeNode* head = nullptr;
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if(pRootOfTree==nullptr)
            return nullptr;
        Convert(pRootOfTree->left);
        if(pre==nullptr){
            head = pRootOfTree;
            pre = pRootOfTree;
        }else{
            pre->right = pRootOfTree;
            pRootOfTree->left = pre;
            pre = pRootOfTree;
        }
        Convert(pRootOfTree->right);
        return head;
    }

    // 判断二叉树是否对称
    bool judge(TreeNode* t1, TreeNode* t2){
        if(t1==nullptr and t2!=nullptr)
            return false;
        if(t1!=nullptr and t2==nullptr)
            return false;
        if((t1==nullptr and t2==nullptr))
            return true;
        if(t1->val!=t2->val)
            return false;
        return judge(t1->left, t2->right) and judge(t1->right, t2->left);
    }
    bool isSymmetrical(TreeNode* pRoot) {
        return judge(pRoot, pRoot);
    }

    // 合并两颗二叉树，都存在的结点就相加，不存在的结点就由另一个树的结点代替
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==nullptr){
            return t2;
        }
        if(t2==nullptr){
            return t1;
        }
        TreeNode* root = new TreeNode(t1->val + t2->val);
        root->left = mergeTrees(t1->left, t2->left);
        root->right = mergeTrees(t1->right, t2->right);
        return root;
    }

    // 二叉树的镜像
    TreeNode* Mirror(TreeNode* pRoot) {
        if(pRoot==nullptr){
            return nullptr;
        }
        TreeNode* left = Mirror(pRoot->right);
        TreeNode* right = Mirror(pRoot->left);

        pRoot->left = left;
        pRoot->right = right;
        return pRoot;
    }

    // 判断是否是二叉排序树
    long _pre = INT_MIN;
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)
            return true;
        if(!isValidBST(root->left))
            return false;
        if(_pre >= root->val)
            return false;
        _pre = root->val;
        if(!isValidBST(root->right))
            return false;
        return true;
    }

    // 判断是否是完全二叉树
    bool isCompleteTree(TreeNode* root) {
        if(root==nullptr)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!empty(q)){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                TreeNode* top = q.front();
                q.pop();
                if(top==nullptr){
                    flag = true;
                }
                else{
                    if(flag){
                        return false;
                    }
                    q.push(top->left);
                    q.push(top->right);
                }
            }
        }
        return true;
    }

    // 判断是否是平衡二叉树
    map<TreeNode*, int> hs;
    int depth(TreeNode* root){
        if(root==nullptr) return 0;
        if(hs.find(root)!=hs.end()) return hs[root];
        return hs[root] = max(depth(root->left), depth(root->right))+1;
    }
    bool judge(TreeNode* root){
        if(root==nullptr) return true;
        return (abs(hs[root->left]-hs[root->right])<=1) and judge(root->left) and judge(root->right);
    }
    bool IsBalanced_Solution(TreeNode* root) {
        depth(root);
        return judge(root);
    }

    // 找到二叉搜索树中两个指定节点的最近公共祖先
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        if(root==nullptr) return -1;
        if(root->val > p and root->val > q)
            return lowestCommonAncestor(root->left, p, q);
        if(root->val < p and root->val < q)
            return lowestCommonAncestor(root->right, p, q);
        return root->val;
    }

    // 在二叉树中找到两个节点的最近公共祖先
    int lowestCommonAncestor2(TreeNode* root, int o1, int o2) {
        //该子树没找到，返回-1
        if(root == NULL)
            return -1;
        //该节点是其中某一个节点
        if(root->val == o1 || root->val == o2)
            return root->val;
        //左子树寻找公共祖先
        int left = lowestCommonAncestor2(root->left, o1, o2);
        //右子树寻找公共祖先
        int right = lowestCommonAncestor2(root->right, o1, o2);
        //左子树为没找到，则在右子树中
        if(left == -1)
            return right;
        //右子树没找到，则在左子树中
        if(right == -1)
            return left;
        //否则是当前节点
        return root->val;
    }

    // 序列化二叉树（较难）
    //处理序列化的功能函数（递归）
    void SerializeFunction(TreeNode* root, string& str){
        //如果指针为空，表示左子节点或右子节点为空，用#表示
        if(root == NULL){
            str += '#';
            return;
        }
        //根节点
        string temp = to_string(root->val);
        str += temp + '!';// 加!，区分节点
        //左子树
        SerializeFunction(root->left, str);
        //右子树
        SerializeFunction(root->right, str);
    }

    char* Serialize(TreeNode *root) {
        //处理空树
        if(root == NULL)
            return "#";
        string res;
        SerializeFunction(root, res);
        //把str转换成char
        char* charRes = new char[res.length() + 1];
        strcpy(charRes, res.c_str());
        charRes[res.length()] = '\0';
        return charRes;
    }

    //处理反序列化的功能函数（递归）
    TreeNode* DeserializeFunction(char** str){
        //到达叶节点时，构建完毕，返回继续构建父节点
        //双**表示取值
        if(**str == '#'){
            (*str)++;
            return NULL;
        }
        //数字转换
        int val = 0;
        while(**str != '!' && **str != '\0'){
            val = val * 10 + ((**str) - '0');
            (*str)++;
        }
        TreeNode* root = new TreeNode(val);
        //序列到底了，构建完成
        if(**str == '\0')
            return root;
        else
            (*str)++;
        //反序列化与序列化一致，都是前序
        root->left = DeserializeFunction(str);
        root->right = DeserializeFunction(str);
        return root;
    }

    TreeNode* Deserialize(char *str) {
        //空序列对应空树
        if(str == "#"){
            return NULL;
        }
        TreeNode* res = DeserializeFunction(&str);
        return res;
    }

    // 给定前序和中序遍历结果，重建二叉树
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int m = pre.size();
        int n = vin.size();
        if(m==0 or n==0)
            return nullptr;

        TreeNode* head = new TreeNode(pre[0]);

        for(int i=0;i<n;i++){
            if(pre[0]==vin[i]){
                vector<int> leftpre(pre.begin()+1, pre.begin()+i+1);
                vector<int> rightpre(pre.begin()+i+1, pre.end());
                vector<int> leftvin(vin.begin(), vin.begin()+i);
                vector<int> rightvin(vin.begin()+i+1, vin.end());
                head->left = reConstructBinaryTree(leftpre, leftvin);
                head->right = reConstructBinaryTree(rightpre, rightvin);
                break;
            }
        }
        return head;
    }

    // 输出二叉树的右视图
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==nullptr)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                TreeNode* top = q.front();
                q.pop();
                if(i==sz-1){
                    res.push_back(top->val);
                }
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
            }
        }
        return res;
    }
};
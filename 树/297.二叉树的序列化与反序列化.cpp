/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-30 16:31:31
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-10-14 18:28:18
 * @FilePath: /.leetcode/树/297.二叉树的序列化与反序列化.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s1, s2;
        perorder(root, s1);
        inorder(root,s2);
        return s1 + s2;
    }
    void perorder(TreeNode* root,string&temp){
            if(!root)return;
            temp+=to_string(root->val);
            perorder(root->left, temp);
            
            perorder(root->right, temp);
    }
        void inorder(TreeNode*root,string&temp){
            if(!root)
                return;
            inorder(root->left, temp);
            temp+=to_string(root->val);
            inorder(root->right, temp);
        }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n=data.size();
        string pres = data.substr(0, n / 2),ins=data.substr(n/2,n/2);
        return buildTree(pres, ins);
    }
    
    TreeNode* buildTree(string&preorder,string&inorder){
        int n = preorder.size();
        if (n==0)
            return NULL;

        unordered_map<int, int> hash;
        for (int i = 0;i<n;++i){
            //hash[inorder[i]]=i;
            hash.emplace((int)inorder[i]-48, i);
        }
        return findRoot(preorder, hash, 0,n-1 , 0);
    }
    TreeNode* findRoot(string & preorder, unordered_map<int, int> & hash, int b, int e, int s){
        if(b>e)return nullptr;
        int index = hash[(int)preorder[s]-48],leftLen=index-b;
        TreeNode *root = new TreeNode((int)preorder[s]-48);
        root->left = findRoot(preorder, hash, b, index - 1, s + 1);
        root->right = findRoot(preorder, hash, index + 1, e, s + leftLen + 1);
        return root;
    }
};
*/
class Codec {
public:
    void rserialize(TreeNode* root, string& str) {
        if (root == nullptr) {
            str += "None,";
        } else {
            str += to_string(root->val) + ",";
            rserialize(root->left, str);
            rserialize(root->right, str);
        }
    }

    string serialize(TreeNode* root) {
        string ret;
        rserialize(root, ret);
        return ret;
    }

    TreeNode* rdeserialize(list<string>& dataArray) {
        if (dataArray.front() == "None") {
            dataArray.erase(dataArray.begin());
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = rdeserialize(dataArray);
        root->right = rdeserialize(dataArray);
        return root;
    }

    TreeNode* deserialize(string data) {
        list<string> dataArray;
        string str;
        for (auto& ch : data) {
            if (ch == ',') {
                dataArray.push_back(str);
                str.clear();
            } else {
                str.push_back(ch);
            }
        }
        if (!str.empty()) {
            dataArray.push_back(str);
            str.clear();
        }
        return rdeserialize(dataArray);
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {        
    string res = "";
    //使用流读取，遇空格，停止的特性，将序列通过流逐个节点地读取
    stringstream datas;
    string tmp;
    //前序递归
    void dfs1 (TreeNode * rt){
        //空格隔开是为了后面的流操作
        if (!rt){
            res += "NULL ";     //用空格分隔开
            return;
        }
        res += to_string(rt->val)+" ";
 
        dfs1(rt->left);
        dfs1(rt->right);   
    };

    TreeNode * dfs2(){
        //遇空格停止
        datas >> tmp;
        if (tmp == "NULL")
            return NULL;
        TreeNode * rt = new TreeNode(stoi(tmp));
        rt->left = dfs2();
        rt->right = dfs2();
        return rt;
    }
public:
    //序列化
    string serialize(TreeNode* root) {
        dfs1(root);
        return res;
    }

    // 反序列化
    TreeNode* deserialize(string data) {
        this->datas << data;
        return dfs2();
    }
};

class Codec {
public:
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
private:
    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {//按照前序遍历获取元素值
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "#";
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;//把流的内容重定向到val
        //再用前序遍历的方式造树
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};

//默写1
class Codec{
public:
    string serialize(TreeNode* root){
        ostringstream out;
        serialize(root, out);
        return out.str();
    }
    TreeNode* deserialize(string data){
        istringstream in(data);
        return deserialize(in);
    }
private:
    void serialize(TreeNode* root,ostringstream& out){
        if(root){
            out << root->val << " ";
            serialize(root->left, out);
            serialize(root->right,out);
        }else{
            out << "#";
        }
    }
    TreeNode* deserialize(istringstream& in){
        string val;
        in >> val;
        if(val=="#"){
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(val));
        root->left=deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end


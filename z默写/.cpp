/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-25 22:33:01
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-29 01:34:03
 * @FilePath: /.leetcode/z默写/.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//LRU
class LRUCache {
public:
    LRUCache(int capacity):m_c(capacity) {}
    
    int get(int key) {
        auto it = hash.find(key);
        if (it==hash.end()){
            return -1;
        }
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = hash.find(key);
        if (it!=hash.end()){
            cache.splice(cache.begin(), cache, it->second);
            it->second->second = value;
        }else{
            cache.emplace(cache.begin(), make_pair(key, value));
            hash[key]=cache.begin();

            if(cache.size()>m_c){
                hash.erase(cache.back().first);
                cache.pop_back();
            }
        }
    }

private:
    int m_c;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
};
//快速排序
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand(time(0));
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }
    void quick_sort(vector<int>&nums,int first,int last){
        if(first>=last)return;
        int pos = rand() % (last - first + 1)+first;
        swap(nums[pos], nums[first]);
        
        int l=first,r=last,base = nums[l];
        while(l<r){
            while(l<r&&nums[r]>=base){
                --r;
            }
            nums[l] = nums[r];
            while(l<r&&nums[l]<=base){
                ++l;
            }
            nums[r] = nums[l];
        }
        nums[l]=base;//这里的l是移动后更新的l

        quick_sort(nums,first,l);
        quick_sort(nums,l+1,last);
    }
};
//合并K个升序链表
class Solution {
public:
        //1.局部两个合并
        ListNode* mergetwoLists(ListNode*l1,ListNode* l2){
            if(!l1){
                return l2;
            }else if(!l2){
                return l1;
            }else if(l1->val<l2->val){
                l1->next=mergetwoLists(l1->next,l2);
                return l1;
            }else{
                l2->next=mergetwoLists(l1,l2->next);
                return l2;
            }
        }
        ListNode* merge(vector<ListNode*> &lists, int l,int r){
            if(l>r) return nullptr;
            if(l==r)
                return lists[l];
            int mid = l+(r-l)/2;
            return mergetwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
        }
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            return merge(lists, 0, lists.size() - 1);
        }
};
//排序链表
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode*slow=head,*fast=head;
        while(fast->next&&fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode*newHead=slow->next;
        slow->next=nullptr;
        return merge(sortList(head),sortList(newHead));
    }
    ListNode* merge(ListNode*l1,ListNode*l2){
        if(!l1){
            return l2;
        }else if(!l2){
            return l1;
        }else if(l1->val<l2->val){
            l1->next=merge(l1->next,l2);
            return l1;
        }else{
            l2->next=merge(l1,l2->next);
            return l2;
        }
    }
};
//插入排序
void insert_sort(vector<int>&nums,int n){
    for (int i=0;i<n; ++i){
        for (int j = i; j > 0 && nums[j] < nums[j - 1];--j){
            swap(nums[j], nums[j - 1]);
        }
    }
}
//maopao
void maopao(vector<int>&nums){
    for (int i = 0; i < nums.size()-1;++i){
        for (int j = 0;j<nums.size()-1-i;++j){
            if(nums[j]>nums[j+1]){
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}
//堆排序
class Solution {
    //堆调整
    void maxHeapadjust(vector<int>&nums,int i,int len){
        while (i*2+1<=len){
            int l=i*2+1,r=i*2+2,large;
            if(l<=len&&nums[l]>nums[i]){
                large = l;
            }else{
                large = i;
            }
            if(r<=len&&nums[r]>nums[large]){
                large = r;
            }
            if(large!=i){
                swap(nums[i],nums[large]);
                i=large;//更新i继续检查调整
            }else{
                break;//i没问题，跳出调整
            }
        }
    }
    //建堆
    void maxHeapbuild(vector<int>&nums,int len){
        for (int i = len / 2; i >= 0;--i){
            maxHeapadjust(nums, i, len);
        }
    }
    //排序
    void heapSort(vector<int>&nums){
        int len=nums.size()-1;
        maxHeapbuild(nums,len);
        for (int j = len; j >= 1;--j){
            swap(nums[j], nums[0]);
            --len;
            maxHeapadjust(nums,0,len);
        }
    }
pbulic:
    vector<int> sortArray(vector<int>&nums){
        heapSort(nums);
        return nums;
    }
};
//归并
void merge_sort(vector<int>& nums,int l,int r,vector<int>&temp){
            if(l>=r)
                return;

            //分半
            int mid = l + (r - l) / 2;
            merge_sort(nums, l, mid, temp);
            merge_sort(nums, mid + 1, r, temp);


            //合并（双指针合并两个有序序列成一个有序序列）
            int i = l, j = mid + 1, cur=0;
            //1.两子列都有元素
            while(i<=mid&&j<=r){
                if(nums[i]<=nums[j])
                    temp[cur++] = nums[i++];
                else temp[cur++]=nums[j++];
            }
            //2.左子列有元素，右无
            while(i<=mid){ 
                temp[cur++]=nums[i++];}
            //3.右子列有元素，左无
            while(j<=r){
                temp[cur++] = nums[j++];}

            //4.将temp中的元素复制到nums的l-r段
            for (int i = 0; i < r - l + 1; ++i) {
                nums[i + l] = temp[i];
            }
}
//环形链表
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode *slow = head, *fast = head;
        do{
            if(!fast->next||!fast->next->next)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);
        return true;
    }
};
//19.第N个节点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head),*prev=dummy,*fast=head;
        //关于找链表倒数第n个节点的问题，要根据实际需要看fast走到nullptr还是最后一个节点
        while(n--){
            fast = fast->next;
        }
        while(fast){
            fast = fast->next;
            prev = prev->next;
        }
        prev->next = prev->next->next;
        ListNode*ans=dummy->next;
        delete dummy;
        return ans;
    }
};
//反转链表中的一段
pair<ListNode*,ListNode*> myreverse(ListNode*head,ListNode*tail){
        ListNode*perv=tail->next,*cur=head,*next=nullptr;
        while(perv!=tail){
            next=cur->next;
            cur->next=perv;
            perv=cur;
            cur=next;
        }
        return {tail,head};
}
//合并两个链表
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        if(list1->val<list2->val){
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
//找链表中点
ListNode* midNode(ListNode* head){
        ListNode *slow = head, *fast = head;
        while(fast->next&&fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *mid = slow->next;
//两树相同
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q) return true;
        if(!p||!q) return false;
        if(p->val!=q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
//二叉树最大深度
class Solution {
public:
    int maxDepth(TreeNode* root) {
        //树的最大深度就是层数
        return root ? 1 + max(maxDepth(root->left), maxDepth(root->right)) : 0;
    }
};
//二叉树前序
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> st;
        while(root||!st.empty()){
            while(root){
                ret.push_back(root->val);
                st.emplace(root);
                root = root->left;
            }
            root=st.top();
            st.pop();
            root=root->right;
        }
        return ret;
    }
};
//二叉树中序
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> stk;
        while(root||!stk.empty()){
            while(root){
                stk.push(root);
                root=root->left;
            }
            root = stk.top();
            ret.push_back(root->val);
            stk.pop();
            root = root->right;
        }
        return ret;
    }
};
//124
class Solution {
    int maxSum=INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
    //以node为端点的最大路径的和
    int dfs(TreeNode*node){
        if(!node)return 0;
        //和0比是为了小于0的舍弃
        int l = max(dfs(node->left), 0);
        int r = max(dfs(node->right), 0);

        maxSum = max(maxSum, node->val + l + r);
        return node->val + max(l, r);
    }
};
//字典树208
class Trie {
    //说明：
        //前缀树的每个节点封装了一个size==26的vector和一个bool标志值
        //vector可以看出在此节点之前出现的字符串
        //bool标志值可以看到此节点是不是一个字符串的结束
    
private:
    //节点内容
    vector<Trie*> children;
    bool isEnd;

    Trie* searchPrefix(string prefix) {
        Trie* node = this;//指向类对象本身，这里就是指向根节点了
        for (char ch : prefix) {
            ch -= 'a';  //char转int 
            if (node->children[ch] == nullptr) {//children[ch]指向ch的指针
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

public:
    Trie() : children(26), isEnd(false) {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];//链表指针移动
        }
        node->isEnd = true;//字符串最后一个节点指向true（类二叉树叶子节点的next指向nullptr）
    }

    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};
//dfs695
class Solution{
    vector<int> d = {-1, 0, 1, 0, -1};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int m = grid.size(),n=grid[0].size(),ans=0;
        for (int i = 0;i<m;++i){
            for (int j = 0;j<n;++j){
                if (grid[i][j]){
                    ans=max(ans,dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>&grid,int r,int c){
        if(!grid[r][c])return 0;
        grid[r][c] = 0;//看过就标记
        int area = 1,x,y;

        for (int k = 0; k < 4; ++k){
            x = r + d[k], y = c + d[k + 1];
            if(x>=0&&x<grid.size()&&y>=0&&y<grid[0].size()&&grid[x][y]){
                area += dfs(grid, x, y);
            }
        }
        return area;
    }
};
//回溯93
class Solution {
    vector<string> ret;
    string str = "";
public:
    vector<string> restoreIpAddresses(string s) {
        backtrack(0,0,s);
        return ret;
    }
    void backtrack(int level,int index,string&s){
        if (level==4||index==s.size()){
            if (level==4&&index==s.size())
                ret.emplace_back(str.substr(0,str.size()-1));//-1是去掉尾巴的‘.’
            return;
        }

        for (int i = 1; i <= 3;++i){//每段长度可为：1、2、3，出现三个分枝
            if(index+i>s.size()) return;//还没够4块，但是s被用完了
            if(s[index]=='0' && i>1) return;//开头0，选取长度超过1，舍去
            if(i==3 &&s.substr(index,i)>"255") return;//这里使用了字符串的比较,所以要i==3
            str+=s.substr(index,i)+".";
            backtrack(level+1,index+i,s);
            str = str.substr(0,str.size()-i-1);//还原
        }
    }
};
//回溯79
class Solution {
    vector<int> d{-1, 0, 1, 0, -1};
public:
    bool exist(vector<vector<char>>& board,string word){
        if(board.empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool find = false;
        for (int i = 0;i<m;++i){
            for (int j = 0;j<n;++j){
                backtrack(board,word,visited,find,i,j,0);
            }
        }
        return find;
    }

    void backtrack(vector<vector<char>>& board,string &word,vector<vector<bool>>& visited,bool& find,int i,int j,int pos){
        if(i<0||i>=board.size()||j<0||j>=board[0].size()||visited[i][j]||find||board[i][j]!=word[pos])
            return;
        if(pos==word.size()-1){
            find=true;
            return;
        }

        visited[i][j]=true;
        for (int k = 0; k < 4;++k){
            int x = i + d[k], y = j + d[k + 1];
            backtrack(board, word, visited, find, x, y, pos + 1);
        }
        visited[i][j]=false;
    }
};
//回溯39
class Solution {
private:
    vector<vector<int>> ret;
    vector<int> path;
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target,0);
        return ret;
    }
    void backtrack(vector<int>&candidates, int target,int pos){
        if(target<0)return;
        if(target==0){
            ret.emplace_back(path);
            return;
        }
        for (int i = pos;i<candidates.size();++i){
            path.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i);
            path.pop_back();
        }
    }
};
//207课程表
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //存图：入度关系
        vector<vector<int>> grid(numCourses, vector<int>());
        //存节点对应的入度数
        vector<int> in(numCourses);

        for(const auto&p:prerequisites){
            //节点数值充当下标
            grid[p[1]].push_back(p[0]);
            ++in[p[0]];
        }

        //初始入度为0的节点为突破口
        queue<int> q;
        for (int i = 0;i<numCourses;++i){
            if(in[i]==0){
                q.push(i);
            }
        }
        //调整节点入度数，==0时入队
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto v:grid[temp]){
                --in[v];
                if(in[v]==0){
                    q.push(v);
                }
            }  
        }        
        //检查，是否存在节点入度没降为0的
        for(auto& j:in){
            if(j)
                return false;
        }

        return true;
    }
};
//232栈实现队列
class MyQueue {
public:
    MyQueue() {}
    void push(int x) {
        in.push(x);
    }
    int pop() {
        int ret = peek();
        out.pop();
        return ret;
    }
    int peek() {
        if(out.empty()){
            while(in.size()){
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }
    bool empty() {
        return in.empty()&&out.empty();
    }
private:
    stack<int> in, out;
};
//33二分
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return -1;
        int l=0,r=nums.size()-1,m;
        while(l<=r){
            m = l + (r - l) / 2;
            if(nums[m]==target){
                return m;
            }
            //要用nums[m]值的关系分段
            else if(nums[m]<=nums[r]){
                if(target>nums[m]&&target<=nums[r]){
                    l = m + 1;
                }else{
                    r = m - 1;
                }
            }else{
                if(target<nums[m]&&target>=nums[l]){
                    r = m - 1;
                }else{
                    l = m + 1;
                }
            }
        }
        return -1;
    }
};
//34二分
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return {-1, -1};
        //产生了一个左闭右开的区间
        int lower = lower_bound(nums, target);
        int upper = upper_bound(nums, target)-1;
        if (lower==nums.size()||nums[lower]>target)
            return {-1, -1};
        return {lower, upper};
    }
    //第一个不小于（>=）target的元素的下标
    int lower_bound(vector<int>&nums,int target){
        int l = 0,r = nums.size(),mid = 0;
        while(l<r){
            mid = (l + r) / 2;
            if(nums[mid]>=target){
                r = mid;//初始化是r=nums.size()
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
    //第一个大于target的元素的下标
    int upper_bound(vector<int>&nums,int target){
        int l = 0,r = nums.size(),mid = 0;
        while(l<r){
            mid = (l + r) / 2;
            if(nums[mid]>target){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};
//位运算136
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto &n:nums){
            ans ^= n;
        }
        return ans;
    }
};
//三数之和
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;

        for (int first = 0; first < n;++first){
            if(first>0&&nums[first]==nums[first-1])continue;
            int target = -nums[first];//枚举一个值，下面就是两数之和
            int third = n - 1;

            for (int second = first + 1; second < n;++second){
                if(second>first+1&&nums[second]==nums[second-1])continue;

                while(second<third&&nums[second]+nums[third]>target){
                    --third;
                }
                if(second==third)break;//没找着第三个数
                if(nums[second]+nums[third]==target){
                    ret.emplace_back(vector<int>{nums[first], nums[second], nums[third]});
                }
            }
        }
        return ret;
    }
};
//105
//2.链表两数之和
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*dummy=new ListNode(0),*pre=dummy;
        int x, y, tmp = 0;
        while(l1||l2){
            x = l1 ? l1->val : 0;
            y = l2 ? l2->val : 0;
            int sum = x + y + tmp;
            pre->next = new ListNode(sum % 10);
            pre = pre->next;
            tmp = sum / 10;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        if(tmp)
            pre->next = new ListNode(tmp);
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};
//前缀和209：要求有关数组连续片段和的值的问题
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), ret = n + 1;
        vector<int> prev(n + 1, 0);
        for (int i = 1;i<=n;++i){
            prev[i]=prev[i-1]+nums[i-1];
        }
        for (int i = 1;i<=n;++i){
            int tmp = target + prev[i - 1];
            auto up = lower_bound(prev.begin(), prev.end(), tmp);
            if(up!=prev.end()){
                ret = min(ret, (int)(up - prev.begin() - (i - 1)));//迭代器的差表距离要转int
            }
        }
        return ret == n + 1 ? 0 : ret;
    }
};
//手撕string
class String{
public:
    String();
    String(const char *str = nullptr);     // 普通构造函数
    String(const String &str);             // 拷贝构造函数
    String &operate = (const String &str); // 赋值函数
    ~String();                             // 析构函数
private:
    char *m_data;// 用于保存字符串
}; 
 
//普通构造函数
String::String(const char *str){
    if(str==nullptr){
        m_data = new char[1]; 
        *m_data = '0';
    }else{
        int len = strlen(str);
        m_data = new char[len+1]; 
        strcpy(m_data, str);
    }
} 
//拷贝构造函数
String::String(const String &str){
    int len = strlen(str.m_data);
    m_data = new char[len+1]; 　　　　
    strcpy(m_data, str.m_data);    
} 
//赋值函数
String & String::operate =(const String &str){     
    if(this == &str)                  　　//检查自赋值
        return *this;   
    delete [] m_data;            　　　　//释放原有的内存资源
    int len = strlen( str.m_data );      
    m_data = new char[len+1]; 　
    strcpy( m_data, str.m_data );   
    return *this;     　　　　　　　　//返回本对象的引用  
}
// String的析构函数
String::~String(void){
    delete [] m_data; 
}

class String{
public:
    String();
    String(const char *str = nullptr);
    String(const String &str);
    String &operator=(const String &str);
    ~String();

private:
    char *m_d;
};
String::String(const char*str=nullptr){
    if(str==nullptr){
        m_d = new char[1];
        *m_d = '\0';
    }else{
        int len = strlen(str);
        m_d = new char[len + 1];//+1,因为strlen不算'\0'
        strcpy(m_d, str);
    }
}
String::String(const String&str){
    int len = strlen(str.m_d);
    m_d = new char[len + 1];//+1,因为strlen不算'\0'
    strcpy(m_d, str.m_d);
}
String& String::operator=(const string&str){
    if(&str==this){
        return *this;
    }else{
        delete[] m_d;
        int len = strlen(str.m_d);
        m_d = new char[len + 1];//+1,因为strlen不算'\0'
        strcpy(m_d, str.m_d);
        return *this;
    }
}
String::~String(){
    delete [] m_d;
}

class String{
public:
    String();
    String(const char *str);
    String(const string &str);
    String &operator=(const String &str);
    ~string();

private:
    char *m_d;
};
String::String(const char *str){
    if(str==nullptr){
        m_d = new char[1];
        *m_d = '\0';
    }else{
        int len = strlen(str);
        m_d = new char[len + 1];
        strcpy(m_d, str);
    }
}
String::String(const String&str){
    int len = strlen(str.m_d);
    m_d = new char[len + 1];
    strcpy(m_d, str.m_d);
}
String& String::operator=(const string&str){
    if(this!=&str){
        delete[] m_d;
        int len = strlen(str.m_d);
        m_d = new char[len + 1];
        strcpy(m_d, str.m_d);
    }
    return *this;
}
String::~String(){
    delete[] m_d;
}
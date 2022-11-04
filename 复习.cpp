/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-09 15:02:04
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-30 12:41:10
 * @FilePath: /.leetcode/复习.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       if(!head||!head->next)
           return head;
       ListNode *newHead = reverseList(head->next);
       head->next->next=head;
       head->next=nullptr;
       return newHead;
    }
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       if(!head||!head->next)return head;
       ListNode*cur=head,*per=nullptr,*next=nullptr;
       while(cur){
           next = cur->next;
           cur->next = per;
           per = cur;
           cur=next;
       }
       return per;
    }
};
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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(0);
        ListNode*p=dummy;
        while(list1&&list2){
            if(list1->val<list2->val){
                p->next = list1;
                list1=list1->next;
            }else{
                p->next=list2;
                list2 = list2->next;
            }
            p=p->next;
        }
        p->next=list1?list1:list2;
        return dummy->next;
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m-- + n-- - 1;
        while(m>=0&&n>=0){
            if(nums1[m]>nums2[n]){
                nums1[pos--] = nums1[m--];
            }else{
                nums1[pos--] = nums2[n--];
            }
        }
        while(n>=0){
            nums1[pos--] = nums2[n--];
        }
        return nums1
    }
};
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> sorted(m+n);
        int p1=0,p2=0,p3=0;
        while(p1<m||p2<n){
            if(p1<m&&p2<n){
                if(nums1[p1]<nums2[p2]){
                    sorted[p3++] = nums1[p1++];
                }else{
                    sorted[p3++] = nums2[p2++];
                }
            }
            else if(p1==m){//
                sorted[p3++] = nums2[p2++];
            }
            else if(p2==n){
                sorted[p3++] = nums1[p1++]; 
            }
        }
        for (int i = 0; i < m + n;++i){
            nums1[i] = sorted[i];
        }
        return;
    }
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode *slow = head, *fast = head;
        do{
            if(!fast->next||!fast->next->next)
                return false;
            slow = slot->next;
            fast = fast->next->next;
        } while (slow != fast);
        return true;
    }
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)return false;
        ListNode*p = head;
        unordered_set<ListNode *> hash;
        while (p){
            if(hash.count(p)){
                return true;
            }else{
                hash.insert(p);
            }
            p=p->next;
        }
        return false;
    }
};
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *s = head, *f = head;
        while(k--){
            f=f->next;
        }
        while(f){
            s=s->next;
            f=f->next;
        }
        return s;
    }
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB)return nullptr;
        ListNode *p1=headA, *p2=headB;
        while(p1!=p2){
            p1=p1?p1->next:headA;
            p2 = p2 ? p2->next : headB;
        }
        return p1;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(),m=0,r=0;
        unordered_set<char>hash;
        for(int l=0;l<n;++l){
            if(l>0){
                hash.erase(s[l-1]);
            }
            while(r<n&&!hash.count(s[r])){
                hash.insert(s[r]);
                ++r;
            }
            m=max(m,r-l);
        }
        return m;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m = 0;
        vector<int>v(128, 0);
        for (int l = 0, r = 0; r < s.size();++r){
            ++v[s[r]];
            while(v[s[r]]>1){
                --v[s[i]];
                ++i;
            }
            m = max(m, r - l + 1);
        }
        return m;
    }
};
class LRUCache {
public:
    LRUCache(int capacity):m_c(capacity) {}
    
    int get(int key) {
        auto it = hash.find(Key);
        if(it==hash.end()){
            return -1;
        }
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = hash.find(key);
        if(it!=hash.end()){
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
        }else{
            list.emplace(cache.begin(), make_pair(key, value));
            hash[key]=cache.begin();

            if(list.size()>m_c){
                hash.erase(cache.back()->first);
                cache.pop_back();
            }
        }
    }

private:
   int m_c;
   list<pair<int, int>> cache;
   unordered_map<int, list<pair<int, int>>::iterator> hash;
};
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        quick_sort(nums,0,nums.size()-1);
        return nums;
    }
    void quick_sort(vector<int>&nums,int first,int last){
        if(first>=last)
            return;
        int pos = rand() % (last - first + 1) + first;
        swap(nums[pos],nums[first]);
        int l = first, r = last, base = nums[l];
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
        nums[l] = base;
        quick_sort(nums,first,l);
        quick_sort(nums,l+1,last);
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int pos,n=nums.size(),l=0,r=n-1;
        while(1){
            pos = help(nums, l,r);
            if(pos==k-1){
                return nums[pos];
            }else if(pos<k-1){
                l = pos + 1;
            }else{
                r = pos - 1;
            }
        }
    }

    //----左右挖坑互填
    int help(vector<int> & nums, int l, int r){
        int base = nums[l];
        while(l<r){
            while(l<r&&nums[r]<=base){
                --r;
            }
            nums[l] = nums[r];
            while(l<r&&nums[l]>=base){
                ++l;
            }
            nums[r]=nums[l];
        }
        nums[l]=base;
        return l;
    }
};
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
                    //ret.push_back({nums[first], nums[second], nums[third]});
                    ret.emplace_back(vector<int>{nums[first], nums[second], nums[third]});
                }
            }
        }
        return ret;
    }
};
class Solution {
    pair<ListNode*,ListNode*> myReverse(ListNode*head,ListNode*tail){
        ListNode *prev = tail->next, *cur = head, *next = nullptr;
        while(prev!=tail){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return {tail, head};
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        listNode*pre=dummy;

        while(head){
            ListNode *tail = pre;
            for (int i = 0; i < k;++i){
                tail = tail->next;
                if(!tail)
                    return dummy->next;
            }
            ListNode*nex=tail->next;

            pair<ListNode *, ListNode *> ret = myReverse(head, tail);
            head=ret.first;
            tail=ret.second;

            tail->next = nex;
            pre->next = head;
            pre = tail;
            head = tail->next;
        }
        return dummy->next;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return{};
        vector<vector<int>>ret;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            ret.emplace_back({});
            while (n--)
            {
                TreeNode*node=q.front();
                q.pop();
                ret.back().push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return ret;
    }
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return{};
        vector<vector<int>> ret;
        queue<TreeNode *> q;
        q.push(root);
        int flag = 0;
        while(!q.empty()){
            int n=q.size();
            ret.push_back({});
            while(n--){
                TreeNode*node=q.front();
                q.pop();
                ret.back().push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(flag&1){
                reverse(ret.back().begin(),ret.back().end());
            }
            ++flag;
        }
        return ret;
    }
};
class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1)
            return x;
        int l = 1, r = x, mid, sqrt;
        while(l<r){
            mid = l + (r - l) / 2;
            sqrt = x / mid;
            if (mid ==sqrt)return mid;
            else if(mid>sqrt)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;
        while(l<=r){
            mid = l + (r - l) / 2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<=nums[r]){
                if(nums[mid]<target&&target<=nums[r]){
                    l=mid+1;
                }else{
                    r=mid - 1;
                }
            }else{
                if(target<nums[mid]&&target>=nums[l]){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(),ans=0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n;++i){
            dp[i] = 1;
            for (int j = 0;j<i;++j){
                if(nums[j]<nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        //return *max_element(dp.begin(), dp.end());
        return ans;
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec;
        vec.push_back(nums[0]);
        for (int i = 1; i < n;++i){
            if(nums[i]>vec.back()){
                vec.push_back(nums[i]);
            }else{
                auto it = lower_bound(vec.begin(), vec.end(), nums[i]);
                *it=nums[i];
            }
        }
        return vec.size();
    }
};

class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        if(n&1)
            return false;
        //"开门"随便放，检测“关门”
        unordered_map<char, char> hash = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> st;
        for(char ch:s){
            if(hash.count(ch)){
                if(st.empty()||st.top()!=hash[ch]){
                    return false;
                }
                st.pop();
            }else{
                st.push(ch);
            }
        }
        return st.empty();
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<2)return nums.size();
        unordered_set<int> hash={nums.begin(),nums.end()};

        int ans = 0;
        while(!hash.empty()){
            int cur = *hash.begin();
            hash.erase(cur);
            int prev = cur - 1, next = cur + 1;
            while(hash.count(prev)){
                hash.erase(prev--);
            }
            while(hash.count(next)){
                hash.erase(next++);
            }
            ans = max(ans,next-prev-1);
            if(ans>=nums.size()/2+1)break;
        }
        return ans;
    }
};

class Solution {
    vector<int> ret;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        dfs(root);
        return ret;
    }
    void dfs(TreeNode* root){
        if(!root)
            return;
        dfs(root->left);
        ret.push_back(root->val);
        dfs(root->right);
    }
};
//中序
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
//前序
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
//后序
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> st;
        TreeNode*prev=nullptr;
        while(root||!st.empty()){
            while(root){
                st.emplace(root);
                root = root->left;
            }
            //先取出来研究
            root=st.top();
            st.pop();

            if(!root->right||root->right==prev){
                ret.push_back(root->val);
                //某个点记录后就把这个点记作prev
                prev = root;
                root=nullptr;
            }else{
                //不是上面情况，将pop出的点再装回去，进行它的右侧
                st.emplace(root);
                root=root->right;
            }
        }
        return ret;
    }
};
class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        if(n&1)return false;
        stack<char> st;
        unordered_map<char,char>hash={{')','('},{']','['},{'}','{'}};

        for(auto &ch:s){
            if(hash.count(ch)){
                if(st.empty()||st.top()!=hash[ch]){
                    return false;
                }
                st.pop();
            }else{
                st.push(ch);
            }
        }
        return st.empty();
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> dp(n,0);
        //dp[0] = 1;
        for (int i = 0; i < n;++i){
            dp[i] = 1;
            for (int j = 0;j<i;++j){
                if(nums[j]<nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<2)
            return s;
        
        int maxlen = 0,start=0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0;i<n;++i){
            dp[i][i] = true;
        }

        for (int L = 2; L < n;++L){
            for (int l = 0; l < n;++l){
                int r = l + L - 1;
                if(r>=n)
                    break;
                if(s[l]!=s[r]){
                    dp[l][r] = false;
                }else{
                    if(L==2){
                        dp[l][r] = true;
                    }else{
                        dp[l][r] = dp[l + 1][r - 1];
                    }
                }
                if(dp[l][r]&&L>maxlen){
                    maxlen = L;
                    start = l;
                }
            }
        }
        return s.substr(start, maxlen);
    }
};
class Solution {
    pair<ListNode*,ListNode*> myReverse(ListNode*head,ListNode*tail){
        ListNode *prev = tail->next, *cur = head, *next = nullptr;
        while(prev!=tail){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return {tail, head};
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
    }
};
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode*root,TreeNode*p,TreeNode*q){
        if(!root||root=p||root=q)
            return root;
        ListNode *left = lowestCommonAncestor(root->left, p, q);
        ListNode *right = lowestCommonAncestor(root->right, p, q);
        if(!left)return right;
        if(!right)
            return left;
        if(left&&right)
            return root;

        return nullptr;
    }
};
class Solution {
    pair<ListNode*,ListNode*> myReverse(ListNode*head,ListNode*tail){
        ListNode*prev=tail->next,*cur=head,*next=nullptr;
        while(prev!=tail){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return {tail,head};
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0),*pre=dummy;
        dummy->next = head;
        
        while(head){
            ListNode *tail = pre;
            for (int i = 0;i<k;++i){
                tail = tail->next;
                if (!tail)
                    return dummy->next;  
            }
            ListNode*next=tail->next;

            pair<ListNode *, ListNode *> tmp = myReverse(head, tail);
            head=tmp.first;
            tail=tmp.second;

            tail->next = next;
            pre->next = head;
            pre = tail;
            head=tail->next;
        }
        return dummy->next;
    }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size(),ans=0;
        for (int i = 0; i < m;++i){
            for (int j = 0; j < n;++j){
                if(grid[i][j]=='1'){
                    ++ans;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>&grid,int i,int j){
        if(grid[i][j]=='0')
            return;
        grid[i][j] = '0';
        if(i-1>=0)
            dfs(grid,i-1,j);
        if(i+1<grid.size())
            dfs(grid,i+1,j);
        if(j-1>=0)
            dfs(grid,i,j-1);
        if(j+1<grid[0].size())
            dfs(grid,i,j+1);
    }
};
class Solution {
    vector<int> ret;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return ret;
    }
    void dfs(TreeNode*root){
        if(!root)
            return;
        ret.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
};
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
class Solution {
    vector<int> d = {-1, 0, 1, 0, -1};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),ans=0;
        for (int i = 0;i<m;++i){
            for (int j = 0; j < n;++j){
                if(grid[i][j]){
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>&grid,int i,int j){
        if (!grid[i][j])
            return 0;
        grid[i][j] = 0;
        int area = 1, x, y;
        for (int k = 0; k < 4; ++k){
            x = i + d[k], y = j + d[k + 1];
            if(x>=0&&x<grid.size()&&y>=0&&y<grid[0].size()){
                area+=dfs(grid, x, y);
            }
        }
        return area;
    }
};
class Solution {
    vector<vector<int>> ret;
    vector<int> tmp;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size(), 0);
        backtrack(nums, used);
        return ret;
    }
    void backtrack(vector<int>&nums,vector<int>&used){
        if(tmp.size()==nums.size()){
            ret.emplace_back(tmp);
            return;
        }
        for (int i = 0;i<nums.size();++i){
            if(used[i])
                continue;
            used[i] = 1;
            tmp.push_back(nums[i]);
            backtrack(nums, used);
            used[i] = 0;
            tmp.pop_back();
        }
    }
};
class Solution {
    vector<vector<int>> ret;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return ret;
    }
    void backtrack(vector<int>&nums,int level){
        if(level==nums.size()){
            ret.emplace_back(nums);
            return;
        }
        for (int i = level; i < nums.size();++i){
            swap(nums[i], nums[level]);
            backtrack(nums, level + 1);
            swap(nums[i], nums[level]);
        }
    }
};
class Solution {
public:
    int climbStairs(int n) {
       if(n<=2)
           return n;
       int p1 = 1, p2 = 2,cur=0;
       for (int i = 3; i <= n;++i){
           cur = p1 + p2;
           p1 = p2;
           p2 = cur;
       }
       return cur;
    }
};
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
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1, j = num2.size()-1, x, y, tmp = 0;
        string ans;
        while (i >= 0 || j >= 0||tmp>0){
            x = i >= 0 ? num1[i] - '0' : 0;
            y = j >= 0 ? num2[j] - '0' : 0;
            --i;
            --j;
            ans.push_back((x + y + tmp) % 10 + '0');
            tmp = (x + y+tmp) / 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(),*cur=dummy;
        int x, y, tmp = 0;
        while (l1 || l2){
            x=l1?l1->val : 0;
            y=l2?l2->val : 0;
            int sum = x + y + tmp;
            cur->next = new ListNode(sum % 10);
            tmp = sum / 10;
            cur = cur->next;
            if (l1)
                l1 = l1->next;
            if(l2)
                l2=l2->next;
        }
        if(tmp)
            cur->next = new ListNode(tmp);
        return dummy->next;
    }
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(), per = dummy,next=nullptr;
        dummy->next = head;
        listNode*p1 = head,*p2 = head;
        while(left-->0){
            per = per->next;
            p1 = p1->next;
        }
        while(right-->0){
            p2=p2->next;
        }
        next = p2->next;
        pair<ListNode *, ListNode *> tmp = myreverse(p1, p2);
        per->next=tmp.first;
        tmp.second->next = next;
        return dummy->next;
    }
    pair<ListNode*,ListNode*> myreverse(ListNode*head,ListNode*tail){
        ListNode*perv=tail->next,*cur=head,next=nullptr;
        while(perv!=tail){
            next=cur->next;
            cur->next=perv;
            perv=cur;
            cur=next;
        }
        return {tail,head};
    }
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int> ret;
        int left=0,right=n-1,top=0,bottom=m-1;
        while(left<=right&&top<=bottom){
            for (int i = left;i<=right;++i){
                ret.emplace_back(matrix[top][i]);
            }
            for (int j = top + 1;j<=bottom;++j){
                ret.emplace_back(matrix[j][right]);
            }
            if(left<right&&top<bottom){
                for (int k = right-1; k > left;--k){
                    ret.emplace_back(matrix[bottom][k]);
                }
                for (int l = bottom; l > top;--l){
                    ret.emplace_back(matrix[l][left]);
                }
            }
            ++left;
            ++top;
            --right;
            --bottom;
        }
        return ret;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        while(x < m&&y>=0){
            if(matrix[x][y]==target)return true;
            else if(matrix[x][y]>target)
                --y;
            else
                ++x;
        }
        return false;
    }
};
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode *> tmp;
        ListNode *node = head;
        while (node){
            tmp.emplace_back(node);
            node = node->next;
        }
        int l = 0,r=tmp.size()-1;
        while(l<r){
            tmp[l]->next = tmp[r];
            ++l;
            if(l==r)
                break;
            tmp[r]->next = tmp[l];
            --r;
        }
        tmp[l]->next=nullptr;
    }
};
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *mid = mid = midNode(head),*l1=head,*l2=mid->next;
        mid->next=nullptr;
        l2 = reverse(l2);
        merge(l1, l2);
    }
    ListNode* midNode(ListNode* head){
        ListNode *slow = head, *fast = head;
        while(fast->next&&fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode*head){
        if(!head||!head->next)
            return head;
        ListNode *newHead = reverse(head->next);
        ListNode *next = head->next;
        head->next=nullptr;
        next->next = head;
        return newHead;
    }
    void merge(ListNode*l1,ListNode* l2){
        ListNode *nec1 = nullptr, *nec2 = nullptr;
        while (l1 && l2){
            nec1 = l1->next;
            nec2=l2->next;
            l1->next = l2;
            l1=nec1;
            l2->next = l1;
            l2=nec2;
        }
    }
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        int len = getLength(head);
        for (int i = 1; i <= len - n;++i){
            prev = prev->next;
        }
        prev->next = prev->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
    int getLength(ListNode* head){
        int n = 0;
        while(head){
            ++n;
            head = head->next;
        }
        return n;
    }
};class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        
    }
    
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head),*prev=dummy,*fast=head;
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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        int l = 0, r = v.size() - 1;
        while(l<r){
            if(v[l]!=v[r])return false;
            ++l;
            --r;
        }
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *mid = midNode(head), *l1=head,*l2 = mid->next;
        mid->next = nullptr;
        l2 = reverse(l2);
        return compare(l1, l2);
    }
    ListNode* midNode(ListNode* head){
        ListNode *slow=head, *fast = head;
        while(fast->next&&fast->next->next){
            slow = slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        if(!head||!head->next)
            return head;
        ListNode *newHead = reverse(head->next);
        head->next->next=head;
        head->next=nullptr;
        return newHead;
    }
    bool compare(ListNode*l1,ListNode* l2){
        while(l1&&l2){
            if(l1->val!=l2->val)return false;
            l1 = l1->next;
            l2=l2->next;
        }
        return true;
    }
};
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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)return head;
        int tmp=0;
        ListNode*dummy=new ListNode(0,head),*prev=dummy,*cur=head;
        while(cur->next){
            if(cur->val==cur->next->val){
                tmp = cur->val;
                cur= cur->next->next;
                prev->next=cur;
                while(cur&&tmp==cur->val){
                    cur=cur->next;
                    prev->next = cur;
                }
            }else{
                cur = cur->next;
                prev = prev->next;
            }
        }
        return dummy->next;
    }
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode*newHead=head->next;
        head->next = swapPairs(newHead->next);
        newHead->next=head;
        return newHead;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return head;
        
        ListNode dummy (-1, head);
        ListNode *prev = &dummy;
        //循环条件一定要清楚的演示出来
        while (prev->next&&prev->next->next){
            ListNode *p1 = prev->next, *p2 = prev->next->next;
            prev->next = p2;
            p1->next = p2->next;
            p2->next = p1;
            prev = p1;
        }
        return dummy.next;
    }
};
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return{};
        vector<int> ret;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode*node=q.front();
                if(n==1){
                    ret.push_back(node->val);
                }
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        return ret;
    }
};
class Solution {
    vector<int> ret;

public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return ret;
    }
    void dfs(TreeNode* root,int level){
        if(!root)
            return;
        if(level==ret.size()){
            ret.push_back(root->val);
        }
        dfs(root->right, level + 1);
        dfs(root->left, level + 1); 
    }
};

#include<iostream>
#include <vector>
#include<queue>
using namespace std;

int main(){
    //输入
    int n;
    cin>>n;
    vector<int> nums(n),ans(n);
    for(int i = 0; i < n; i++){
        int num;
        cin>>num;
        nums[i] = num;
    }
    //结果ans
    queue<int> q;
    for (int i = 0; i < n; ++i){
        q.push(i);
    }
    for (int i = 0; i < n;++i){
        int c = 2,tmp;
        while(c--){
            tmp=q.front();
            q.pop();
            q.push(tmp);
        }
        ans[q.front()] = nums[i];
        q.pop();
    }
    //输出ans
    for (int j = 0; j < n; ++j){
        cout << ans[j] << " ";
    }
    return 0;
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, inorder, 0, preorder.size()-1, 0, inorder.size() - 1);
    }
    TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int pl, int pr, int il, int ir){
        if(pl>pr)return nullptr;
        int tmp=preorder[pl],ind=0;
        TreeNode *root = new TreeNode(tmp);

        for (int i = il;i<inorder.size();++i){
            if(tmp==inorder[i]){
                ind = i;
                break;
            }
        }
        int leftLen = ind - il;
        root->left = dfs(preorder, inorder, pl + 1, pl+leftLen, il, ind - 1);
        root->right = dfs(preorder, inorder, pl + leftLen + 1, pr, ind + 1, ir);
        return root;
    }
};
class Solution {
public:
    TreeNode* buildTree(vector<int>&preorder,vector<int>&inorder){
        int n = preorder.size();
        if (n==0)
            return NULL;

        unordered_map<int, int> hash;
        for (int i = 0;i<n;++i){
            hash.emplace(inorder[i], i);
        }
        return dfs(preorder, hash, 0,n-1 , 0);
    }
    TreeNode* dfs(vector<int> & preorder, unordered_map<int, int> & hash, int b, int e, int s){
        if(b>e)return nullptr;
        int index = hash[preorder[s]],leftLen=index-b;
        TreeNode *root = new TreeNode(preorder[s]);
        root->left = dfs(preorder, hash, b, index - 1, s + 1);
        root->right = dfs(preorder, hash, index + 1, e, s + leftLen + 1);
        return root;
    }
};

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode*curr = root;
        while(curr){
            if(curr->left){
                TreeNode *next = curr->left;
                while(next->right){
                    next = next->right;
                }
                next->right = curr->right;
                curr->right = curr->left;
                curr->left=nullptr;
            }
            curr = curr->right;
        }
        return;
    }
};
class Solution {
    int ans = 0;
    int depth(TreeNode* root){
        if(!root)
            return 0;
        int L=depth(root->left);
        int R=depth(root->right);
        ans = max(ans, L + R);
        return 1 + max(L, R);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return ans;
    }
};
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        int lm = minDepth(root->left), rm = minDepth(root->right);
        return !root->left || !root->right ? lm + rm + 1 : min(lm, rm) + 1;
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret={intervals[0]};
        for (int i = 1; i < intervals.size(); ++i){
            int n1 = ret.back()[1], n2 = intervals[i][0],n3=intervals[i][1];
            if (n1<n2){
                ret.emplace_back(intervals[i]);
            }else if(n1<n3){
                ret.back()[1] = n3;
            }
        }
        return ret;
    }
};
class Solution {
    vector<vector<int>> ret;
    vector<int> path;

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ret;
    }
    void dfs(TreeNode* root,int targetSum){
        if(!root)
            return;
        path.push_back(root->val);
        if (!root->left && !root->right && targetSum==root->val){
            ret.emplace_back(path);
        }else{
            dfs(root->left, targetSum - root->val);
            dfs(root->right, targetSum - root->val);
        }
        path.pop_back();
    }
};
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
class Solution {
    int maxSum;

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
    //以node为端点的最大路径的和
    int dfs(TreeNode*node){
        if(!node)
            return 0;
        int l = max(dfs(node->left), 0);
        int r = max(dfs(node->right), 0);
        maxSum = max(maxSum,node->val+l+r);
        return node->val + max(l, r);
    }
};
//dfs的中序遍历，在这过程中，始终保持前者比当前小
class Solution {
    long prev = LONG_MIN;
public:
    bool isValidBST(TreeNode* root) {
        if (!root->left&&!root->right)return true;
        return dfs(root);
    }
    bool dfs(TreeNode*root){
        if(!root)return true;
        bool l=dfs(root->left);
        if (prev >=root->val){
            return false;
        }else{
            prev = root->val;
        }
        bool r=dfs(root->right);
        return l&&r;
    }
};
class Solution {
    int Sum = 0;
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root);
    }
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        Sum = Sum * 10 + root->val;
        if(!root->left&&!root->right){
            return Sum;
        }else{
           return dfs(root->left) + dfs(root->right); 
        }    
    }
};
class Solution {
    int ret;
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ret;
    }
    //以node为端点的最大路径的和
    int dfs(TreeNode*root){
        if(!root)
            return 0;
        int l=max(0,dfs(root->left));
        int r = max(0,dfs(root->right));
        ret = max(ret, root->val + l + r);
        return root->val + max(l, r);
    }
};
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
    int dfs(TreeNode* root,int prevSum){
        if(!root)
            return 0;
        int sum = prevSum * 10 + root->val;
        if(!root->left&&!root->right){
            return sum;
        }else{
           return dfs(root->left, sum) + dfs(root->right, sum); 
        }    
    }
};
class Solution {
    int sum=0,tmp=0;
public:
    int sumNumbers(TreeNode* root) {
        dfs(root);
        return sum;
    }
    void dfs(TreeNode*root){
        if(!root)return;
        if(!root->left&&!root->right){
            sum+=tmp*10+root->val;
            return;
        }
        tmp=tmp*10+root->val;
        dfs(root->left);
        dfs(root->right);
        tmp/=10;
    }
};
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root){
            return 0;
        }
        int res = 0;
        queue<TreeNode*> q;
        root->val = 0;
        q.push(root);

        while (!q.empty()){
            // 基于目前队列头和尾获得当前层的宽度
            res = max(res, q.back()->val - q.front()->val + 1);

            // 编号缩小的差值
            int offset = q.front()->val;

            // 遍历完当前层
            int n = q.size();
            for (int i = 0; i < n; ++i){
                TreeNode* curr = q.front();
                q.pop();
                // 缩小数值
                curr->val -= offset;

                if (curr->left){
                    // 转换为对应的编号
                    curr->left->val = curr->val*2;
                    q.push(curr->left);
                }
                if (curr->right){
                    // 转换为对应的编号
                    curr->right->val = curr->val*2+1;
                    q.push(curr->right);
                }
            }
        }
        return res;
    }
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next)
            return head;
        int len = length(head);
        k = k % len;
        ListNode *dummy = new ListNode(0,head),*slow=dummy,*fast=head;
        if(k==0)return head;
        int tmp=k-1;
        while(tmp--){
            fast = fast->next;
        }
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *newHead = slow->next;
        slow->next=nullptr;
        fast->next = head;
        delete dummy;
        return newHead;
    }
    int length(ListNode* head){
        int len = 0;
        while(head){
            ++len;
            head = head->next;
        }
        return len;
    }
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || !head  || !head->next) {
            return head;
        }
        int n = 1;
        ListNode* iter = head;
        while (iter->next) {
            iter = iter->next;
            n++;
        }
        int add = n - k % n;
        if (add == n) {
            return head;
        }
        iter->next = head;
        while (add--) {
            iter = iter->next;
        }
        ListNode* ret = iter->next;
        iter->next = nullptr;
        return ret;
    }
};
class MinStack {
    stack<int> s;
    deque<int> q;

public:
    MinStack() {}
    
    void push(int val) {
        s.push(val);
        if(q.empty()||val<=q.back()){
            q.push_back(val);
        }
    }

    void pop() {
        
        if(s.top()==q.back()){
            q.pop_back();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return q.back();
    }
};
class MinStack {
    //要完成一个特殊性能要求的栈，我们可以封装几个基本栈，通过算法来实现
    stack<int> data_stack;
    stack<int> min_stack;

public:
    MinStack() {
        //data_stack=new stack ;
        //min_stack =new stack;
    }

    void push(int val) {
        if(min_stack.empty()||val<=min_stack.top())
            min_stack.push(val);
        data_stack.push(val);
    }

    void pop() {
        //先pop()min_stack，因为其中的值受data_stack影响
        if(min_stack.top()==data_stack.top())
            min_stack.pop();
        data_stack.pop();
    }
    
    int top() {
        return data_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
class Solution {
public:
    bool isValid(string s) {
        if(s.size()&1)return false;
        stack<char>st;
        unordered_map<char, char> hash = {{')', '('}, {']', '['}, {'}', '{'}};
        for(auto&ch:s){
            if(hash.count(ch)){
                if(st.empty()||st.top()!=hash[ch])
                    return false;
                st.pop();
            }else{
                st.push(ch);
            }
        }
        return st.empty();
    }
};
class MyQueue {
public:
    MyQueue() {}
    void push(int x) {
        in.push(x)
    }
    int pop() {
        int v=peek();
        out.pop();
        return v;
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
class Solution {
public:
    int calculate(string s) {
        vector<int> st;
        char prev = '+';
        int num = 0,n=s.size();
        for (int i = 0; i < n; ++i){
            if(isdigit(s[i])){
                num = num * 10 + (s[i]-'0');
            }
            if(!isdigit(s[i])&&s[i]!=' '||i==n-1){
                switch(prev){
                    case '+':
                        st.push_back(num);
                        break;
                    case '-':
                        st.push_back(-num);
                        break;
                    case '*':
                        st.back() *= num;
                        break;
                    default:
                        st.back() /= num;
                    }
                    num = 0;
                    prev = s[i];
            }
        }
        return accumulate(st.begin(), st.end(), 0);
    }
};
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int ind = 0;
        for (int i = 0; i < popped.size(); ++i){
            s.push(pushed[i]);
            while(!s.empty()&&popped[ind]==s.top()){
                s.pop();
                ++ind;
            }
        }
        return s.empty();
    }
};
class Solution {
    vector<string> ret;
    string str;

public:
    vector<string> generateParenthesis(int n) {
        backtrack(0,0,n);
        return ret;
    }
    void backtrack(int l,int r,int n){
        if(str.size()==n*2){
            ret.emplace_back(str);
            return;
        }
        if(l<n){
            str.push_back('(');
            backtrack(l + 1, r, n);
            str.pop_back();
        }
        if(r<l){
            str.push_back(')');
            backtrack(l, r + 1, n);
            str.pop_back();
        }
    }
};
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
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return 0;
        vector<int> dp(n, 0);
        for (int i = 2; i < n;++i){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                dp[i] = dp[i - 1] + 1;
            }
        }
        return accumulate(dp.begin(),dp.end(),0);
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        dp[0]=0;dp[1]=nums[0];
        for(int i=2;i<=n;++i){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return dp[n];
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[1]=nums[0];
        for (int i = 2; i <= n;++i){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return dp[n];
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int p1 = 0, p2 = 0,cur=0;
        for(auto&n:nums){
            cur = max(p2, p1 + n);
            p1 = p2;
            p2 = cur;
        }
        return p2;
    }
};
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),i=n-2;
        while(i>=0&&nums[i]>=nums[i+1]){
            --i;
        }
        if(i>=0){
            int j = n - 1;
            while(nums[i]>=nums[j]){
                --j;
            }
        }
        reverse(nums.begin() + r + 1, nums.end());
    }
};
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(),i=n-1;
        
        string ret,tmp;
        while(i>=0){
            if(s[i]==' '){
                reverse(tmp.begin(), tmp.end());
                ret += tmp + ' ';
                tmp.clear();
                while(s[i]==' '){
                    --i;
                }
            }
            tmp.push_back(s[i]);
            --i;
        }
        if(ret[0]==' ')
            ret.erase(tmp.begin());
        if(ret.(ret.size()-1)==' ')ret.pop_back();
        return ret;
    }
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode *prev = &dummy, *cur = head;
        while(cur&&cur->next){
            if(cur->val==cur->next->val){
                int tmp = cur->val;
                cur = cur->next->next;
                prev->next = cur;
                while (cur&&tmp==cur->val){
                    cur = cur->next;
                    prev->next = cur;
                }
            }else{
                cur = cur->next;
                prev=prev->next;
            }
        }
        return dummy.next;
    }
};
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for (int i = 1; i <= m;++i){
            for (int j = 1; j <= n;++j){
                if(text1[i-1]==text2[i-1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(),l=0,r=0;
        while(r<n){
            if(nums[r]==0){
                ++r;
            }else if(nums[r]&&nums[l]==0){
                swap(nums[l], nums[r]);
                ++r;
                ++l;
            }else{
                ++l;
                ++r;
            }
        }
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0;
        while (r < n) {
            if (nums[r]) {
                swap(nums[l], nums[r]);
                l++;
            }
            r++;
        }
    }
};
class Solution {
    vector<string> ret;
    string path="";

public:
    vector<string> restoreIpAddresses(string s) {
        backtrack(0, 0, s);
        return ret;
    }

    void backtrack(int level,int index,string&s){
        if(level==4||index==s.size()){
            if(level==4&&index==s.size()){
                ret.emplace_back(path.substr(0,path.size()-1));
            }
            return;
        }

        for (int i = 1; i <= 3;++i){
            if(index+i>s.size())
                return;
            if(s[index]=='0'&&i>1)
                return;
            if(i==3&&s.substr(index,3)>"255")
                return;

            path += s.substr(index, i) + ".";
            backtrack(level + 1, index + i, s);
            path = path.substr(0, path.size() - i - 1);
        }
    }
};
class Solution {
    int perv = 0;
public:
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        if(!isValidBST(root->left))return false;
        if(perv>root->val){
            return false;
        }else{
            perv = root->val;
        }
        if(!isValidBST(root->right))return false;
        return true;
    }
};
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m;++i){
            dp[i][0] = 1;
        }
        for (int j = 0; j < n;++j){
            dp[0][j] = 1;
        }

        for (int i = 1; i < m;++i){
            for (int j = 1; j < n;++j){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 1; i < m; i++) grid[i][0] += grid[i - 1][0];
        for (int j = 1; j < n; j++) grid[0][j] += grid[0][j - 1];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), ans = 0;
        for (int i = 0; i < m;++i){
            for (int j = 0; j < n;++j){
                int p1 = i, p2 = j,count=0;
                while(p1<m&&p2<n&&nums1[p1]==nums2[p2]){
                    ++count;
                    ++p1;
                    ++p2;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), ans = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for (int i = 1; i <=m; ++i){
            for (int j = 1; j <=n;++j){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
class Solution {
    vector<vector<int>>ret;
    vector<int>tmp;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return ret;
    }
    void backtrack(vector<int>&nums,int pos){
        ret.emplace_back(tmp);
        if(pos==nums.size())
            return;
        for (int i = pos; i < nums.size();++i){
            tmp.push_back(nums[i]);
            backtrack(nums, pos);
            tmp.pop_back();
        }
    }
};
class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n1 = count(v1.begin(),v1.end(),'.'), n2 = count(v2.begin(),v2.end(),'.'),k=n1-n2,c=n1;
        if(k>0){
            while(k--){
                v2+=".0";
            }
        }else if(k<0){
            k = -k;
            c = n2;
            while (k--){
                v1+=".0";
            }
        }
        v1 += ".";
        v2 += ".";
        c += 1;
        return help(v1, v2, c);
    }
    int help(string v1, string v2,int c){
        int i = 0, j = 0, p1 = 0, p2 = 0, m = v1.size(), n = v2.size();
        while (c--){
            int tmp1 = 0,tmp2 = 0;
            while (i < m){
                if(v1[i]=='.'){
                    // tmp1 = atoi(v1.substr(p1, i - p1).c_str());
                    tmp1 = stoi(v1.substr(p1, i - p1));
                    ++i;
                    p1 = i;
                    break;
                }
                ++i;
            }
            while(j<n){
                if(v2[j]=='.'){
                    // tmp2 = atoi(v2.substr(p2, j - p2).c_str());
                    tmp2 = atoi(v2.substr(p2, j - p2));
                    ++j;
                    p2 = j;
                    break;
                }
                ++j;
            }
            if(tmp1!=tmp2){
                return tmp1 > tmp2 ? 1 : -1;
            }
            
        }
        return 0;
    }
};
class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n = v1.length(), m = v2.length();
        int i = 0, j = 0;
        while (i < n || j < m) {
            long x = 0;
            for (; i < n && v1[i] != '.'; ++i) {
                x = x * 10 + v1[i] - '0';
            }
            ++i; // 跳过点号
            long y = 0;
            for (; j < m && v2[j] != '.'; ++j) {
                y = y * 10 + v2[j] - '0';
            }
            ++j; // 跳过点号
            if (x != y) {
                return x > y ? 1 : -1;
            }
        }
        return 0;
    }
};
class Solution {
public:
    int compareVersion(string v1, string v2) {
        int flag=1;
        if(v1.size()<v2.size()){
            swap(v1,v2);
            flag=-1;
        }//使version1比version2长
        stringstream ss1(v1),ss2(v2);
        string temp1,temp2;
        while(getline(ss1,temp1,'.')){//分割字符串
            if(!getline(ss2,temp2,'.'))temp2="0";
            int l=stoi(temp1),r=stoi(temp2);//去除前导零并比较
            if(l>r)return 1*flag;
            else if(l<r)return -1*flag;
            temp1="";
            temp2="";
        }
        return 0;
    }
};
class Solution {
    vector<vector<int>> ret;
    vector<int> path;

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ret;
    }
    void dfs(TreeNode* root,int targetSum){
        if(!root)
            return;
        path.push_back(root->val);
        if(!root->left&&!root->right&&root->val==targetSum){
            ret.emplace_back(path);
            return;
        }
        dfs(root->left, targetSum - root->val);
        dfs(root->right, targetSum - root->val);
        path.pop_back();
    }
};
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
        if(target<0)
            return;
        if(target==0){
            ret.emplace_back(path);
            return;
        }
        for (int i = pos; i < candidates.size();++i){
            path.push_back(candidates[i]);
            backtrack(candidates, target-candidates[i],pos);
            path.pop_back();
        }
    }
};
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 水平翻转
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        // 主对角线翻转
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2;++i){
            for (int j = 0; j < n;++j){
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }
        for (int i = 0; i < n;++i){
            for (int j = 0; j < i;++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return {-1, -1};
        int l=lower_bound(nums,target);
        int r = upper_bound(nums, target);
        if(r==nums.size()||nums[l]<target)
            return {-1, -1};
        return {l, r};
    }
    int lower_bound(vector<int>&nums,int target){
        int n=nums.size(),l=0,r=n,mid;
        while(l<r){
            mid = l + (r - l) / 2;
            if(nums[mid]>=target)
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
    int upper_bound(vector<int>&nums,int target){
        int n=nums.size(),l=0,r=n,mid;
        while(l<r){
            mid = l + (r - l) / 2;
            if(nums[mid]>target)
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ret = 0,n=nums.size(),l=0;
        while(l<n){
            int r = l,tmp=k;
            while(r<n){
                tmp-=nums[r];
                if(tmp==0){
                    ++ret;
                }
                ++r;
            }
            ++l;
        }
        return ret;
    }
};
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum<target)
            return 0;
        int n=nums.size();
        for (int i = 1; i <= n;++i){
            for (int l = 0; l < n;++l){
                int r = l + i - 1;
                if(r>=n)continue;
                int sum = accumulate(nums.begin() + l, nums.begin() + r+1, 0);
                if(sum>=target){
                    return i;
                }
            }
        }
        return 0;
    }
};
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
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(), int i = n - 1;
        string ret = "", tmp = "";
        while(i>=0){
            if(s[i]==' '){
                if(!tmp.empty()){
                    reverse(tmp.begin(), tmp.end());
                    ret += tmp + ' ';
                    tmp.clear();
                }
                while(i>=0&&s[i]=' ')
                    --i;
            }
            while(i>=0&&s[i]!=' '){
                tmp.push_back(s[i]);
                --i;
            }
            if(i=-1&&!tmp.empty()){
                reverse(tmp.begin(), tmp.end());
                ret += tmp;
            }
        }
        if(ret[ret.size()-1]==' ')ret.pop_back();
        return ret;
    }
};
class Solution {
public:
    int rand10() {
        int a = 7, b = 7;
        while(a==7)
            a = rand7();
        while(b>5)
            b = rand7();
        return a & 1 ? b : b + 5;
    }
};
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size(),ret=0;
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for (int i = 1; i <= m;++i){
            for (int j = 1; j <= n;++j){
                if(A[i-1]==B[j-1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                ret = max(ret, dp[i][j]);
            }
        }
        return ret;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, minProfit = prices[0];
        for(auto&p:prices){
            maxProfit = max(maxProfit, p - minProfit);
            minProfit = min(minProfit, p);
        }
        return maxProfit;
    }
};
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        st.push(1);
        int flag = 1;

        int ret = 0, n = s.size(),i=0;
        while (i<n){
            if(s[i]==' '){
                ++i;
            }else if(s[i]=='+'){
                flag = st.top();
                ++i;
            }else if(s[i]=='-'){
                flag = -st.top();
                ++i;
            }else if(s[i]=='('){
                st.push(flag);
                ++i;
            }else if(s[i]==')'){
                st.pop();
                ++i;
            }else{
                long num = 0;
                while (i < n&& isdigit(s[i])){
                    num = num * 10 + s[i] - '0';
                    ++i;
                }
                ret += flag * num;
            }
        }
        return ret;
    }
};
class Solution {
public:
    string removeKdigits(string num, int k) {
        string stk;
        for (auto& x: num) {
            while (stk.size() && stk.back() > x && k) {
                stk.pop_back();
                --k;
            }
            stk.push_back(x);
        }
        while(k--){
            stk.pop_back();
        }
        int pos = 0;
        while(pos<stk.size()&&stk[pos]=='0'){
            ++pos;
        }
        stk = stk.substr(pos, stk.size() - pos);
        return stk == "" ? "0" : stk;
    }
};
class MyStack {
    queue<int> q;
public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
    }

    int pop() {
        int a=q.back(),i=q.size()-1;
        while(i--){
            q.push(q.front());
            q.pop();
        }
        q.pop();
        return a;
    }

    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ret(n, 0);
        stack<int> ind;

        for (int i = 0; i < n;++i){
            while(!ind.empty()){
                int pre_i = ind.top();
                if(t[i]<=t[pre_i]){
                    break;
                }
                ind.pop();
                ret[pre_i] = i - pre_i;
            }
            ind.push(i);
        }
        return ret;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = strs[0];
        for (int i = 1; i < strs.size();++i){
            string tmp = common(ret, strs[i]);
            if(tmp!=""){
                ret = tmp;
            }else{
                return "";
            }
        }
        return ret;
    }
    string common(string&s1,string&s2){
        int n1 = s1.size(), n2 = s2.size(), i = 0;
        string s = "";
        while (i < n1 && i < n2){
            if(s1[i]==s2[i]){
                s.push_back(s1[i]);
            }else
                break;
            ++i;
        }
        return s;
    }
};
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int prev = INT_MIN, i = 0, n = nums.size();
        nums.push_back(INT_MIN);
        while(i<n){
            if(prev<nums[i]&&nums[i]>nums[i+1]){
                return i;
            }else{
                ++i;
            }
        }
        return 0;
    }
};
class Solution {
public:
    int climbStairs(int n) {
        if(n<2)
          return n;
        int p1 = 1, p2 = 2, cur = 0;
        for (int i = 3; i <= n;++i){
            cur = p1 + p2;
            p1 = p2;
            p2 = cur;
        }
        return cur;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, minPrices = prices[0];
        for(auto&p:prices){
            maxProfit = max(maxProfit, p - minPrices);
            minPrices = min(p, minPrices);
        }
        return maxProfit;
    }
};
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n + 1);
        ret[0] = 0;
        for (int i = 1; i <= n; ++i){
            ret[i] = i & 1 ? ret[i - 1] + 1 : ret[i >> 1];
        }
        return ret;
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n<2)
            return s;

        int begin = 0, maxLen = 1;
        vector<vector<bool>> dp(n, vector<int>(n));
        for (int i = 0; i < n;++i){
            dp[i][i] true;
        }

        for (int L = 2; L <= n;++L){
            for (int l = 0; l < n;++l){
                int r = l + L - 1;
                if(r>=n)
                    break;
                
                if(s[l]!=s[r]){
                    dp[l][r] = false;
                }else{
                    if(L==2){
                        dp[l][r] = true;
                    }else{
                        dp[l][r] = dp[l + 1][r - 1];
                    }
                }

                if(dp[l][r]&&L>maxLen){
                    begin = l;
                    maxLen = L;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};
class Solution {
    vector<string> ret;
    string str="";

public:
    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, n);
        return ret;
    }
    void backtrack(int l,int r,int n){
        if(str.size()==2*n){
            ret.emplace_back(str);
            return;
        }

        if(l<n){
            str += "(";
            backtrack(l + 1, r, n);
            str.pop_back();
        }
        if(r<l){
            str += ")";
            backtrack(l, r + 1, n);
            str.pop_back();
        }
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = 0,ret=nums[0];
        for(auto&n:nums){
            prev = max(prev, n);
            ret = max(ret, prev);
        }
        return ret;
    }
};
class Solution {
public:
    bool canJump(vector<int>&nums){
        int n = nums.size();
        vector<bool> dp(n,false);
        dp[0] = true;
        int perv = 0;
        for (int i = 0; i < n; ++i){
            for (int k = perv+1; k <= nums[i] + i&&k<n;++k){
                if(dp[i]){
                    dp[k] = true;
                }else{
                    break;
                }
            }
            perv = nums[i] + i;
        }
        return dp[n - 1];
    }
}
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farest = 0, n = nums.size();
        for (int i = 0; i < n;++i){
            if(i<=farest){
                farest = max(farest, nums[i] + i);
            }
            if(farest>=n-1)
                return true;
        }
        return false;
    }
};
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m;++i){
            dp[i][0] = 1;
        }
        for (int i = 0; i < n;++i){
            dp[0][i] = 1;
        }

        for (int i = 1; i < m;++i){
            for (int j = 1; j < n;++j){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n;++i){
            for (int j = 0; j < n;++j){//j表示左子树的节点数
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};
class Solution{
public:
    bool canPlaceFlowers(vector<int> &f,int n){
        for (int i = 0; i < f.size();){
            if(f[i]==1){
                i += 2;//遇到1,直接跳到下一步的下一步判断
            }else if(i==f.size()-1||f[i+1]==0){//经过前面if，0的前一个必定是0,此处可1，就变成了前面if的情况
                --n;
                i += 2;
            }else{
                i += 3;
            }
        }
        return n <= 0;
    }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for (int i = 1; i <= n;++i){
            for(auto &w:wordDict){
                int len = w.size();
                if(i>=len&&s.substr(i-len,len)==w){
                    dp[i] = dp[i] || dp[i - len];
                }
            }
        }
        return dp[n];
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int p1 = 0, p2 = 0, cur = 0;
        for(auto&n:nums){
            cur = max(p2, p1 + n);
            p1 = p2;
            p2 = cur;
        }
        return cur;
    }
};
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(),max_len=0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));//存放对应坐标产生方块的边长
        for (int i = 1; i <= m;++i){
            for (int j = 1;j<=n;++j){
                if(matrix[i-1][j-1]=='1'){
                    //min(左，上，左上)+1；
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]))+1;
                }
                max_len = max(max_len, dp[i][j]);
            }
        }
        return max_len*max_len;
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxn = nums[0], minn = nums[0], ret=nums[0];
        for (int i = 1;i<nums.size();++i){
            int x = nums[i];
            maxn = max(maxn * x, max(x, x * minn));
            minn = min(minn * x, min(x, maxn * x));
            ret = max(ret, maxn);
        }
        return ret;
    }
};

class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while(x!=0){
            if(ret<min/10||ret>max/10)
                return 0;
            int mod = x % 10;
            x /= 10;
            ret = ret * 10 + mod;
        }
        return ret;
    }

private:
    int min = INT_MIN;
    int max = INT_MAX;
};
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n;++i){
            for (int j = 1; j * j <= i;++j){
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
class Solution{
    vector<int> d = {-1, 0, 1, 0, -1};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size(),ret=0;
        for (int i = 0; i < m;++i){
            for (int j = 0; j < n;++j){
                if(grid[i][j]){
                    ret = max(ret, dfs(grid, i, j));
                }
            }
        }
        return ret;
    }
    int dfs(vector<vector<int>>&grid,int i,int j){
        if(grid[i][j]==0)
            return 0;
        grid[i][j] = 0;
        int x, y, tmp = 1;
        for (int k = 0; k < 4; ++k){
            x = i + d[k], y = j + d[k + 1];
            if(x>=0&&x<grid.size()&&y>=0&&y<grid[0].size()){
                tmp += dfs(grid, x, y);
            }
        }
        return tmp;
    }
};
class Solution {
    vector<int> d = {-1, 0, 1, 0, -1};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),ans=0;
        for (int i = 0;i<m;++i){
            for (int j = 0; j < n;++j){
                if(grid[i][j]){
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>&grid,int i,int j){
        if (!grid[i][j])
            return 0;
        grid[i][j] = 0;
        int area = 1, x, y;
        for (int k = 0; k < 4; ++k){
            x = i + d[k], y = j + d[k + 1];
            if(x>=0&&x<grid.size()&&y>=0&&y<grid[0].size()){
                area+=dfs(grid, x, y);
            }
        }
        return area;
    }
};
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int lm = minDepth(root->left), rm = minDepth(root->right);
        return !root->left || !root->right ? lm + mr + 1 : 1 + min(lm, rm);
    }
};
class String{
public:
    String();
    String(const string *str = nullptr);
    String(const String &str)();
    String &operator=(const String &str);
    ~String();
private:
    char *m_data;
};
String::String(const string *str=nullptr){
    if(str==nullptr){
        m_data = new char[1];
        *m_data = '0';
    }else{
        int len=strlen(str);
        m_data = new char[len+1];
        strcpy(m_data, str);
    }
}
String::String(const string&str){
    int len = strlen(str);
    m_data=new char[len+1];
    strcpy(m_data, str);
}
String::String& operator=(const String &str){
    if(this==&str){
        return *this;
    }
    delete[] m_data;
    int len = strlen(str.m_data);
    m_data=new char[len+1];
    strcpy(m_data, str.m_data);
    return *this;
}
String::~String(){
    delete[] m_data; 
}
class String{
public:
    String();
    String(const string *str = nullptr);
    String(const String &str);
    String &operator=(const String &str);
    ~String();
private:
    char *m_data;
};
String::String(const string *str=nullptr){
    if(str==nullptr){
        m_data = new char[1];
        *m_data = '0';
    }else{
        int len = strlen(str);
        m_data = new char[len+1];
        strcpy(m_data, str);
    }
}
String::String(const string&str){
    int len = strlen(str.m_data);
    m_data = new char[len+1];
    strcpy(m_data, str.m_data);
}
String::String& operator=(const String &str){
    if(this==&str){
        return *this;
    }
    
    delete[] m_data;
    int len = strlen(str.m_data);
    m_data = new char[len + 1];
    strcpy(m_data, str.m_data);
    return *this;
}
Stirng::~String(){
    delete[] m_data;00000
}
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(),max_len=0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m;++i){
            for (int j = 1; j <= n;++j){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]))+1;
                }
                max_len = max(max_len, dp[i][j]);
            }
        }
        return max_len * max_len;
    }
};
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1,INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n;++i){
            for (int j = 1; j * j <= i;++j){
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for (int i = 0; i < n;++i){
            int tmp = 1,prev=nums[i];
            for (int j = i; j < n; ++j){
                if(nums[j]>prev){
                    ++tmp;
                    prev = nums[j];
                }
            }
            ans = max(tmp, ans);
            if(ans>=n-i)
                break;
        }
        return ans;
    }
};
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1;i<=amount;++i){
            for (int j = 0;j<coins.size();++j){
                if(coins[j]<=i){
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] < amount ? dp[amount] : -1;
    }
};
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        if(n<2)return false;

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1)
            return false;

        int target = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n;++i){
            int tmp = nums[i - 1];
            for (int j = 1; j <= target;++j){
                if(tmp<=j){
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - tmp];
                }else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][target];
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int p1 = 0, p2 = 0, cur = 0;
        for(auto&n:nums){
            cur = max(n + p1, p2);
            p1 = p2;
            p2 = cur;
        }
        return cur;
    }
};

class Solution {
    unordered_map<TreeNode *, int> Y, N;

public:
    int rob(TreeNode* root) {
        dfs(root);
        return max(Y[root], N[root]);
    }
    void dfs(TreeNode* root){
        if(!root)
            return;
        dfs(root->left);
        dfs(root->right);
        //Y,N分别表示选和不选节点node的最值
        Y[root] = root->val + N[root->left] + N[root->right];
        N[root] = max(Y[root->left], N[root->left]) + max(Y[root->right], N[root->right]);
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, minPrice = prices[0];
        for(auto&p:prices){
            maxProfit = max(maxProfit, p - minPrice);
            minPrice = min(minPrice, p);
        }
        return maxProfit;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {

    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //f表示三态对应的Max利润
        int f0 = -prices[0], f1 = 0, f2 = 0;
        for (int i = 1;i<prices.size();++i){
            int nf0 = max(f0, f2 - prices[i]);
            int nf1 = f0 + prices[i];
            int nf2 = max(f2, f1);
            f0 = nf0, f1 = nf1, f2 = nf2;
        }
        return max(f1, f2);
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        else if(n==2)
            return max(nums[0],nums[1]);
        else
            return max(help(nums, 0, n - 2), help(nums, 1, n - 1));
    }
    int help(vector<int>&nums,int start,int end){
        int p1 = 0, p2 = 0, cur = 0;
        for (int i = start; i <= end;++i){
            cur = max(p2, p1 + nums[i]);
            p1 = p2;
            p2 = cur;
        }
        return cur;
    }
};

//使用零拷贝技术
#include <sys/sendfile.h>
int main(){
    fdA = open("file_A", O_CREAT | O_RDONLY | O_APPEND);
    fdb = open("file_B", O_CREAT | O_WRONLY | O_APPEND);

	if (fdA < 0||fdB < 0)
	{
		perror("open file error");
		return 0;
	}
    else{
        int len=sendfile(fdB,fdA,0,1024);
        if(len<0){
           perror("sendfile error"); 
        }
        printf("发出了%d个字节\n",len);
    }
    return 0;
}


class Solution {
private:
    static bool cmp(int &a,int &b){
        string sa = to_string(a), sb = to_string(b);
        return sa + sb > sb + sa;
    }
public:
    string largestNumber(vector<int>&nums){
        string ret;
        sort(nums.begin(), nums.end(), cmp);
        for(int& n:nums){
            ret+=to_string(n);
        }
        if(ret[0]=='0')
            return "0";
        return ret;
    }
}
class Solution {
    unordered_map<Node *, Node *> hash;

public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        if(!hash.count(head)){
            Node *newNode = new Node(head->val);
            hash[head] = newNode;
            newNode->next = copyRandomList(head->next);
            newNode->random = copyRandomList(head->random);
        }
        return hash[head];
    }
};
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int falg = 1;
        st.push(1);

        int n = s.size(), ret = 0,i=0;
        while(i<n){
            if(s[i]==' '){
                ++i;
            }else if(s[i]=='+'){
                falg = st.top();
                ++i;
            }else if (s[i] == '-'){
                falg = -st.top();
                ++i;
            }else if (s[i] == '('){
                st.push(falg);
                ++i;
            }else if(s[i]==')'){
                st.pop();
                ++i;
            }else{
                long num=0;
                while(i<n&&isdigit(s[i])){
                    num = num * 10 + s[i] - '0';
                    ++i;
                }
                ret += falg*num;
            }
            return ret;
        }
    }
};
class Solution {
private:
    static bool cmp(int &a,int &b){
        string sa = to_string(a);
        string sb = to_string(b);
        return sa + sb > sb + sa;
    }

public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(nums.begin(), nums.end(), cmp);
        for(int &n:nums){
            ans+=to_string(n);
        }
        return ans[0] == '0' ? "0" : ans;
    }
};
class Solution {
public:
    int calculate(string s) {
        vector<int> v;
        char prev = '+';
        int num = 0;
        for (int i = 0; i < s.size();++i){
            if(isdigit(s[i])){
                num = num * 10 + s[i] - '0';
            }
            //一个数字结束，要进行操作
            if(!isdigit(s[i])&&s[i]!=' '||i==s.size()-1){
                switch(prev){
                    case '+':
                        v.push_back(num);
                        break;
                    case '-':
                        v.push_back(-num);
                        break;
                    case '*':
                        v.back() *= num;
                        break;
                    default:
                        v.back() /= num;
                    }
                num = 0;
                prev = s[i];
            } 
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};
class Solution {
public:
    int trap(vector<int>& h) {
        int ret = 0, l = 0, r = h.size() - 1, lMax = 0, rMax = 0;
        while(l<r){
            //维护朝向单调增
            lMax = max(lMax, h[l]);
            rMax = max(rMax, h[r]);
            //由于Max向着扫描方向维持着单调性，所以走到某个位置直接可以通过比较确定当前雨水量
            if(h[l]<h[r]){
                ret += lMax - h[l];
                ++l;
            }else{
                ret += rMax - h[r];
                --r;
            }
        }
        return ret;
    }
};
class Solution {
public:
    int trap(vector<int>& h) {
        int ret = 0, l = 0, r = h.size() - 1, lMax = 0, rMax = 0;
        while(l<r){
            //维护朝向的单调增
            lMax = max(lMax, h[l]);
            rMax = max(rMax, h[r]);

            //下面双指针的特征，遇到情况处理
            if(h[l]<h[r]){
                ret += lMax - h[l];
                ++l;
            }else{
                ret += rMax - h[r];
                --r;
            }
        }
        return ret;
    }
};
class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        if(n==0)
            return 0;
        vector<int>leftMax(n),rightMax(n);
        leftMax[0] = h[0];
        for (int i = 1; i < n;++i){
            leftMax[i] = max(leftMax[i - 1], h[i]);
        }
        rightMax[n - 1] = h[n - 1];
        for (int i = n - 2; i >= 0;--i){
            rightMax[i] = max(rightMax[i + 1], h[i]);
        }
        int ret = 0;
        for (int i = 0; i < n;++i){
            ret += min(leftMax[i], rightMax[i]) - h[i];
        }
        return ret;
    }
};
class Solution {
public:
    int trap(vector<int>& h) {
        int ret = 0, n = h.size();
        if(h==0)
            return 0;
        vector<int> lMax(n), rMax(n);
        lMax[0] = h[0], rMax[n - 1] = h[n - 1];

        for (int i = 1; i < n;++i){
            lMax[i] = max(lMax[i - 1], h[i]);
        }
        for (int j = n - 2; j >= 0;--j){
            rMax = max(rMax[j + 1], h[j]);
        }

        for (int i = 0; i < n;++i){
            ret += min(lMax[i], rMax[i]) - h[i];
        }
        return ret;
    }
};
class LRUCache {
public:
    LRUCache(int capacity):m_c(capacity){}
    
    int get(int key) {
        auto it=hash.find(key);
        if(it==hash.end())
            return -1;
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = hash.find(key);
        if(it!=hash.end()){
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
        }else{
            cache.emplace(cache.begin(), make_pair(key, value));
            hash[key] = cache.begin();
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
class LRUCache {
public:
    LRUCache(int capacity):m_c(capacity) {}
    
    int get(int key) {
        auto it = hash.find(key);
        if (it==hash.end()){
            return -1;
        }
        //splice字符串剪贴函数，将it->second的元素剪贴到首部(此函数操作对象时迭代器)
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = hash.find(key);
        if (it!=hash.end()){
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
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
    //当既要k索引v，又要v索引k，使用如下存储方式
    list<pair<int, int>> cache;//存放k-v
    unordered_map<int, list<pair<int, int>>::iterator> hash;//以k索引k-v节点的
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
       if(!head||!head->next)
           return head;
       ListNode *p=head;

       while(p->next){
           if(p->val==p->next->val){
               p->next = p->next->next;
           }else{
               p = p->next;
           }
       }
       return head;
    }
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       if(!head||!head->next)
           return head;
       ListNode *newHead = reverseList(head->next);
       head->next->next = head;
       head->next = nullptr;
       return newHead;
    }
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       if(!head||!head->next)return head;
       ListNode *p = nullptr, *cur = head;
       while(cur){
           ListNode *next = cur->next;
           cur->next = p;

           p = cur;
           cur = next;
       }
       return p;
    }
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(head),*p=dummy,*cur=head;
        while(cur&&cur->next){
            if(cur->val==cur->next->val){
                //遇到等值的点，先处理了这两个，拿到值后面一个一个地对比
                int tmp = cur->val;
                cur = cur->next->next;

                while(cur&&cur->val==tmp){
                    cur = cur->next;
                }
                //问题点都跑完了，再接上
                p->next = cur;
            }else{
                cur=cur->next;
                p = p->next;
            }
        }
        ListNode *newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> ret;
        queue<TreeNode * > q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            ret.emplace_back({});
            while (sz--){
                TreeNode*root=q.front();
                q.pop();
                ret.back().push_back(root->val);
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
        }
        return ret;
    }
};
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        dfs(root,ret);
        return ret;
    }
    void dfs(TreeNode* root,vector<int>&ret){
        if(!root)
            return;
        ret.emplace_back(root->val);
        dfs(root->left, ret);
        dfs(root->right, ret);
    }
};
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        vector<int> ret;
        stack<TreeNode *> st;
        while(root||!st.empty()){
            while(root){
                ret.emplace_back(root->val);
                st.push(root);
                root=root->left;
            }
            root = st.top()->right;
            st.pop();
        }
        return ret;
    }
};
pair<ListNode*,ListNode*> myReverse(ListNode*head,ListNode*tail){
        ListNode*prev=tail->next,*cur=head,*next=nullptr;
        while(prev!=tail){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return {tail,head};
    }

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode*root,TreeNode*p,TreeNode*q){
        if(!root||root==p||root==q)
            return head;
        ListNode *left = lowestCommonAncestor(root->left);
        ListNode *right = lowestCommonAncestor(root->right);
        if(!left)return right;
        if(!right)return left;
        if(left&&right)return root;
        return nullptr;
    }
};
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root ? 1 + max(maxDepth(root->left), maxDepth(root->right)) : 0;
    }
};
class Solution {
public:
    TreeNode* buildTree(vector<int>&preorder,vector<int>&inorder){
        int n = preorder.size();
        if(n==0)
            return nullptr;
        unordered_map<int, int> hash;//值——下标
        for (int i = 0; i < n; ++i){
            hash.emplace(inorder[i], i);
        }
        return dfs(preorder, hash, 0, n - 1, 0);
    }
    TreeNode* dfs(vector<int>&preorder,unordered_map<int, int>&hash,int b,int e,int pb){
        if(b>e)
            return nullptr;
        int i = hash[preorder[ps]], leftLen = i - b;
        TreeNode *root = new TreeNode(preorder[s]);
        root->left = dfs(preorder, hash, b, i - 1, pb + 1);
        root->right = dfs(preorder, hash, i + 1, e, s + leftLen + 1);
        return root;
    }
};
ListNode* merge(ListNode*l1,ListNode*l2){
    if(!l1){
        return l2;
    }else if(!l2){
        return l1;
    }else if(l1->val<l2->val){
        l1->next = merge(l1->next, l2);
        return l1;
    }else{
        l2->next = merge(l1, l2->next);
        return l2;
    }
}
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> hash;
        for(int&n:nums){
            hash.insert(n);
        }
        vector<int> ret;
        for (int i = 1; i <= n; ++i){
            if(!hash.count(i))
                ret.push_back(i);
        }
        return ret;
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ret = 0, prev = 0;
        unordered_map<int, int> hash;
        hash[0]++;
        for(int &n:nums){
            prev += n;
            if(hash.count(prev-k))
                ret += hash[prev - k];
            hash[prev]++;
        }
        return ret;
    }
};
class Solution {
private:
    vector<vector<int>> ret;
    vector<int> path;
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrace(candidates, target, 0);
        return ret;
    }
    void backtrace(vector<int>&candidates,int target,int pos){
        if(target<0)
            return;
        if(target==0){
            ret.emplace_back(path);
            return;
        }
        for (int i = pos; i < candidates.size();++i){
            path.push_back(candidates[i]);
            backtrace(candidates, target - candidates[i], i);
            path.pop_back();
        }
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), f0 = 0, f1 = -prices[0];
        for (int i = 1; i < n;++i){
            f0 = max(f0, f1 + prices[i]);
            f1 = max(f1, f0 - prices[i]);
        }
        return f0;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size(), f0 = 0, f1 = -p[0];
        for(int&x:p){
            f0 = max(f0, f1 + x);
            f1 = max(f1, f0 - x);
        }
        return f0;
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<2)return s

        vector<vector<bool>dp(n,vector<bool>(n));
        int maxL = 0, b = 0;

        for (int i = 0; i < n;++i){
            dp[i][i] = true;
        }

        for (int L = 2; L <= n;++L){
            for (int l = 0; l < n;++l){
                int r = l + L + 1;
                if(r>=n)
                    break;
                
                if(s[l]!=s[r]){
                    dp[l][r] = false;
                }else{
                    if(L==2){
                        dp[l][r] = true;
                    }else{
                        dp[l][r] = dp[l + 1][r - 1];
                    }
                }
                if(dp[l][r]&&L>maxL){
                    maxL = L;
                    b = l;
                }
            }
        }
        return s.substr(b, maxL);
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        vector<int> v(128, 0);
        for (int l = 0, r = 0; r < s.size(); ++r){
            ++v[s[r]];
            while(v[s[r]]>1){
                --v[s[l]];
                ++l;
            }
            ret = max(ret, r - l + 1);
        }
        return ret;
    }
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA,*q=headB;
        unordered_set<ListNode *> hash;
        while(p){
            hash.insert(p);
            p = p->next;
        }
        while(q){
            if(hash.count(q))
                return q;
            q = q->next;
        }
        return nullptr;
    }
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        while(p!=q){
            p = p ? p->next : headA;
            q = q ? q->next : headB;
        }
        return p;
    }
};
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
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l<r){
            int m = l + (r - l) / 2;
            if(nums[m]>nums[m+1])
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
class Solution {
    vector<vector<int>> ret;

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root,0);
        return ret;
    }
    void dfs(TreeNode* root,int level){
        if(!root)
            return;
        if(ret.size()==level){
            ret.push_back({});
        }
        ret[level].push_back(root->val);
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int fast = 0;
        for (int i = 0; i < nums.size();++i){
            if(i<=fast){
                fast = max(fast, i + nums[i]);
                if(fast>=nums.size()-1)
                    return true;
            } 
        }
        return false;
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        int farst = 0, p = 0, n = nums.size(),ret=0;
        for (int i = 0; i < n - 1;++i){
            if(i<=farst){
                farst = max(farst, i + nums[i]);
                if(i==p){
                    p = farst;
                    ++ret;
                }
            }
        }
        return ret;
    }
};
class Solution {
    unordered_map<Node *, Node *> hash;
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        if(!hash.count(head)){
            ListNode *Newhead = new ListNode(head->val);
            hash[head] = Newhead;
            Newhead->next = copyRandomList(head->next);
            Newhead->random = copyRandomList(head->random);
        }
        return hash[head];
    }
};
char* strcpy(char*a,char*b){
    if(!a||!b){
        cout << "空指针"<<endl;
        return nullptr;
    }
    char *p = a;
    while(*b!='\0'){
        *(p++) = *(b++);
    }
    return a;
}
class Solution {
   vector<vector<int>>ret;
   vector<int>path;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ret;
    }
    void dfs(TreeNode* root,int targetSum){
        if(!root)
            return;
        path.push_back(root->val);
        if(!root->left&&!root->right&&root->val==targetSum){
            ret.push_back(path);
        }
        dfs(root->left, targetSum-root->val);
        dfs(root->right, targetSum-root->val);
        path.pop_back();
    }
};
class Solution {
    int ret = 0, tmp = 0;

public:
    int sumNumbers(TreeNode* root) {
        dfs(root);
        return ret;
    }
    void dfs(TreeNode*root){
        if(!root)
            return;
        tmp=tmp * 10 + root->val;
        if(!root->left&&!root->right)
            ret += tmp;
        dfs(root->left);
        dfs(root->right);
        tmp /= 10;
    }
};
    ListNode* midNode(ListNode* head){
        //默认head!=nullptr
        ListNode *slow = head, *fast = head;
        while(fast->next&&fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.szie();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i=1;i<=n;++i){
            for(auto&w:wordDict){
                int len = w.length();
                if(i>=len&&w==s.substr(i-len,len)){
                    dp[i] = dp[i] || dp[i - len];
                }
            }
        }
        return dp[n];
    }
};
class Solution {
public:
    int KLargest(vector<int>&nums,int k){
        int pos = 0, l = 0, r = nums.size() - 1;
        while(1){
            pos=help(nums,l,r);
            if(pos==k-1){
                return nums[pos];
            }else if(pos<k-1){
                l = pos + 1;
            }else{
                r = pos - 1;
            }
        }
    }
    int help(vector<int>&nums,int l,int r){
        int base = nums[l];
        while(l<r){
            while(l<r&&nums[r]<=base){
                --r;
            }
            nums[l] = nums[r];
            while(l<r&&nums[l]>=base){
                ++l;
            }
            nums[r] = nums[l];
        }
        nums[l] = base;
        return l;
    }
};
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand(time(NULL));
        sort(nums, 0, nums.size() - 1);
        return nums;
    }
    void sort(vector<int>&nums,int l,int r){
        if(l>=r)
            return;
        int p = rand() % (r - l + 1)+l;
        swap(nums[l], nums[p]);

        int b = l, e = r,base = nums[b];
        while(b<e){
            while(b<e&&nums[e]>=base){
                e--;
            }
            nums[b] = nums[e];
            while(b<e&&nums[b]<=base){
                ++b;
            }
            nums[e] = nums[b];
        }
        nums[b] = base;
        sort(nums, l, b);
        sort(nums, b + 1, r);
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ret;
        deque<int> q;
        for (int i = 0; i < nums.size();++i){
            while(q.size()&&i-k+1>q.front()){
                q.pop_front();
            }

            while(q.size()&&nums[i]>nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            if(i-k+1>=0){
                ret.push_back(nums[i]);
            }
        }

        return ret;
    }
};
class Single{
public:
    static Single* GetInstance();
private:
    Single();
    Single(Single &instance);
    Single &operator=(Single &instance);
    ~Single();
};
Single* Single::GetInstance(){
    static Single instance;
    return &instance;
}
int main(){
    Single *instance = Single::GetInstance();
}

class LRUCache {
public:
    LRUCache(int capacity):m_c(capacity) {}
    
    int get(int key) {
        auto it = hash.find(key);
        if(it==hahs.end())return -1;
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = hash.find(key);
        if(it!=hash.end()){
            cache.splice(cache.begin(), cache, it->second);
            it->second->second = value;
        }else{
            cache.emplace(cache.begin(), make_pair(key, value));
            hash[k]=cache.begin();

            if(cache.size()>m_c){
                hash.erase(cache.back().first);
                cache.pop_back();
            }
        }
    }

private:
    int m_c;
    list<pair<int,int>>cache;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
};
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
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand(time(0));
        sort(vector<int> & nums, 0, nums.size()-1);
        return nums;
    }
    void sort(vector<int>&nums,int b,int e){
        if(b>=e)
            return;
        int pos = rand() % (b - e + 1) + b;
        swap(nums[pos], nums[b]);
        int l = b, r = e, base = nums[l];
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
        nums[l] = base;
        sort(nums, b, l);
        sort(nums, l + 1, e);
    }
};
void maopao(vector<int>&nums){
    int n = nums.size();
    for (int i = 0; i < n - 1;++i){//扫n-1趟，每趟产生一个最值
        for (int j = 0; j < n - 1 - i;++j){
            if(nums[j]>nums[j+1]){
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)
           return head;
        ListNode *cur = head, *prev = nullptr, *next = nullptr;
        while(cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
pair<ListNode*,ListNode*> reverse2(ListNode* head,ListNode* tail){
    ListNode *prev = tail->next, *cur = head, *next = nullptr;
    while(prev != tail){
        next = cur->next;
        cur->next=prev;
        prev = cur;
        cur = next;
    }
    return {tail, head};
}
ListNode* merge(ListNode*l1,ListNode*l2){
    if(!l1){
        return l2;
    }else if(!l2){
        return l1;
    }else if(l1->val<l2->val){
        l1->next = merge(l1->next, l2);
        return l1;
    }else{
        l2->next = merge(l1, l2->next);
        return l2;
    }
}
ListNode* retNNode(ListNode* head,int n){
    ListNode *dummy = new ListNode(0, head),*slow=dummy,*fast=head;
    while(n--){
        fast = fast->next;
    }
    while(fast){
        fast = fast->next;
        slow = slow->next;
    }
    return Nnode=slow->next;
}
ListNode* retNNode(ListNode* head,int n){
    ListNode *dummy = new ListNode(0, head), *slow = dummy, *fast = head;
    while(n--){
        fast = fast->next;
    }
    while(fast){
        fast=fast->next;
        slow = slow->next;
    }
    return slow->next;
}
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int &m:nums){
            if(m<=0){
                m = n + 1;
            }
        }

        for (int i = 0; i < n;++i){
            int m = abs(nums[i]);
            if(m<=n){
                nums[m - 1] = -abs(nums[m - 1]);
            }
        }
        for (int i = 0;i<n;++i){
            if(nums[i]>0)
                return i + 1;
        }

        return n + 1;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;

        for (int first = 0; first < n;++first){
            if(first>0&&nums[first]==nums[first-1])
                continue;
            int target = -nums[first];
            int third = n - 1;

            for (int second = first + 1; second < n;++second){
                if(second>first+1&&nums[second]==nums[second-1])continue;
                while(second<third&&nums[second]+nums[third]>target){
                    --third;
                }
                if(second==third)
                    break;//没找到第三个数
                if(nums[second]+nums[third]==target){
                    ret.emplace_back(vector<int>{nums[first], nums[second], nums[third]});
                }
            }
        }
        return ret;
    }
};
class Solution {
public:
    int myAtoi(string s) {
        char prev = '+';
        long tmp = 0;
        int i = 0, n = s.szie();
        while(i<n){
            if(isalpha(s[i])||s[i]=='.')
                return 0;
            while(i<n&&s[i]==' '){
                ++i;
            }

            if(i<n&&s[i]=='+'){
                if(i<n-1&&!isdigit(s[i+1]))
                    return 0;
                else{
                    ++i;
                    prev = '+';
                }
            }
            if(i<n&&s[i]=='-'){
                if(i<n-1&&!isdigit(s[i+1]))
                    return 0;
                else{
                    ++i;
                    prev = '-';
                }
            }

            //遍历数字
            if(i<n&&isdigit(s[i])){
                while(i<n&&isdigit(s[i])){
                    tmp = tmp * 10 + s[i] - '0';
                    tmp = (prev == '-') ? min(tmp, -(long long)INT_MIN) : min(tmp, (long long)INT_MAX);
                    ++i;
                }
                return (prev == '-') ? -tmp : tmp;
            }
        }
        return 0;
    }
}i;
class Solution {
public:
    string minWindow(string s, string t) {
        //字符串查找的问题，由于随机存取，
        //首先hash把参考字符串存一下
        vector<int> chars(128, 0);
        for(auto& c:t){
            ++chars[c];
        }

        //双指针滑动窗口扫描
        int count = 0,l=0,min_l=0,min_size=s.size()+1;
        for (int r = 0; r < s.size(); ++r){
            if(--chars[s[r]]>=0){
                ++count;
            }

            //if目前滑动窗口中已经包含t中所有
            //尝试移动l右移
            while(count==t.size()){
                if(r-l+1<min_size){
                    //记录
                    min_l = l;//用于最后取子串的起始位置
                    min_size = r - l + 1;//用于最后取子串的大小
                }
                //看移动l导致的count情况
                if(++chars[s[l]]>0){
                    --count;
                }
                ++l;
            }
        }
        return min_size > s.size() ? "" : s.substr(min_l, min_size);
    }
};
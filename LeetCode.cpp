  【数组】

283. 移动零					//练习：27. 26. 80
	【双指针】快慢指针
class Solution {
public:
    void moveZeroes(vector<int>& nums) {    //双指针  //O(n)  //O(1)
        int lastNonZeroNum = 0;
        
        for(int i = 0; i < nums.size(); i++){   // !0和0交换位置
            if(nums[i] != 0){
                if(i != lastNonZeroNum)
                    swap(nums[lastNonZeroNum++], nums[i]);
                else
                    lastNonZeroNum++;
            }
        }    
    }
};


75. 颜色分类		//练习：88.215
	【计数排序：适用于元素比较有限的排序】
class Solution {  //O(n),O(1)
public:
    void sortColors(vector<int>& nums) {  //计数排序 
        int count[3] = {0};
        for(int i = 0; i <nums.size(); i ++){
            assert(nums[i] >= 0 && nums[i] <= 2);
            count[nums[i]] ++;
        }

        int index = 0;
        for(int j = 0; j <= 2; j ++)
            for(int i = 0; i < count[j]; i++)
                nums[index++] = j;

    }
};
	【三路快排】遍历一遍
class Solution {  //O(n),O(1)
public:
    void sortColors(vector<int>& nums) {  //三路快排
        int zero = -1;  //num[0, zero] == 0
        int two = nums.size();  //num[two, n-1] == 2

        for(int i = 0; i < two; ){
            if(nums[i] == 1){ 
                i++;
            }
            else if(nums[i] == 2){
                two --;
                swap(nums[i], nums[two]);
            }
            else{
                assert(nums[i] == 0);   //num[i] == 0
                zero++;
                swap(nums[i], nums[zero]);
                i++;
            }
        }

    }
};


167. 两数之和 II - 输入有序数组		
	【二分搜索】//O(nlogn) O(1)
	【双指针：对撞指针】	//练习：125 344 345 11
class Solution {	//O(n) O(1)
public:
    vector<int> twoSum(vector<int>& numbers, int target) {  //对撞指针
        int l = 0, r = numbers.size() - 1; //[]
        while(l < r){
            if(numbers[l] + numbers[r] == target){
                int res[] = {l + 1, r + 1};
                return vector<int> (res, res + 2);
            }
            else if(numbers[l] + numbers[r] < target)
                l ++;
            else 
                r --;
        }
        throw invalid_argument("no solution.");
    }
};


209. 长度最小的子数组
	【窗口滑动】
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {  //滑动窗口  //O(n) O(1)
        int l = 0, r = -1; //窗口[l,r]
        int sum = 0;
        int res = nums.size()  + 1;

        while(l < nums.size()){
            if( r + 1 < nums.size() && sum < s){
                r++;
                sum += nums[r];
            }
            else{
                sum -=nums[l];
                l++;
            }

            if(sum >= s){
                res = min(res , r - l + 1);
            }
        }
        if(res == nums.size() + 1)   return 0;
        return res;
    }
};


3. 无重复字符的最长子串				//练习：438. 76
	【窗口滑动】
class Solution {
public:
    int lengthOfLongestSubstring(string s) {    //窗口滑动
        int freq[256] = {0};
        int l = 0, r = -1;  //窗口 [l,r]
        int res = 0;

        while(l < s.size()){

            if(r + 1 < s.size() && freq[s[r + 1]] == 0 ){  //右边界滑动
                r++;
                freq[s[r]] ++;
            }
            else{   //左窗口滑动
                freq[s[l]] --;
                l++;
            }

            res = max(res, r - l + 1);
            
        }
        return res;
    }
};


【查找问题】
	查找有无：set	[平衡搜索树：O(logn)]
	查找对应关系：map	[平衡搜索树：O(logn)]
	
349. 两个数组的交集 242 202 290 205 451
	【set容器】
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {  //set容器
        set<int> record(nums1.begin(),nums1.end());

        set<int> setResult;
        for(int i = 0; i < nums2.size(); i ++){
            if(record.find(nums2[i]) != record.end()){
                setResult.insert(nums2[i]);
            }
        }
        return vector<int> (setResult.begin(), setResult.end());

    }
};


350. 两个数组的交集 II

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {        //map容器
        map <int, int> record;

        for(int i = 0; i < nums1.size(); i ++){     //存入record
            record[nums1[i]] ++;
        }

        vector<int> resultVector;
        for(int i = 0; i < nums2.size(); i ++){     //查找
            if(record[nums2[i]] > 0){
                resultVector.push_back(nums2[i]);
                record[nums2[i]] --;
            }
        }
        return resultVector;
    }
};


1. 两数之和		15	18
	【unordered_map哈希表】
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) { //哈希表map (O(n))
        unordered_map<int , int> record;
        for(int i = 0; i < nums.size(); i ++){
            int complement = target - nums[i];
            if(record.find(complement) != record.end()){
                int res[2] = {record[complement], i };
                return vector<int> {res, res + 2};
            }
            record[nums[i]] = i;
        }
        throw invalid_argument("no solution!");
    }
};


454. 四数相加 II	49	
	【unordered_map哈希表】
class Solution {    //O(n^2)
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {  //哈希表
        assert(A.size() == B.size() && B.size() == C.size() && C.size() == D.size());

        unordered_map<int, int> record;     //查找表
        for(int i = 0; i  < C.size(); i ++)
            for(int j = 0; j < D.size(); j ++)
                record[C[i] + D[j]] ++;
        
        int res = 0;
        for(int i = 0; i < A.size(); i ++)
            for(int j = 0; j < B.size(); j ++){
                if(record.find(0 - A[i] - B[j]) != record.end()){
                    res += record[0 - A[i] - B[j]];
                }
            }
        return res;
    }
};


447. 回旋镖的数量	149

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {   //哈希表
        int res = 0;
        for(int i = 0; i < points.size(); i ++){
            unordered_map<int , int> record;
            for(int j = 0; j < points.size(); j ++)
                if(j != i )
                    record[dis(points[i], points[j])] ++;
            
            for(auto iter = record.begin(); iter != record.end(); iter ++){
                res += (iter->second) * (iter->second -1);
            }
        }
        return res;
    }
private:
    int dis(vector<int> & pa, vector<int> & pb){
        return (pa[0] - pb[0]) * (pa[0] - pb[0]) + (pa[1] - pb[1]) * (pa[1] - pb[1]);
    }
};   

219. 存在重复元素 II	217	220
【滑动窗口+表查找】
class Solution {    //O(n)    O(k)
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {    //滑动窗口 + 哈希表
        unordered_set<int> record;
        for(int i = 0; i < nums.size(); i ++){
            
            if(record.find(nums[i]) != record.end()){
                return true;
            }

            record.insert(nums[i]);

            //保持record中最多有k个元素
            if(record.size() == k + 1 ){
                record.erase(nums[i - k]);
            }
        }
        return false;
    }
};


【指针】


206. 反转链表	92	86	328	2	445
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {     //反向改变指针
        ListNode* prev = NULL;
        ListNode* cur = head;   //用于遍历
        while(cur != NULL){
            ListNode* next = cur->next;

            cur->next = prev;
            prev = cur;
            cur = next;
        }
    return prev;
    }
};

【设置哑结点】
203. 移除链表元素	82	21
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) { //哑结点遍历
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode* cur = dummyHead;
        while(cur->next != NULL){

            if(cur->next->val == val){
                ListNode* delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
            }
            else
                cur = cur->next;
        }
        ListNode* retNode = dummyHead->next;
        delete dummyHead;

        return retNode;
    }
};


24. 两两交换链表中的节点	25	147	148
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);  //哑结点
        dummyHead->next = head;

        ListNode* p = dummyHead;
        while(p->next && p->next->next){
            ListNode* Node1 = p->next;
            ListNode* Node2 = Node1->next;
            ListNode* Next = Node2->next;

            Node2->next = Node1;
            Node1->next = Next;
            p->next = Node2;

            p = Node1;
        }

        ListNode* resNode = dummyHead->next;
        delete dummyHead;
        return resNode;
    }
};

237. 删除链表中的节点
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {   //迭代，改变值
        if(node == NULL)
            return ;
        
        if(node->next == NULL){
            delete node;
            node = NULL;
            return ;
        }
        node->val=node->next->val;
        ListNode* del = node->next;
        node->next=node->next->next;

        delete del;
        return;
        
    }
};

【链表与双指针】
19. 删除链表的倒数第N个节点		61	143	234
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) { //快慢指针
        ListNode* dummy=new ListNode(-1);   //哑结点
        dummy->next=head;
        ListNode* first=dummy;
        ListNode* second=dummy;
        
        for(int i=1;i<=n+1;i++){
            first=first->next;
        }

        while(first!=NULL){
            first=first->next;
            second=second->next;
        }

        ListNode* delNode = second->next;
        second->next = delNode->next;
        delete delNode;

        ListNode* resNode = dummy->next;
        delete dummy;

        return resNode;
    }
};


【栈和队列】

20. 有效的括号	150	71
class Solution {
public:
    bool isValid(string s) {    //栈
        if(s.empty())   return true;
        map<char,char> mStr=    //定义map存放括号
        {
            {')','('},
            {']','['},
            {'}','{'} 
        };

        stack<char> myStack;    //定义栈

        if(s.size()%2 != 0)     //如果不是偶数一定不匹配
            return false;

        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')     //如果是左括号，入栈
                myStack.push(s[i]);
            else if(s[i]==')' || s[i]==']' || s[i]=='}')
            {
                if(myStack.empty())     //第一个符号是右括号，一定不匹配
                    return false;
                else if(mStr[s[i]]==myStack.top())      //如果匹配，弹出栈
                {
                    myStack.pop();
                }
                else
                    return false;       //其他情况的处理，例如：{[}]
            }
        }
        if(!myStack.empty())    //栈中还有数据，不匹配
            return false;
    
        return true;
    }
};

【二叉树的前序遍历：144；中序：94；后序：145】	341
144. 二叉树的前序遍历
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*系统栈*/
struct Command{
    string s;   //go;   print
    TreeNode* node;
    Command(string s, TreeNode* node) : s(s), node(node) { }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {     //系统栈实现
        vector<int> res;

        if(root == NULL)
            return res;

        stack<Command> stack;
        stack.push(Command("go", root));
        while(!stack.empty()){

            Command command = stack.top();
            stack.pop();

            if(command.s == "print")
                res.push_back(command.node->val);
            else{
                assert(command.s =="go");
                if(command.node -> right)
                    stack.push(Command("go", command.node -> right));
                if(command.node -> left)
                    stack.push(Command("go", command.node -> left));
                stack.push(Command("print",command.node));
            }
        }

        return res;
    }
};

94. 二叉树的中序遍历
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*模拟系统栈*/
struct Command{
    string s;   //go;   print
    TreeNode* node;
    Command(string s, TreeNode* node) : s(s), node(node) { }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {  //模拟系统栈实现
         vector<int> res;

        if(root == NULL)
            return res;

        stack<Command> stack;
        stack.push(Command("go", root));
        while(!stack.empty()){

            Command command = stack.top();
            stack.pop();

            if(command.s == "print")
                res.push_back(command.node->val);
            else{
                assert(command.s =="go");
                if(command.node -> right)
                    stack.push(Command("go", command.node -> right));

                stack.push(Command("print",command.node));

                if(command.node -> left)
                    stack.push(Command("go", command.node -> left));
                
            }
        }

        return res;       
    }
};

145. 二叉树的后序遍历
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*模拟系统栈*/
struct Command{
    string s;   //go;   print
    TreeNode* node;
    Command(string s, TreeNode* node) : s(s), node(node) { }
};
 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {    //模拟系统栈实现
         vector<int> res;

        if(root == NULL)
            return res;

        stack<Command> stack;
        stack.push(Command("go", root));
        while(!stack.empty()){

            Command command = stack.top();
            stack.pop();

            if(command.s == "print")
                res.push_back(command.node->val);
            else{
                assert(command.s =="go");
                stack.push(Command("print",command.node));

                if(command.node -> right)
                    stack.push(Command("go", command.node -> right));

                if(command.node -> left)
                    stack.push(Command("go", command.node -> left));
                
            }
        }

        return res;       
    }
};

【队列】
队列的基本应用-广度优先遍历
树：层序遍历
图：无权图的最短路径

102. 二叉树的层序遍历	107	103	199
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {    //队列
        vector<vector<int>> res;
        if(root == NULL)    return res;

        queue< pair<TreeNode*, int> > q;    
        q.push( make_pair(root, 0));

        while( !q.empty()){

            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            if(level == res.size())
                res.push_back( vector<int> ());

            res[level].push_back(node->val);

            if(node->left)
                q.push(make_pair(node->left, level + 1));

            if(node->right)
                q.push(make_pair(node->right, level + 1));
        }

        return res;
    }
};

【使用队列求无权图的的最短路径】
279. 完全平方数		127	126
class Solution {
public:
    int numSquares(int n) { //图的BFS

        assert( n > 0);

        queue< pair<int, int> > q;
        q.push( make_pair(n, 0));

        vector<bool> visited (n + 1, false);
        visited[n] = true;

        while(!q.empty()){
            int num = q.front().first;
            int step =  q.front().second;
            q.pop();

            for(int i = 1; ; i ++){
                int a = num - i * i;
                if(a < 0)
                    break;
                if(a == 0)
                    return step + 1;
                if(! visited[a]){
                    q.push(make_pair(a, step + 1));
                    visited[a] = true;
                }
            }          
        }
        throw invalid_argument("No Solution!");
    }
};

【优先队列】priority_queue<>
priority_queue<int> pq;	//最大堆
priority_queue<int,vector<int>, greater<int>> pq2;	//最小堆
priority_queue<int, vector<int>, function< bool(int,int)> > pq3(MyCom)	//自定义

347. 前 K 个高频元素	23
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        assert(k > 0);

        //统计每个元素出现的频率
        unordered_map<int, int> freq;   //(元素，频率)
        for(int i = 0; i < nums.size(); i ++){
            freq[nums[i]] ++;
        }

        assert(k <= nums.size());

        //扫描freq，维护当前出现频率最高的k个元素
        //优先队列中，按频率排序，数据对的格式是(频率，元素)	最小堆
        priority_queue< pair<int,int> ,vector<pair<int, int>>, greater<pair<int, int>> > pq;
        for(auto iter = freq.begin(); iter != freq.end(); iter ++){
            
            if(pq.size() == k){
                if(iter->second > pq.top().first){
                    pq.pop();
                    pq.push( make_pair( iter -> second, iter -> first));
                }
            }
            else
                pq.push( make_pair( iter -> second, iter -> first));
        }

        vector<int> res;
        while(! pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }   
};


【二叉树和递归】
104. 二叉树的最大深度	111
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {      //递归
        if(root == NULL)
            return 0;
        
        return max(maxDepth(root->left),maxDepth(root->right)) + 1;
    }

};

226. 翻转二叉树		100	101	222	110
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        
        invertTree(root -> left);
        invertTree(root -> right);
        swap(root->left, root->right);

        return root;
    }
};

【平衡二叉树：每一个节点的左右子树差不超过1】

【注意递归终止条件】
112. 路径总和	404		111
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) //空节点
            return false;

        if(root->left == nullptr && root->right == nullptr) //优化根节点等于sum的情况
            return root->val == sum;

        if(hasPathSum(root->left, sum - root->val))
            return true;
        if(hasPathSum(root->right, sum - root->val))
            return true;

        return false;
    }
};

257. 二叉树的所有路径	113	129
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;

        if(root == nullptr)     return res;

        if(root->left == nullptr && root->right == nullptr){    //终止条件，没有叶子节点
            res.push_back(to_string(root->val));
            return res;
        }

        vector<string> leftS = binaryTreePaths(root->left);     //遍历左子树
        for(int i = 0; i < leftS.size(); i ++){
            res.push_back(to_string(root->val) + "->" + leftS[i]);
        }
        vector<string> rigthS = binaryTreePaths(root->right);   //遍历右子树
        for(int i = 0; i < rigthS.size(); i ++){
            res.push_back(to_string(root->val) + "->" + rigthS[i]);
        }

        return res;
    }
};

【更复杂的递归】
437. 路径总和 III
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	//在以root为根节点的二叉树中，寻找和为sum的路径，返回这样的路径个数
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr)     //根节点为空
            return 0;
        
        int res = findPath(root, sum);  //寻找包含root的和为sum的路径
        res += pathSum(root->left, sum);    //寻找不包含root的左子树中和为sum的路径个数
        res += pathSum(root->right, sum);   //寻找不包含root的右子树中和为sum的路径个数

        return res;
    }

private:
	//在以root为根节点的二叉树中，寻找包含root的路径，使和为sum 
	//返回这样的路径个数
    int findPath(TreeNode* root, int sum){
        if(root == nullptr)
            return 0;

        int res = 0;
        if(root->val == sum)
            res += 1;
        
        res += findPath(root->left, sum - root->val);   //左子树
        res += findPath(root->right, sum - root->val);

        return res;
    }
};

【二分搜索树】
基本操作：
	查找	插入	删除
	
235. 二叉搜索树的最近公共祖先	98	450	108*	230	236
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 **/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {  //递归

        assert(p != nullptr && q != nullptr);

        if(root == nullptr)
            return nullptr;
        
        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);

        if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);

        return root; 
        
    }
};

【递归和回溯】
17. 电话号码的字母组合		93	131
class Solution {

private:
    const string letterMap[10] = {
        " ",    //0
        "",     //1
        "abc",  //2
        "def",  //3
        "ghi",  //4
        "jkl",  //5
        "mno",  //6
        "pqrs", //7
        "tuv",  //8
        "wxyz"  //9
    };

    vector<string> res;

    //s中保存此时digits[0···index-1]翻译得到的字母字符串
    //寻找和digits[index]匹配的字母，获得digit[0,index]得到的解
    void findCombination(const string &digits, int index, const string &s){

        cout<< index << " : "<< s <<endl;

        if(index == digits.size()){
            //保存s
            res.push_back(s);
            cout <<"get " << s << ", return" <<endl;
            return ;
        }

        char c = digits[index];
        assert(c >= '0' && c <= '9' && c != '1');
        string letters = letterMap[c - '0'];
        for(int i = 0; i < letters.size(); i++){
            cout<< "digits[" << index << "] = " << c << ", use " <<letters[i] <<endl;
            findCombination(digits, index + 1, s + letters[i]);
        }

        cout << "digits[" << index <<"] = " << c <<" complete, return" <<endl;
        cout << endl;
        return ;
    }

public:
    vector<string> letterCombinations(string digits) {
        
        res.clear();
        if(digits == "")
            return res;

        findCombination(digits, 0, "");

        return res;
    }
};

【回溯法排列问题】
46. 全排列	47
class Solution {    //回溯法
private:
    vector<vector<int>> res;

    //p中保存了一个有index个元素的排列
    //向这个排列的末尾添加第index+1个元素，获得一个有index + 1个元素的全排列
    void generatePermutation(const vector<int> nums, int index, vector<int>& p){

        if(index == nums.size()){
            res.push_back(p);
            return ;
        }

        for(int i = 0; i < nums.size(); i ++){
            if(find(p.begin(), p.end(), nums[i]) == p.end()){
                p.push_back(nums[i]);
                generatePermutation(nums,index + 1, p);
                p.pop_back();
            }
        }
        return ;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        res.clear();
        if(nums.size() == 0)
            return res;
        
        vector<int> p;
        generatePermutation(nums, 0, p);

        return res;
    }
};

77. 组合		39		40		216  78		90	401
class Solution {    //回溯算法
private:
    vector<vector<int>> res;
    //int i = 1;
	//求解C(n,k)，当前已经找到的组合存储在c中，需要从start开始搜索新的元素
    void generateCombinations(int n, int k, int start, vector<int> &c){

        //cout<<"调用第 " << i ++ <<"次函数, start = "<<start<<"." <<endl;

        if(c.size() == k){
            res.push_back(c);
            return ;
        }

        for(int i = start; i <= n; i ++){
          c.push_back(i);
          generateCombinations(n, k, i + 1, c);
          c.pop_back();  
        }

        return ;
    }
public:
    vector<vector<int>> combine(int n, int k) { 

        res.clear();
        vector<int> c;
        generateCombinations(n, k, 1, c);
        
        return res;
    }
};

【回溯法的剪枝】
class Solution {    //回溯算法
private:
    vector<vector<int>> res;
    int i = 1;
	//求解C(n,k)，当前已经找到的组合存储在c中，需要从start开始搜索新的元素
    void generateCombinations(int n, int k, int start, vector<int> &c){

        //cout<<"调用第 " << i ++ <<"次函数, start = "<<start<<"." <<endl;

        if(c.size() == k){
            res.push_back(c);
            return ;
        }

        //剪枝
        //还有k - c.size() 个空位，所以[i，n]至少还要有k - c.size() 个元素
        //i最多为 n - (k - c.size()) + 1
		//[i,n]的长度：n - i + 1 = k - c.size()
        for(int i = start; i <= n - (k - c.size()) + 1; i ++){
          c.push_back(i);
          generateCombinations(n, k, i + 1, c);
          c.pop_back();  
        }

        return ;
    }
public:
    vector<vector<int>> combine(int n, int k) { 

        res.clear();
        vector<int> c;
        generateCombinations(n, k, 1, c);
        
        return res;
    }
};


【二维平面内的回溯算法】
79. 单词搜索	⭐⭐⭐⭐⭐
class Solution {    //回溯

private:
    int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int m, n;
    vector<vector<bool>> visited;

    bool inArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    
    //从board[startx, starty]开始寻找，寻找word[index,word.size())
    bool searchWord(const vector<vector<char>> &board, const string &word, int index, int startx, int starty){
        
        if(index == word.size() - 1)  
            return board[startx][starty] == word[index];

        if(board[startx][starty] == word[index]){
            visited[startx][starty] = true; 
            //从startx, starty出发，向四个方向寻找
            for(int i = 0; i < 4; i ++){
                int newx = startx + d[i][0];
                int newy = starty + d[i][1];
                if(inArea(newx, newy) && ! visited[newx][newy])
                    if(searchWord(board, word, index + 1, newx, newy))
                        return true;
            }
            visited[startx][starty] = false;	//回溯，放弃这个位置
        }  

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();           
        assert(m > 0);
        n = board[0].size();                    

        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for(int i = 0; i < board.size(); i ++)
            for(int j = 0; j < board[i].size(); j ++)
                if(searchWord(board, word, 0, i, j))
                    return true;

        return false;
    }
};

【floodfill算法】深度优先遍历	130	417
200. 岛屿数量
class Solution { //floodfill算法
private:
    int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};   //位置数组
    int m, n;
    vector<vector<bool>> visited;

    bool inArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    //从grid[x][y]的位置开始，进行floodfill
    void dfs(const vector<vector<char>>& grid, int x, int y){

            visited[x][y] = true;

            for(int i = 0; i < 4; i ++){
                int newx = x + d[i][0];
                int newy = y + d[i][1];
                if(inArea(newx,newy) && !visited[newx][newy] && grid[newx][newy] == '1')
                    dfs(grid, newx, newy);
            }

            return ;
    }
public:
    int numIslands(vector<vector<char>>& grid) {

        m = grid.size();           
        if(m == 0)
            return 0;
        n = grid[0].size();                    

        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        int res = 0;
        for(int i = 0; i < grid.size(); i ++)
            for(int j = 0; j < grid[i].size(); j ++)
                if(grid[i][j] == '1' && !visited[i][j]){
                    res ++;
                    dfs(grid, i, j);
                }
        
        return res;
    }
};

【回溯法是经典的人工智能的基础】
51. N皇后	52	37
class Solution {    //递归回溯
private:
    vector<vector<string>> res;
    vector<bool> col, dia1, dia2;

    //尝试在一个n皇后问题中，摆放第index行的皇后位置
    void putQueen(int n, int index, vector<int> &row){

        if(index == n){
            res.push_back(generateBoard(n, row));
            return ;
        }

        for(int i = 0; i < n; i ++){
            //尝试将第index行的皇后摆放在第i列
            if(!col[i] && !dia1[index + i] && !dia2[index - i + n - 1]){
                row.push_back(i);
                col[i] = true;
                dia1[index + i] = true;
                dia2[index - i + n - 1] = true;
                putQueen(n, index + 1, row);
                col[i] = false;
                dia1[index + i] = false;
                dia2[index - i + n - 1] = false;
                row.pop_back();
            }
        }
        return ;
    }

    vector<string> generateBoard(int n, vector<int> &row){
        assert(row.size() == n);
        vector<string> board(n, string(n, '.'));
        for(int i = 0; i < n; i ++)
            board[i][row[i]] = 'Q';
        return board;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        
        res.clear();

        col = vector<bool>(n, false);   //列标志位
        dia1 = vector<bool>(2 * n - 1, false);  //“/” 对角线
        dia2 = vector<bool>(2 * n - 1, false);  //“\” 对角线

        vector<int> row;
        putQueen(n ,0, row);

        return res;
    }
};


【动态规划】

斐波那契数列
记忆化搜索
vector<int> memo = -1;
int fib(int n ){
	
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	
	if(memo[n] == -1)
		memo[n] = fib(n-1) + fib(n - 2);
	
	return memo[n];
}

70. 爬楼梯	120
class Solution {    //递归   记忆化搜索 

private:
    vector<int> memo;
    int calcWays(int n){

        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        
        if(memo[n] == -1) 
            memo[n] = calcWays(n - 1) + calcWays(n - 2);

        return memo[n];
    }

public:
    int climbStairs(int n) {

        memo = vector<int>(n + 1, -1);
        return calcWays(n);
    }
};

class Solution {    //动态规划
public:
    int climbStairs(int n) {
        vector<int> memo(n + 1, -1);
        memo[0] = 1;
        memo[1] = 1;

        for(int i = 2; i <= n; i ++){
            memo[i] = memo[i - 1] + memo[i - 2];
        }

        return memo[n];
    }
};

343. 整数拆分	279	91	62	63	
class Solution {    //记忆化搜索

private:
    vector<int> memo;

    int max3(int a, int b, int c){
        return max(a, max(b, c));
    }
    //将n进行分割（至少分割两部分）,可以获得的最大乘积
    int breakInteger(int n){

        if(n == 1)
            return 1;
        
        if(memo[n] != -1)
            return memo[n];

        int res = -1;
        for(int i = 1; i <= n - 1; i ++){
			//i + (n - i)
            res = max3(res, i * (n - i), i * breakInteger(n - i));
        }
        memo[n] = res;
        return res;
    }
public:
    int integerBreak(int n) {

        memo = vector<int>(n + 1, -1);
        return breakInteger(n);

    }
};


class Solution {    //动态规划

private:

    int max3(int a, int b, int c){
        return max(a, max(b, c));
    }

public:
    int integerBreak(int n) {

        //memo[i]表示将数字i分割(至少分割2次)后得到的最大乘积
        vector<int> memo = vector<int>(n + 1, -1);

        memo[1] = 1;
        for(int i = 2; i <= n; i ++)
            //求解memo【i】
            for(int j = 1; j <= i -1; j ++)
                //j + (i - j)
                memo[i] = max3(memo[i], j * memo[i - j], j * (i - j));

        return memo[n];

    }
};


198. 打家劫舍	213	337	309
class Solution {    //记忆化搜索
private:
    //memo[i]表示考虑[i,n)房子的最大收益
    vector<int> memo;
    //考虑抢劫从[index,nums.size())的房子
    int tryRob(vector<int> &nums, int index){

        if(index >= nums.size())
            return 0;
        if(memo[index] != -1)
            return memo[index];

        int res = 0;
        for(int i = index; i < nums.size(); i++)
            res = max(res, nums[i] + tryRob(nums, i + 2));
        memo[index] = res;
        
        return res;
    }
public:
    int rob(vector<int>& nums) {    //
        memo = vector<int>(nums.size(), -1);
        return tryRob(nums, 0); 
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        vector<int> dp = vector<int>(size, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[size - 1];
    }
};

【0-1背包问题 】

class Solution{		//动态规划 O(n*C)  O(n*C)
public:
	int knapsack01(const vector<int> &w, const vector<int> & v, int C){
		assert(w.size() == v.size() && C >= 0);
		int n = w.size();
		if(n == 0 || C == 0)
			return 0;
		
		vector<vector<int>> memo(n,vector<int>(C + 1, -1));
		
		for(int j = 0; j <= C; j ++)
			memo[0][j] = (j >= w[0]) ? v[0] : 0);
		
		for(int i = 1; i < n; i ++){
			for(int j = 0; j <= C; j ++){
				memo[i][j] = memo[i - 1][j];
				if(j >= w[i])
					memo[i][j] = max(memo[i][j], v[i] + memo[i - 1][j - w[i]]);
			}
		}
		return memo[n - 1][C];
	}
};


class Solution{		//动态规划  时间：O(n*C)   空间：O(2*C)
public:
	int knapsack01(const vector<int> &w, const vector<int> & v, int C){
		assert(w.size() == v.size() && C >= 0);
		int n = w.size();
		if(n == 0 || C == 0)
			return 0;
		
		vector<vector<int>> memo(2,vector<int>(C + 1, -1));
		
		for(int j = 0; j <= C; j ++)
			memo[0][j] = (j >= w[0]) ? v[0] : 0);
		
		for(int i = 1; i < n; i ++){
			for(int j = 0; j <= C; j ++){
				memo[i % 2][j] = memo[(i - 1) % 2][j];
				if(j >= w[i])
					memo[i % 2][j] = max(memo[i % 2][j], v[i] + memo[(i - 1) % 2][j - w[i]]);
			}
		}
		return memo[(n - 1) % 2][C];
	}
};


class Solution{		//动态规划  时间：O(n*C)   空间：O(C)
public:
	int knapsack01(const vector<int> &w, const vector<int> & v, int C){
		assert(w.size() == v.size() && C >= 0);
		int n = w.size();
		if(n == 0 || C == 0)
			return 0;
		
		vector<int> memo(C + 1, -1);
		
		for(int j = 0; j <= C; j ++)
			memo[j] = (j >= w[0]) ? v[0] : 0);
		
		for(int i = 1; i < n; i ++){
			for(int j = C; j >= w[i]; j --){
				memo[j] = max(memo[j], v[i] + memo[j - w[i]]);
			}
		}
		return memo[C];
	}
};


416. 分割等和子集	322	377	474	139	494
class Solution {    //记忆化搜索
private:
    //memo[i][c]表示使用索引位[0,i]的这些元素，是否可以完全填充一个容量位c的背包
    // -1 ：未计算；0：不可以填充；1：可以填充
    vector<vector<int>> memo;

    //使用sum[0,index]，是否可以完全填充一个容量为sum的背包
    bool tryPartition(vector<int> &nums, int index, int sum){
        if(sum == 0)
            return true;
        
        if(sum < 0 || index < 0)
            return false;

        if(memo[index][sum] != -1)
            return memo[index][sum] == 1;

        memo[index][sum] = ( tryPartition(nums, index - 1, sum) ||
                tryPartition(nums, index - 1, sum - nums[index] ) ) ? 1 : 0;

        return memo[index][sum] == 1;  
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i ++){
            assert(nums[i] > 0);
            sum += nums[i];
        }

        if(sum % 2 != 0)    
            return false;
        
        memo = vector<vector<int>>(nums.size(), vector<int>(sum / 2 + 1, -1));
        return tryPartition(nums, nums.size() - 1, sum / 2);
    }
};

class Solution {    //动态规划
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i ++){
            assert(nums[i] > 0);
            sum += nums[i];
        }

        if(sum % 2 != 0)    
            return false;
        
        int n = nums.size();
        int C = sum / 2;
        vector<bool> memo(C + 1, false);

        for(int i = 0; i <= C; i ++)
            memo[i] = (nums[0] == i);
        
        for(int i = 1; i < n ; i ++)
            for(int j = C; j >= nums[i]; j --)
                memo[j] = memo[j] || memo[j - nums[i]];

        return memo[C];
    }
};

300. 最长上升子序列	376
class Solution {    //动态规划  O(n^2)
public:
    int lengthOfLIS(vector<int>& nums) 
	{

        if(nums.size() == 0)
            return 0;

        //dp[i]表示以nums[i]为结尾的最长上升子序列的长度
        vector<int> dp(nums.size(), 1);
        for(int i = 0; i < nums.size(); i ++)
            for(int j = 0; j < i; j ++)
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i] , 1 + dp[j]);

        int res = 1;
        for(int i = 0; i < dp.size(); i ++)
            res = max(res, dp[i]);

        return res;
    }
};


【贪心算法】
455. 分发饼干	392
class Solution {    //O(nlogn)
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());

        int si = 0, gi = 0;
        int res = 0;
        while(si < s.size() && gi < g.size() ){
            if(g[gi] <= s[si]){
                res ++;
                gi ++;
                si ++;
            }
            else
                gi ++;
        }

        return res;
    }
};


【贪心算法和动态规划】
435. 无重叠区间
bool compare(const vector<int> &a, const vector<int> &b){

    assert(a.size() == 2 && b.size() == 2);

    if(a[0] != b[0])
        return a[0] < b[0];
    return a[1] < b[1];
}

class Solution {	 //O(n^2)
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)
            return 0;
        
        sort(intervals.begin(), intervals.end(), compare);  //排序

        //memo[i]表示使用interval[0,i]的区间能构成的最长不重叠区间序列
        vector<int> memo(intervals.size(), 1);
        for(int i = 1; i < intervals.size(); i ++)
            for(int j = 0; j < i; j ++)     //memo[i]
                if(intervals[j][1] <= intervals[i][0])
                    memo[i] = max(memo[i], 1 + memo[j]);

        int res = 0;
        for(int i = 0; i < memo.size(); i++)
            res = max(res, memo[i]);

        return intervals.size() - res;
    }
};

//贪心算法
bool compare(const vector<int> &a, const vector<int> &b){   

    assert(a.size() == 2 && b.size() == 2);

    if(a[1] != b[1])
        return a[1] < b[1];
    return a[0] < b[0];
}

//按照区间的结尾排序
//每次选择结尾最早的，且和前一个区间不重叠的区间
class Solution {        //贪心算法
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)
            return 0;
        
        sort(intervals.begin(), intervals.end(), compare);  //排序

        int res = 1;
        int pre = 0;
        for(int i = 1; i < intervals.size(); i ++)
            if(intervals[i][0] >= intervals[pre][1]){

                res ++;
                pre = i;
            }
        
        return intervals.size() - res;

    }
};



/*******************快速排序 排序规则 *******************

排序思想：分治法+挖坑填数
分治法：大问题分解成各个小问题，对小问题求解，使
得小问题得以解决。

*******************************************************/

//快速排序(从小到大)
void quickSort(int s[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r;
		// 拿出第一个元素, 保存到x中,第一个位置成为一个坑
		int x = s[l];
		while (i < j)
		{
			// 从右向左找小于x的数
			while (i < j && s[j] >= x)
			{
				//左移, 直到遇到小于等于x的数
				j--;
			}
			if (i < j)
			{
				//将右侧找到的小于x的元素放入左侧坑中, 右侧出现一个坑
				//左侧元素索引后移
				s[i++] = s[j];
			}

			// 从左向右找大于等于x的数
			while (i < j && s[i] < x)
			{
				//右移, 直到遇到大于x的数
				i++;
			}
			if (i < j)
			{
				//将左侧找到的元素放入右侧坑中, 左侧出现一个坑
				//右侧元素索引向前移动
				s[j--] = s[i];
			}
		}
		//此时 i=j,将保存在x中的数填入坑中
		s[i] = x;
		quickSort(s, l, i - 1); // 递归调用 
		quickSort(s, i + 1, r);
	}
}


[*]二叉树的深度优先遍历--深度优先遍历（栈，先压右节点，再压左节点）

void DepthFirstTravel(Tree *root)
{
    stack<Tree *> s;
    s.push(root);
    while(!s.empty())
    {
        root = s.top();
        cout << root->data << " ";
        s.pop();
        if(root->rchild != NULL)
        {
            s.push(root->rchild);
        }
        if(root->lchild != NULL)
        {
            s.push(root->lchild);
        }
    }
}

[*]二叉树的深度优先遍历--广度优先遍历二叉树（队列：先压左节点，再压右节点）
void BreadthFirstTravel(Tree *root)
{
    queue<Tree *> q;
    q.push(root);
    while(!q.empty())
    {
        root = q.front();
        cout << root->data << " ";
        q.pop();
        if(root->lchild != NULL)
        {
            q.push(root->lchild);
        }
        if(root->rchild != NULL)
        {
            q.push(root->rchild);
        }
    }
}
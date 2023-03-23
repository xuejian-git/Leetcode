#include "solution.h"

using namespace std;

class Solution {
public:
    // 1
    int splitNum(int num) {
        vector<int> vec;
        while(num != 0) {
            int temp = num % 10;
            vec.push_back(temp);
            num /= 10;
        }
        sort(vec.begin(), vec.end());
        int n = 0, m = 0;
        for (int i = 0; i < vec.size(); ++i) {
            if (i % 2) {
                n = n * 10 + vec[i];
            } else {
                m = m * 10 + vec[i];
            }
        }
        return n + m;
    }

    // 2
    long long coloredCells(int n) {
        long long ans = 0;
        vector<long long> nums(n + 1 , 0);
        int a = 1;
        nums[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            a += 2;
            nums[i] = nums[i - 1] + 2 * a - 2;
        }
        for (auto n : nums) {
            cout << n << endl;
        }
        return nums[n];
    }

    // 3 
    const int MOD = 1e9 + 7;
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        int m = 2;
        int maxR = ranges[0][1];
        for (auto range : ranges) {
            if (range[0] > maxR) {
                m = m * 2 % MOD;
            }
            maxR = max(maxR, range[1]);
        }

        return m;
    }

    // 330 周赛
    int passThePillow(int n, int time) {
        int ans = 1;
        bool flag;
        for (int i = 1; i <= time; ++i) {
            if (ans == 1) {
                flag = true;
            } else if (ans == n) {
                flag = false;
            }
            if (flag) {
                ans++;
            } else {
                ans--;
            }
            cout << ans << endl;
        }
        return ans;
    }
    
    // 2
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

    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<vector<int>> orders;
        orders = levelOrder(root);
        priority_queue<long long, vector<int>,greater<int>> pq;
        for (auto order : orders) {
            long long temp = 0;
            for (auto o : order) {
                temp += o;
            }
            pq.push(temp);
        }
        
        for (int i = 0; i < k; ++i) {
            pq.pop();
        }
        return pq.top();
    }

    // 3
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = 1;
        for (int i = 0; i < n - 1; ++i) {
            cout << "i :" << i << endl;
            l = l * nums[i];
            cout << l << " " << r << endl;
            int j = i + 1;
            for (; j < n; ++j) {
                cout << "==" << endl;
                r *= nums[j];
                cout << l << " " << r << endl;
                if (gcd(l, r) != 1) {
                    break;
                }

            }
            cout << "j:" << j << endl;
            if (j == n) {
                cout << "!!" << endl;
                return i;
            }
            r = 1;
        }
        return -1;
    }
    // int findValidSplit(vector<int>& nums) {
    //     int n = nums.size();
        
    //     long long sum = 1;
    //     for (int i = 0; i < n; ++i) {
    //         sum *= nums[i];
    //     }
    //     long long l = 1, r = sum;
    //     for (int i = 0; i < n; i++) {
    //         l = l * nums[i];
    //         r = r / nums[i];
    //         cout << l << "  " << r << endl;
    //         if (gcd(l, r) == 1) {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }
};

int main()
{
    cout << "hello" << endl;
    ListNode head(0);
    Solution so;
    //cout << so.coloredCells(4) << endl;
    // [1,3],[10,20],[2,5],[4,8]
    vector<vector<int>> test{{1, 3}, {10, 20}, {2, 5}, {4, 8}};
    //so.countWays(test);
    //so.passThePillow(4, 5);
    //so.kthLargestLevelSum()
    vector<int> test1{4,7,8,15,3,5};
    cout << so.findValidSplit(test1) << endl;
    return 0;
}






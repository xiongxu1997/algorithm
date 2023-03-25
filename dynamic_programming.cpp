//
// Created by xx on 2023/3/25.
//
# include<vector>
# include<iostream>
# include <stack>

using namespace std;

// 1. 斐波那契数列
int Fibonacci(int n) {
    if (n==1){
        return 1;
    }
    if (n==2){
        return 1;
    }
    int a = 1;
    int b = 2;
    for (int i = 3; i < n; i++){
        int c = a+b;
        a = b;
        b = c;
    }
    return b;
}

// 2. 跳台阶
int jumpFloor(int target) {
    if (target==1){
        return 1;
    }
    if (target==2){
        return 2;
    }
    int a=1, b=2;
    for(int i=2; i<target; i++){
        int c = a+b;
        a = b;
        b = c;
    }
    return b;
}

// 3. 最小花费爬楼梯
int minCostClimbingStairs(vector<int>& cost) {
    //dp[i]表示爬到第i阶楼梯需要的最小花费
    vector<int> dp(cost.size()+1, 0);
    for(int i=2;i<cost.size()+1;i++){
        dp[i]=min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
    }
    return dp[cost.size()];
}

// 4. 最长公共子序列
string LCS(string s1, string s2) {
    //只要有一个空字符串便不会有子序列
    if (s1.length() == 0 || s2.length() == 0)
        return "-1";
    int len1 = s1.length();
    int len2 = s2.length();
    //dp[i][j]表示第一个字符串到第i位，第二个字符串到第j位为止的最长公共子序列长度
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    //遍历两个字符串每个位置求的最长长度
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            //遇到两个字符相等
            if (s1[i - 1] == s2[j - 1])
                //来自于左上方
                dp[i][j] = dp[i - 1][j - 1] + 1;
                //遇到的两个字符不同
            else
                //来自左边或者上方的最大值
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    //从动态规划数组末尾开始
    int i = len1, j = len2;
    stack<char> s;
    while (dp[i][j]) {
        //来自于左方向
        if (dp[i][j] == dp[i - 1][j])
            i--;
            //来自于上方向
        else if (dp[i][j] == dp[i][j - 1])
            j--;
            //来自于左上方向
        else if (dp[i][j] > dp[i - 1][j - 1]) {
            i--;
            j--;
            //只有左上方向才是字符相等的情况，入栈，逆序使用
            s.push(s1[i]);
        }
    }
    string res = "";
    //拼接子序列
    while (!s.empty()) {
        res += s.top();
        s.pop();
    }
    //如果两个完全不同，返回字符串为空，则要改成-1
    return res != "" ? res : "-1";
}

// 5. 最长公共子串
string LCS2(string str1, string str2) {
    //dp[i][j]表示到str1第i个,到str2第j个为止的公共子串长度
    vector<vector<int>> dp(str1.length()+1, vector<int>(str2.length()+1, 0));
    int pos = 0;
    int max = -1;
    for(int i=1;i<=str1.length();i++){
        for(int j=1;j<=str2.length();j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = 0;
            }
            if(max<dp[i][j]){
                pos = i-1;
                max = dp[i][j];
            }
        }
    }
    return str1.substr(pos-max+1,max);
}

// 6. 矩阵的最小路径数，只能向右和向下走，求左上角到右下角的路径数
int uniquePaths(int m, int n) {
    // write code here
    if(m==1 or n==1)
        return 1;
    return uniquePaths(m-1,n)+uniquePaths(m,n-1);
}

// 7. 矩阵的最小路径和，只能向右和向下走，求左上角到右下角的最小路径和
int minPathSum(vector<vector<int> >& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    //dp[i][j]表示到[i,j]的最小路径和
    dp[0][0] = matrix[0][0];
    for(int i=1;i<m;i++)
        dp[i][0] = dp[i-1][0]+matrix[i][0];
    for(int j=1;j<n;j++)
        dp[0][j] = dp[0][j-1]+matrix[0][j];
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j] = min(dp[i-1][j], dp[i][j-1])+matrix[i][j];
        }
    }
    return dp[m-1][n-1];
}

// 8. 把数字翻译成字符串
int solve(string nums) {
    //排除0
    if(nums=="0")
        return 0;
    //排除只有一种可能的10 和 20
    if(nums=="10" or nums=="20")
        return 1;
    //当0的前面不是1或2时，无法译码，0种
    for(int i=1;i<nums.size();i++)
        if(nums[i]=='0' and (nums[i-1]!='1' and nums[i-1]!='2'))
            return 0;
    //dp[i]表示前i个数字的译码结果
    vector<int> dp(nums.size()+1, 1);
    for(int i=2;i<nums.size()+1;i++){
        //如果是在11-19，21-26之间的情况
        if((nums[i-2]=='1' and nums[i-1]!='0')or(nums[i-2]=='2' and nums[i-1]>'0' and nums[i-1]<'7')){
            dp[i] = dp[i-1]+dp[i-2];
        }else{
            dp[i] = dp[i-1];
        }
    }
    return dp[nums.size()];
}

// 9. 兑换零钱，求组成aim的最少零钱数
// arr中所有的值都为正整数且不重复，每个值代表一种面值的货币，每种面值的货币可以使用任意张
int minMoney(vector<int>& arr, int aim) {
    //小于1的都返回0
    if(aim<1)
        return 0;
    //dp[i]表示凑齐i元的最少货币数
    vector<int> dp(aim+1, aim+1);
    dp[0] = 0;
    //遍历1-aim元
    for(int i=1;i<=aim;i++){
        //判断每种面值的货币
        for(int j=0;j<arr.size();j++){
            //如果面值不超过要凑的钱才能用
            if(arr[j]<=i){
                //维护最小值，不加货币j和加货币j都要考虑
                dp[i] = min(dp[i], dp[i-arr[j]]+1);
            }
        }
    }
    //如果最终答案大于aim代表无解（看dp初始化的值）
    return dp[aim]>aim?-1:dp[aim];
}

// 10. 求给定数组的最长严格上升子序列的长度
int LIS(vector<int>& arr) {
    //dp[i]表示到下标为i的元素为止的子序列的最大长度
    vector<int> dp(arr.size(),1);
    if(arr.size()==0)
        return 0;
    if(arr.size()==1)
        return 1;
    int res = 0;
    for(int i=1;i<arr.size();i++){
        for(int j=0;j<i;j++){
            //找出在[0, i-1]中的最大值arr[j]，需满足dp[i] < dp[j] + 1
            if(arr[j]<arr[i] and dp[j]+1>dp[i]){
                dp[i] = dp[j]+1;
                res = max(res, dp[i]);
            }

        }
    }
    return res;
}

// 11. 求连续子数组的最大和
int FindGreatestSumOfSubArray(vector<int> array) {
    //dp[i]表示到下标i为止的最大连续子数组和
    vector<int> dp(array.size(), 0);
    dp[0] = array[0];
    int res = dp[0];
    for(int i=1; i<array.size();i++){
        dp[i] = max(array[i], dp[i-1]+array[i]);
        res = max(res, dp[i]);
    }
    return res;
}

// 12. 最长回文子串
int getLongestPalindrome(string A) {
    int n = A.length();
    bool dp[n][n];
    int mx = 0;
    for (int len = 0; len < n; len++) {       // 子串的长度
        for (int l = 0; l + len < n; l++) {   // 子串的起点
            int r = l + len;                  // 子串的终点
            if (len == 0)                     // 如果是单字符子串
                dp[l][r] = true;              // 则直接返回true
            else if (len == 1)                // 如果是相邻的双字符子串
                dp[l][r] = (A[l] == A[r]);    // 判断是否相同
            else
                dp[l][r] = (A[l] == A[r] &&
                            dp[l + 1][r - 1]); // 其他情况就利用递推方程
            if (dp[l][r])
                mx = max(mx, r - l + 1);    // 统计最长串
        }
    }
    return mx;
}

// 13. 编辑距离
int editDistance(string str1, string str2) {
    //dp[i][j]表示str1的前i个元素到str2的前j个元素的编辑距离
    int n1 = str1.size();
    int n2 = str2.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    for(int i=1;i<n1+1;i++)
        dp[i][0] = dp[i-1][0]+1;
    for(int j=1;j<n2+1;j++)
        dp[0][j] = dp[0][j-1]+1;
    for(int i=1;i<n1+1;i++){
        for(int j=1;j<n2+1;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
        }
    }
    return dp[n1][n2];
}

// 14. 最长括号子串，最长的格式正确的括号子串的长度
int longestValidParentheses(string s) {
    int res = 0;
    int end = -1;
    stack<int> st;
    for(int i = 0; i < s.length(); i++){
        //左括号就入栈
        if(s[i]=='(')
            st.push(i);
        else{
            if(st.empty()) // 遇到右括号，且栈为空，非法，更新终点
                end = i;
            else{ // 栈不空，左括号出栈匹配
                st.pop();
                if(!st.empty()) //栈中还有左括号
                    res = max(res, i - st.top());
                else
                    res = max(res, i - end);
            }
        }
    }
    return res;
}

// 15. 打家劫舍序列型
int rob(vector<int>& nums) {
    //dp[i]表示长度为i的数组，最多能偷取多少钱
    vector<int> dp(nums.size() + 1, 0);
    //长度为1只能偷第一家
    dp[1] = nums[0];
    for(int i = 2; i <= nums.size(); i++)
        //对于每家可以选择不偷或者偷
        dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
    return dp[nums.size()];
}

//16. 打家劫舍圆型
int rob_circle(vector<int>& nums) {
    //dp[i]表示长度为i的数组，最多能偷取多少钱
    vector<int >dp(nums.size()+1, 0);
    int n=nums.size();
    //第一家不偷
    dp[1] = 0;
    for(int i=2;i<=n;i++){
        dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
    }
    int ans1 = dp[n];
    //清除dp数组，第二次循环
    dp.clear();
    //第一家偷
    dp[1] = nums[0];
    for(int i=2;i<n;i++){
        dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
    }
    return max(ans1, dp[n-1]);
}

//17. 返回买卖股票能获得的最大收益， 总共只能买入和卖出一次，且买入必须在卖出的前面的某一天
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    //dp[i][0]表示某一天不持股到该天为止的最大收益，dp[i][1]表示某天持股，到该天为止的最大收益
    vector<vector<int> > dp(n, vector<int>(2, 0));
    //第一天不持股，总收益为0
    dp[0][0] = 0;
    //第一天持股，总收益为减去该天的股价
    dp[0][1] = -prices[0];
    //遍历后续每天，状态转移
    for(int i = 1; i < n; i++){
        // 不持股票，前一天就不持有 或者 前一天持有并且当天卖掉
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        // 持有股票，前一天就持有 或者 前一天不持有并且当天买入
        dp[i][1] = max(dp[i - 1][1], -prices[i]);
    }
    //最后一天不持股，到该天为止的最大收益
    return dp[n - 1][0];
}

// 18. 返回买卖股票能获得的最大收益，你可以多次买卖该只股票，但是再次购买前必须卖出之前的股票
int maxProfit2(vector<int>& prices) {
    //dp[i][0]表示某天不持股到该天为止的最大收益，dp[i][1]表示某天持股到该天为止的最大收益
    vector<vector<int>>dp(prices.size(), vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for(int i=1;i<prices.size();i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
    }
    return max(dp[prices.size()-1][0], dp[prices.size()-1][1]);
}

// 19. 返回买卖股票能获得的最大收益，最多可以对该股票有两笔交易操作
int maxProfit3(vector<int>& prices) {
    int n = prices.size();
    //初始化dp为最小
    vector<vector<int>> dp(n, vector<int>(5, -10000));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for(int i=1;i<n;i++){
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
        dp[i][2] = max(dp[i-1][2], dp[i-1][1]+prices[i]);
        dp[i][3] = max(dp[i-1][3], dp[i-1][2]-prices[i]);
        dp[i][4] = max(dp[i-1][4], dp[i-1][3]+prices[i]);
    }
    return max(dp[n-1][2], dp[n-1][4]);
}

int main(){
    cout<<Fibonacci(4);
}
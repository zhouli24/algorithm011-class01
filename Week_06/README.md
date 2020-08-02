学习笔记
动态规划3个要素：
1、最优子结构
2、定义中间状态
3、根据中间状态，推导状态转移方程

例题分析：
回文子串：
https://leetcode-cn.com/problems/palindromic-substrings/submissions/

首先想到的是暴力法，三层循环一个一个子串判断是否为回文子串，时间复杂度O(n^3)
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        if (len == 1) return len;
        int ans = len;

        for (int i=2; i<=len; i++) {
            for (int j=0; j<= len-i; j++) {
                int m=j, n=j+i-1;
               // cout<<"m="<<m<<" n="<<n<<endl;
                while (m < n) {
                    if (s[m] != s[n]) {
                        break;
                    }
                    m++;
                    n--;
                }
                if (m >= n) ans++;  
            }
        }
        return ans;
    }
};

动态规划:
1、假设s是回文子串，那么s前以及s后2个字符相等，s-1~s+1也为回文子串，从中心向2边扩展，子问题最优解与全局最优解有递推关系，可以用动态规划。
2、中间存储状态，f[i][j]表示到j的子串是否为回文子串。
3、递推公式：f(i)(j) = f(i+1)(j-1)&&(s[i] == s[j])  
还有2个特殊情况1、i=j必为回文子串；2、s[i] ==s[j] && j-i==1

int countSubstrings(char * s){
    int len = strlen(s);
    int ans = 0;
    int **dp = NULL;

    dp = malloc(sizeof(int *) * len);
    for (int i=0; i<len; i++) {
        dp[i] = malloc(len * sizeof(int));
        memset(dp[i], 0, len * sizeof(int));
    }

    for (int i=0; i<len; i++) {
        dp[i][i] = 1;
    }

    for (int hi=0; hi<len; hi++) {
        for (int lo=0; lo<=hi; lo++) {
            if ((s[lo]==s[hi]) && ((hi-lo<=1) || (((hi>=1) &&(lo+1<len)) && (dp[lo+1][hi-1]==1)))) {
                dp[lo][hi] = 1;
                ++ans;
            }
            
        }
    }

    return ans;
}

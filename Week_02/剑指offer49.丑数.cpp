class Solution {
public:
    //丑数 *2，3，5还是丑数
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        int a = 0,b= 0,c =0;
        dp[0]=1;
        for(int i = 1;i<n;i++){
            int a2 = dp[a]*2,b3 = dp[b]*3,c5 = dp[c]*5;
            dp[i]=min(a2,min(b3,c5));
            //去除重复元素 要进行多次比较
            if(dp[i]==a2) a++;
            if(dp[i]==b3) b++;
            if(dp[i]==c5) c++;
        }
        return dp[n-1];
    }
};

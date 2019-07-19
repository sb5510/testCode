//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
class Solution {
public:
    int jump(vector<int>& nums) {
	//从尾部开始查找
        int end = nums.size() - 1;
        int result = 0;
        while(end>0)
        {
            for(int i = 0;i<end;i++)
            {
                if(i+nums[i] >= end)
                {
                    end = i;
                    result ++;
                    break;
                }
            }
        }
        return result;
    }
	//贪心
	int jump2(vector<int>& nums) {
        int dis = 0;
        int result = 0;
        int i = 0;
        while(dis<nums.size()-1)
        {
            result ++;
            int pre = dis;
            for(;i<=pre;i++)
            {
                dis = max(dis,i+nums[i]);//得到每一步最长距离
            }
        }
        return result;
    }
	//动态规划
	int jump3(vector<int>& nums) {
        int *dp = new int[nums.size()]();
        for(int i = 1;i<nums.size();i++)
        {
            dp[i] = INT_MAX;
        }
        for(int i = 1;i<nums.size();i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(dp[j]!=INT_MAX&&(j+nums[j])>=i)
                {
                    dp[i] = min(dp[i],dp[j]+1);
                }
            }
        }
        return dp[nums.size()-1];
    }
};

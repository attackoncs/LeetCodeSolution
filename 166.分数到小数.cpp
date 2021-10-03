/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

// @lc code=start
class Solution {
    typedef long long ll;
public:
    string fractionToDecimal(int num, int den) {
        string res;
        //防止溢出
        ll numerator=ll(num),denominator=ll(den);
        if(numerator*denominator<0)res+="-";//加上负号
        numerator=abs(numerator),denominator=abs(denominator);
        ll n=numerator%denominator;
        res+=to_string(numerator/denominator);
        if(!n)return res;//整除
        res+=".";//不整除则加上小数点符号。
        ll idx=0;
        unordered_map<ll,int> m;//记录余数的位置
        string s;
        //若剩余数不为空且hash表中找不到则继续
        while(n&&!m.count(n)){
           m[n]=idx++;
           n*=10;
           s.push_back(n/denominator+'0');
           n%=denominator; 
        }
        if(n)res+=s.substr(0,m[n])+"("+s.substr(m[n])+")";
        else res+=s;
        return res;
    }
};
// @lc code=end


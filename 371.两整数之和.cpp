/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        // int res=0,t=0;
        // for(int i=0;i<32;++i){
        //     int first=(a>>i)&1,second=(b>>i)&1;
        //     if(first==1&&second==1){
        //         res|=(t<<i);
        //         t=1;
        //     }else if(first==1||second==1){
        //         res|=((1^t)<<i);
        //     }else{
        //         res|=(t<<i);
        //         t=0;
        //     }
        // }
        // return res;
        //本质是先求a^b再考虑进位，而进位只需左移一位,这样写 -1 1用例通不过
        return b == 0 ? a : getSum(a ^ b, (unsigned int)(a & b) << 1);
        // while (b != 0) {
        //     unsigned int carry = (unsigned int)(a & b) << 1;
        //     a = a ^ b;
        //     b = carry;
        // }
        // return a;
        //此外还可将a+b看成一个自增一个自减
    }
};
// @lc code=end


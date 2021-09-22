/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res;
        int len=0;
        ListNode* t=head;
        while(t!=NULL){
            len++;t=t->next;
        }
        int every=len/k,left=len%k;
        ListNode* h=head;
        ListNode* cur=head;
        for(int i=0;i<k;i++){//k组
            //有可能every为0，导致下面继续，因此要分类讨论
            if(every!=0){
                for(int j=1;j<every;++j){//每组every个
                    cur=cur->next;
                }
                if(i<left){//前面多加一个
                    cur=cur->next;
                }
            }
            //处理最后压入为NULL的特殊情况，这题思路不难，难在代码实现上
            ListNode* q=NULL;
            if(cur!=NULL)
                q=cur->next;
            if(q!=NULL){
                cur->next=NULL;
            }else{
                q=NULL;
            }
            res.push_back(h);
            h=q;
            cur=q;
        }
        return res;
    }
};
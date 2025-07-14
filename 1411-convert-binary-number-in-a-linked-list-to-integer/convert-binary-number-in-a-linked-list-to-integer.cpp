
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode *temp=head;
        vector<int> v;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int x=1;
        int num=0;
        for(int i=v.size()-1;i>=0;i--){
            num+=(v[i]*x);
            x*=2;
        }
        return num;
    }
};
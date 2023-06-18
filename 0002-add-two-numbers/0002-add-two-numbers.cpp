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
  const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}(); 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2,int carry=0) {
       ListNode *root=new ListNode();
       int i=0,j=0;
       if(l1==NULL && l2==NULL && carry==0)return NULL;
      
       if(l1!=NULL){i=l1->val;l1=l1->next;} 
       if(l2!=NULL){j=l2->val;l2=l2->next;}
        if(l1==NULL && l2==NULL && carry!=0)
        { root->val=(i+j+carry)%10;
       carry=(i+j+carry)/10;}
       else{   root->val=(i+j+carry)%10;
       carry=(i+j+carry)/10;}
       root->next=addTwoNumbers(l1,l2,carry);
       return root;
    }
};
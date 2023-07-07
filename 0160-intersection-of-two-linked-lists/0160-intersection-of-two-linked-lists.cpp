/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
 */
 



class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<int,int>m;
        vector<int>v;
          ListNode * temp=headA;
          while(temp!=NULL)
          {
              m[temp->val]++;
              temp=temp->next;
          }
          temp=headB;
          while(temp!=NULL)
          {
              m[temp->val]++;
              if(m[temp->val]>1)v.push_back(temp->val);
              temp=temp->next;
          }
          for(int i=0;i<v.size();i++)
          {
               ListNode * temp1=headA;
               ListNode * temp2=headB;
               while(temp1->val!=v[i])
               {
                   temp1=temp1->next;
               }
               while(temp2->val!=v[i])
               {
                   temp2=temp2->next;
               }
               if(temp1==temp2)return temp1;


          }
          return NULL;
    }
};
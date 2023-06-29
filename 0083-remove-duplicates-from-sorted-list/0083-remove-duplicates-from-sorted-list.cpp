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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp= head;
        int val;
        while(temp!=NULL)
        {
            val=temp->val;
            ListNode* temp2=temp->next;
            while(temp2!=NULL && temp2->val==val)
            {
                temp2=temp2->next;

            }
            temp->next=temp2;
            temp=temp->next;
        }
        return head;
    }
};
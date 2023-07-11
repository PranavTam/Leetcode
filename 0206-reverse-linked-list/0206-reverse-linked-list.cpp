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
     cout.flush();
      //exit(0);
    return 0;
}(); 
/* int init = [] {
    ios_base::sync_with_stdio(false); // turn off sync
    cin.tie(nullptr);  // untie in/out streams
    ofstream out("user.out"); // redirect stdout to user.out
     for (string s; getline(cin, s);)  // read a line into s
        out << (equal(s.begin()+1, s.begin()+s.size()/2, s.rbegin()+1) ? "true\n" : "false\n");  // write to user.out
    out.flush(); // flush the buffer
    exit(0);  // exit normally
    return 0;
}(); */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int>v;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
         while(temp!=NULL)
        {
            temp->val=v.back();
            v.pop_back();
            temp=temp->next;
        }
        return head;
    }
};
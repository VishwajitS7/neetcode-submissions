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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* temp=head;
        ListNode* prev= dummy;

        int cnt=0;
        while(n>0){
            temp=temp->next;
            n--;
        }
        while(temp!=NULL){
            temp=temp->next;
            prev=prev->next;
        }
        prev->next=prev->next->next;
        return dummy->next;
    }
};

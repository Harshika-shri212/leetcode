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
    ListNode* reverseList(ListNode* head) {
    if (!head) return NULL; 

    ListNode * nxt = head -> next;
    ListNode * curr = head;
    ListNode * prev = NULL;

    while(curr){
        curr -> next = prev;
        prev = curr;
        curr = nxt;
        if(nxt) nxt = nxt->next;
    }

    return prev;
}



};
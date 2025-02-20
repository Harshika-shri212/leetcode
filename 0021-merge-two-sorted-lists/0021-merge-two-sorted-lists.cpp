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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * temp;
        ListNode * head;

        ListNode * l1;
        ListNode * l2;

        l1 = list1;
        l2 = list2;

        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1 -> val < l2 -> val){
            temp = l1;
            l1 = l1 -> next;
        }
        else{
            temp = l2;
            l2 = l2 -> next;
        }

        head = temp;

        while(l1 && l2){
            if(l1 -> val <= l2 -> val){
                temp -> next = l1;
                temp = temp -> next ;
                l1 = l1 -> next;
            }
            else{
                temp -> next = l2;
                l2 = l2 -> next;
                temp = temp -> next;
            }
        }

        if(l1){
            while(l1){
                temp -> next = l1;
                temp = temp -> next ;
                l1 = l1 -> next;
            }
        }

        if(l2){
            while(l2){
                temp -> next = l2;
                temp = temp -> next ;
                l2 = l2 -> next;
            }
        }

        return head;

    }
};
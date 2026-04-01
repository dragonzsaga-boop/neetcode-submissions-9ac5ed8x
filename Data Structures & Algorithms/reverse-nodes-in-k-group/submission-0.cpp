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
using node = ListNode*;
class Solution {
    ListNode* reverse(ListNode* &head) {
        // for(auto temp = head; temp; temp = temp->next) cout<<temp->val<<" "; cout<<endl;
        ListNode *curr(head), *prev(nullptr), *tail(head);
        while(head) {
            curr = head;
            head = head->next;
            curr->next = prev;
            prev = curr;
        }
        // for(auto temp = curr; temp; temp = temp->next) cout<<temp->val<<" "; cout<<endl;
        head = prev;
        return tail;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // reverseLL(head);return head;
        if(!head || k < 2) return head;

        node sentinel = new ListNode;
        sentinel->next = head;
        
        node curr(head), next(head), prevTail(sentinel);
        int i = 0;
        while(true) {
            node reversedHead(curr), prev(prevTail);
            for(i = 0; curr && (i < k); ++i) {
                prev = curr; //store k'th element to separate from remaining linked list
                curr = curr->next; //point to (k + 1)th element
            }
            if(i < k) break; //break when insufficient number of nodes left to reverse
            
            prev->next = nullptr; //break the group of k
            
            node tail = reverse(reversedHead);
            
            //link newly reversed group to already reversed linked list
            prevTail->next = reversedHead;
            //link newly reversed group to remaining/unreversed linked list
            tail->next = curr;
            //update tail of overall reversed linked list
            prevTail = tail;
        }
        return sentinel->next;

        {
            // // count & group elements [] [] [] [ )
            // ListNode *prevHead(head), *prevTail(nullptr), *newHead(nullptr);
            // while(head) {
            //     int i = 1;
            //     auto sublistHead(head), tail(head);
            //     while(i < k && tail) {
            //         ++i; tail = tail->next;
            //     }
            //     cout<<i<<" :" <<k<<endl;
            //     if(i != k && !tail) {
            //         return newHead;
            //     }
            //     cout<<"prereversal sublist head : "<<sublistHead->val
            //         <<",, sublist tail : "<<(tail?tail->val:0)<<endl;
                
            //     // separate sub list
            //     head = tail->next;
            //     tail->next = nullptr;

            //     // reverse sub list
            //     auto newTail = reverseLL(sublistHead);
            //     // cout<<head->val<<" : "<<newTail->val<<endl;
            //     // connect back
            //     if(prevTail) {
            //         if(sublistHead)
            //         cout<<"Updating prevTail : "<<sublistHead->val<<endl;
            //         prevTail->next = sublistHead;
            //     }
            //     prevTail = newTail;
            //     // update final list head only once
            //     if(!newHead) {
            //         newHead = sublistHead;
            //     }
            // }
            
            // return newHead;
        }
    }
};

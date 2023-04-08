// Leetcode 206 Reverse Linked List : https://leetcode.com/problems/reverse-linked-list/
// First method using Stacks

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
        if(!head) return NULL;
        
        stack<ListNode* > s;
        while(head!=NULL)
        {
            s.push(head);
            head = head->next;
        }
        
        ListNode* n = s.top();
        s.pop();
        ListNode* p = n;
        
        while(!s.empty())
        {
            p->next = s.top();
            s.pop();
            p = p->next;
            if(s.empty()) p->next = NULL;
        }
        
        return n;
    }
};

// 2. Using the 3 pointers prev, current, next & reversing the links.

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
        
        if(!head) return NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr!=NULL)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            if(next==NULL) head = curr;
            curr = next;
            
        }
        
        return head;
    }
};

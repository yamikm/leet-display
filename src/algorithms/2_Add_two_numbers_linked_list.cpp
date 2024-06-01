/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.


Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

*/


using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // 8   8    0   6  
    // 9        1   0      
    // 1        1   2
    ListNode *Head =new ListNode(0);
    ListNode *curr = Head;
    int carry =0;
    while(l1 != nullptr || l2!= nullptr || carry >0){
        int sum =carry;
        if( l1 != nullptr && l2!= nullptr) {
            sum += l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
        }
        else if(l1 != nullptr) {
            sum += l1->val ;
            l1 = l1->next;
        }
        else if(l2 != nullptr){
            sum += l2->val ;
            l2 = l2->next;
        }
        carry = sum/10;
        sum = sum % 10;
        ListNode* tmp =new  ListNode(sum);
        curr->next = tmp;
        
        curr = curr->next;;
    }    
    return Head->next;   
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *Head =new ListNode(0);
    ListNode *curr = Head;
    int carry =0;
    while(l1!= nullptr || l2!= nullptr || carry){
        int d1 = l1 != nullptr ? l1->val  : 0;
        int d2 = l2 != nullptr ? l2->val  : 0;
        int sum = d1 + d2 + carry;
        carry = sum/10;
        sum = sum%10;
        ListNode* tmp = new ListNode(sum);
        curr->next = tmp;
        curr = curr->next;
        l1 = l1 != nullptr ? l1->next : nullptr;
        l2 = l2 != nullptr ? l2->next : nullptr;
    }
    ListNode* tmp= Head;
    Head = Head->next;
    delete tmp;
    return Head;
}
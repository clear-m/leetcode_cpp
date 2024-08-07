/*
Given the head of a singly linked list, reverse the list, and return the reversed list.



Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []


Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000


Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

#include <cassert>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverse_list(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *current = nullptr;
    while (head != nullptr)
    {
        current = head;
        head = head->next;
        current->next = prev;
        prev = current;
    }
    return current;
}

ListNode *reverse_list_b(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *newHead = reverse_list_b(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

ListNode *reverse_list_c(ListNode *head)
{
    ListNode *prev = nullptr;
    while (head)
    {
        ListNode *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

void delete_list(ListNode *head)
{
    ListNode *prev = head;
    while (head)
    {
        head = head->next;
        delete prev;
        prev = head;
    }
}

int main(int argc, char **argv)
{
    ListNode *head = new ListNode{1, new ListNode{2, new ListNode{3, new ListNode{4, new ListNode{5, nullptr}}}}};
    head = reverse_list(head);
    assert(head->val == 5);
    delete_list(head);
    return 0;
}

#include <cassert>

/*
Time: 𝑂(𝑛)
Space: 𝑂(1)
*/

// Given the head of a linked list, remove the nth node from the end of the list and return its head.
// Example 1:
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:
// Input: head = [1], n = 1
// Output: []
// Example 3:
// Input: head = [1,2], n = 1
// Output: [1]

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//TODO: try to implement with backward lookup (with one ptr)
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (n--)
    {
        fast = fast->next;
    }
    if (fast == nullptr)
    {
        return head->next;
    }
    while (fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return head;
}

int main(int argc, char **argv)
{
    // [1,2,3,4,5]
    ListNode fifth(5, nullptr);
    ListNode forth(4, &fifth);
    ListNode third(3, &forth);
    ListNode second(2, &third);
    ListNode first(1, &second);
    ListNode* head = &first;
    ListNode* new_head = removeNthFromEnd(&first, 2);

    assert(third.next == &fifth);

    return 0;
}

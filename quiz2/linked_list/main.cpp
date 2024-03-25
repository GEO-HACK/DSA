#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool Cycle_Check(ListNode *head) {
    // Check if the list is empty or has only one node (no cycle can exist)
    if (!head || !head->next) {
        return false;
    }

    // Initialize two pointers: slow and fast
    ListNode *slow = head;
    ListNode *fast = head->next;

    // Traverse the list with slow and fast pointers
    while (slow != fast) {
        // If fast pointer or its next is null, it means no cycle exists
        if (!fast || !fast->next) {
            return false;
        }
        // Move slow pointer one step forward
        slow = slow->next;
        // Move fast pointer two steps forward
        fast = fast->next->next;
    }

    // If we reached here, it means slow and fast pointers have met, indicating a cycle
    return true;
}

int main() {
    // Create a sample linked list with a cycle
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next ->next->next = head->next->next; // Connect the tail to the second node

    // Check if the linked list has a cycle
    if (Cycle_Check(head)) {
        //std::cout << "The linked list has a cycle." << std::endl;
        return true;
    } else {
       // std::cout << "The linked list does not have a cycle." << std::endl;
       return false;
    }


    return 0;
}

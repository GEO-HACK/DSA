#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr; // No cycle if less than two nodes

        ListNode *slow = head;
        ListNode *fast = head;
        bool hasCycle = false;

        // Detect cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }

        // If no cycle, return nullptr
        if (!hasCycle) return nullptr;

        // Find the node where the cycle begins
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

// function to create a linked list
ListNode* createLinkedListWithCycle(int pos) {
    ListNode *head = new ListNode(1);
    ListNode *tail = head;
    ListNode *cycleNode = nullptr;

    for (int i = 2; i <= 5; ++i) {
        tail->next = new ListNode(i);
        tail = tail->next;
        if (i == pos) cycleNode = tail; // Set cycle node
    }

    if (pos != -1) tail->next = cycleNode; // Create cycle

    return head;
}

int main() {
    Solution solution;

    // Create a linked list with cycle
    ListNode *head = createLinkedListWithCycle(2);

    // Detect cycle and find the node where the cycle begins
    ListNode *cycleStartNode = solution.detectCycle(head);

    // Print the result
    if (cycleStartNode)
        std::cout << "Cycle starts at node with value: " << cycleStartNode->val << std::endl;
    else
        std::cout << "No cycle found" << std::endl;

    return 0;
}

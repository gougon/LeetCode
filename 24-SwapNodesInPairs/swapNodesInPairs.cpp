#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* left = cur;
        ListNode* right = cur->next;
        head = right;
        left->next = right->next;
        right->next = left;

        prev = left;
        cur = left->next;

        while (cur && cur->next) {
            left = cur;
            right = cur->next;
            swapPair(prev, left, right);
            prev = left;
            cur = left->next;
        }

        return head;
    }

    void swapPair(ListNode* prev, ListNode* left, ListNode* right) {
        prev->next = right;
        left->next = right->next;
        right->next = left;
    }
};

void printList(ListNode *head) {
    ListNode *cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    int len = 7;
    int listVal[len] = {2, 5, 3, 4, 6, 2, 2};
    ListNode *head = new ListNode();
    ListNode *cur = head;
    for (int i = 0; i < len; i++) {
        cur->val = listVal[i];
        if (i != len - 1)
            cur->next = new ListNode();
        cur = cur->next;
    }

    printList(head);

    Solution solution = Solution();
    head = solution.swapPairs(head);

    printList(head);
    return 0;
}

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodeAddressList;
        int len = 0;
        ListNode *cur = head;
        while (cur != nullptr) {
            nodeAddressList.push_back(cur);
            cur = cur->next;
            len++;
        }

        int removeIdx = len - n;
        if (len == 1 && removeIdx == 0)
            head = nullptr;
        else if (removeIdx == 0)
            head = nodeAddressList[1];
        else if (removeIdx == len - 1)
            nodeAddressList[removeIdx - 1]->next = nullptr;
        else
            nodeAddressList[removeIdx - 1]->next = nodeAddressList[removeIdx + 1];
        return head;
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
    int len = 2;
    int listVal[len] = {1, 2};
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
    head = solution.removeNthFromEnd(head, 1);

    printList(head);
    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result, **cur = &result;
        int carry = 0;
        while (l1 || l2) {
            int sum = 0;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            *cur = new ListNode(sum % 10);
            cur = &(*cur)->next;
        }
        if (carry)
            *cur = new ListNode(1);
        return result;
    }
};

ListNode* MakeNumber(int num)
{
    vector<int> numList;
    while (num > 0) {
        numList.push_back(num % 10);
        num /= 10;
    }
    ListNode* head, **cur = &head;
    for (auto i : numList) {
        *cur = new ListNode(i);
        cur = &(*cur)->next;
    }
    return head;
}

void PrintList(ListNode* list)
{
    while (list) {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    Solution s;
    ListNode* l1 = MakeNumber(9999999);
    ListNode* l2 = MakeNumber(9999);
    PrintList(l1);
    PrintList(l2);
    ListNode* r = s.addTwoNumbers(l1, l2);
    PrintList(r);
    return 0;
}

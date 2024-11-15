#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *creatListFromArray(vector<int> nums) {
    if (nums.empty()) return nullptr;

    ListNode *head = new ListNode(nums[0]);
    ListNode *current = head;
    for (int i = 1; i < nums.size(); i++) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;

}

class Solution {
public:
    static ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *head = new ListNode();
        ListNode *cur = head;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                cur->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            cur = cur->next;
        }

        while (list1) {
            cur->next = new ListNode(list1->val);
            list1 = list1->next;
            cur = cur->next;
        }

        while (list2) {
            cur->next = new ListNode(list2->val);
            list2 = list2->next;
            cur = cur->next;
        }
        return head->next;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> nums(n), nums2(m);
    for (int &x: nums) cin >> x;
    for (int &x: nums2) cin >> x;

    ListNode *l1 = creatListFromArray(nums);
    ListNode *l2 = creatListFromArray(nums2);
    ListNode *result = Solution::mergeTwoLists(l1, l2);
    ListNode *current = result;
    while (current) {
        cout << current->val << ' ';
        current = current->next;
    }
}
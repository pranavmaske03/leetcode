#include<iostream>
using namespace std;

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
 
class Solution {
public:
    ListNode* curr;

    int getLength(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }

    TreeNode* buildTree(int left, int right) {
        if (left > right)
            return nullptr; 

        int mid = left + (right - left) / 2;
        TreeNode* leftChild = buildTree(left, mid - 1);
        TreeNode* root = new TreeNode(curr->val);
        root->left = leftChild;
        curr = curr->next;
        root->right = buildTree(mid + 1, right);

        return root;
    }

    TreeNode* sortedListToBST  (ListNode* head) {
        if (!head)
            return nullptr;

        int n = getLength(head);
        curr = head;

        return buildTree(0, n - 1);
    }
};

int main()
{
    return 0;
}
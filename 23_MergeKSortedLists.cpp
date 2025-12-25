#include<iostream>
#include<vector>
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
class Solution 
{
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) 
        {
            vector<ListNode*> nodes;

            for(auto& _list : lists) {
                ListNode *_curr = _list;
                while(_curr) {
                    nodes.push_back(_curr);
                    _curr = _curr->next;
                }
            }

            if(nodes.empty()) return nullptr;

            sort(nodes.begin(),nodes.end(),[](ListNode* a, ListNode* b) {
                return a->val < b->val;
            });     

            for(int i = 0; i < nodes.size()-1; i++) {
                nodes[i]->next = nodes[i+1];
            }
            nodes.back()->next = nullptr;

            return nodes[0];
        }
};    

int main()
{

    return 0;
}
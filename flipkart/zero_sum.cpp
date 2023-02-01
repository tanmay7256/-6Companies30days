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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *root = head, *temp = head;
        unordered_map<int, ListNode *> umap;
        stack<pair<int, ListNode *>> stk;
        int sum = 0;
        umap[0] = root;
        while (temp)
        {
            sum += temp->val;
            if (umap[sum])
            {
                pair<int, ListNode *> t = {sum, umap[sum]};
                if (!sum)
                    root = temp->next;
                umap[sum]->next = temp->next;
                while (!(stk.empty()) && stk.top() != t)
                {
                    umap[stk.top().first] = NULL;
                    stk.pop();
                }
            }
            else
            {
                umap[sum] = temp;
                stk.push({sum, temp});
            }
            temp = temp->next;
        }
        return root;
    }
};
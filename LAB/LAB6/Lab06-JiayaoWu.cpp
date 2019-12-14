#include <iostream>
#include <queue>
#include <vector>
#include<stack>
#include<sstream>
using namespace std;
void get_median()
{

    priority_queue<double, std::vector<double>, std::less<double>> max_heap;
    priority_queue<double, std::vector<double>, std::greater<double>> min_heap;
    int counter = 0;
    while(true)
    {
        string str;
        cin >> str;
        if(str == "exit")
        {
            break;
        }
        stringstream ss;
        ss << str;
        double p = 0;
        ss >> p;
        double median = 0;
        //Suppose max heap >= min heap in numbers
        if (counter == 0)
        {
            max_heap.push(p);
            median = p;
        }
        else if (counter % 2 == 0)
        {
            median =  (max_heap.top() + min_heap.top()) / 2;
            max_heap.pop();
            min_heap.pop();
        }
        else
        {
            if (p >= max_heap.top())
            {
                min_heap.push(p);
            }
            else
            {
                double tmp = max_heap.top();
                max_heap.pop();
                min_heap.push(tmp);
                max_heap.push(p);
            }
            median = max_heap.top();
        }
        cout << median << "\n";
        counter++;
    }
}


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* first = NULL;
TreeNode* second = NULL;
TreeNode* prev = NULL;
void traverse(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }
    traverse(root->left);
    if(prev != NULL && root->val < prev->val && !first)
    {
        first = prev;
    }
    if(prev != NULL && root->val < prev->val && first)
    {
        second = root;
    }
    prev = root;
    traverse(root->right);
    
}
 
void recoverTree(TreeNode *root)
{
	traverse(root);
    if (first && second)
    {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
	
}

bool verifySquenceOfBST(vector<int> squence)
{
    stack<int> s;
    int root = INT32_MAX;
    for (auto it = squence.rbegin(); it != squence.rend();it++)
    {
        if(*it > root)
        {
            return false;
        }
        while(!s.empty() && *it < s.top())
        {
            root = s.top();
            s.pop();
        }
        s.push(*it);
    }
    return true;
}
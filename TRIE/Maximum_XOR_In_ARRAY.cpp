//https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/



class Solution {
public:

    struct Node{
        Node *left;
        Node *right;
        int num;
        Node(){
            left = NULL;
            right = NULL;
            num = -1;
        }
    };
    string convert(int N)
    {
        string binary = "";
        int bits = 31;
        while(bits--)
        {
            int x = N%2;
            binary += x + '0';
            N = N/2;
        }
        reverse(binary.begin(),binary.end());
        return binary;
    }
    void insert(Node* root,string &S,int numVal)
    {
        Node *curr = root;
        for(int i=0;i<S.size();i++)
        {
            if(S[i] == '0')
            {
                if(curr->left == NULL)
                {
                    curr->left = new Node();
                }
                curr = curr->left;
            }
            else
            {
                if(curr->right == NULL)
                {
                    curr->right = new Node();
                }
                curr = curr->right;
            }
        }
        curr->num = numVal;
        
    }
    int traverse(Node* root,string S,int numVal)
    {
        Node* tmp = root;
        for(int i=0;i<S.size();i++)
        {
            if(S[i] == '1')
            {
                if(tmp->left)
                    tmp = tmp->left;
                else
                    tmp = tmp->right;
            }
            else
            {
                if(tmp->right)
                    tmp = tmp->right;
                else
                    tmp = tmp->left;
            }
        }
        return (tmp->num ^ numVal);
    }
    int findMaximumXOR(vector<int>& nums) {
        vector<pair<string,int>> BIN;

        for(int i=0;i<nums.size();i++)
        {
            BIN.push_back({convert(nums[i]),nums[i]});
        }
        Node *root = new Node();
        for(int i=0;i<BIN.size();i++)
        {
            insert(root,BIN[i].first,BIN[i].second);
        }

        int ans = 0;

        for(int i=0;i<BIN.size();i++)
        {
            int curr_ans = traverse(root,BIN[i].first,BIN[i].second);
            ans = max(ans,curr_ans);
        }

        return ans;

        
    }
};


//Brute Force

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                ans = max(ans,nums[i]^nums[j]);
            }
        }

        return ans;
    }
};
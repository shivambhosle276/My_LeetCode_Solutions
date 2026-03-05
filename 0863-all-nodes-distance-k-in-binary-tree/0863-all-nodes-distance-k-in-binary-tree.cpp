
class Solution {
    void markp(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent_track,TreeNode* target)
    {
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty())
        {
            TreeNode* current=queue.front();
            queue.pop();
            if(current->left)
            {
                parent_track[current->left]=current;
                queue.push(current->left);
            }
            if(current->right)
            {
                parent_track[current->right]=current;
                queue.push(current->right);
            }
        }
    } 
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_track;
        markp(root,parent_track,target);
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> queue;
        queue.push(target);
        vis[target]=true;
        int curl=0;
        while(!queue.empty())
        {
            int size=queue.size();
            if(curl++==k)break;
            for(int i=0;i<size;i++)
            {
                TreeNode* current=queue.front();queue.pop();
                if(current->left && !vis[current->left])
                {
                    queue.push(current->left);
                    vis[current->left]=true;
                }
                if(current->right && !vis[current->right])
                {
                    queue.push(current->right);
                    vis[current->right]=true;
                }
                if(parent_track[current] && !vis[parent_track[current]])
                {
                    queue.push(parent_track[current]);
                    vis[parent_track[current]]=true;
                }
            }
        }
        vector<int> result;
        while(!queue.empty())
        {
            TreeNode* current =queue.front();queue.pop();
            result.push_back(current->val);
        }
        return result;
    }
};
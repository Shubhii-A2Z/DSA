/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr) return "";


        // We’ll use level order bfs Traversal
        queue<TreeNode*> nodes;
        nodes.push(root);
        
        string serializedTree="";
        while(nodes.size()){
            int currentQueueSize=nodes.size();
            while(currentQueueSize--){
                TreeNode *currentNode=nodes.front(); nodes.pop();

                if(currentNode==nullptr) serializedTree+="#,";
                else{
                    serializedTree+=to_string(currentNode->val)+",";
                    nodes.push(currentNode->left);
                    nodes.push(currentNode->right);
                }
            }
        }
        // for(auto ch:serializedTree) cout<<ch<<' ';
        return serializedTree;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
            if(data.length()==0) return nullptr;


            stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode *root=new TreeNode(stoi(str));


        queue<TreeNode*> nodes;
        nodes.push(root);


        while(nodes.size()){
            int currentQueueSize=nodes.size();
            while(currentQueueSize--){
                TreeNode *currentNode=nodes.front(); nodes.pop();

                getline(s,str,','); // getting the left child of currentNode

                if(str=="#") currentNode->left=nullptr;
                else{
                    TreeNode *leftChild=new TreeNode(stoi(str));
                    currentNode->left=leftChild;
                    nodes.push(leftChild);
                }
                
                getline(s,str,','); // getting the right child of currentNode

                if(str=="#") currentNode->right=nullptr;
                else{
                    TreeNode *rightChild=new TreeNode(stoi(str));
                    currentNode->right=rightChild;
                    nodes.push(rightChild);
                }
            }
        }


        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
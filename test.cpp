/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
    unordered_map<int,Node*> mp;// for storing the parrent addresee
    Node* beg=nullptr;// begining node
    
    // parent addresee
    void plot(Node* root,Node *par,int t){
        
        if(root==nullptr) return;
        
        mp[root->data]=par;
        
        if(root->data==t) beg=root;
        
        plot(root->left,root,t);
        plot(root->right,root,t);
        
    }
    
    vector<int> kDistanceNodes(Node* root, int target, int k) {
        vector<int> temp;
        
        int a=0;
        
        plot(root,nullptr,target);
        
        if(beg==nullptr) return {};
        
        unordered_set<Node*> st;
        
        queue<Node*> q;
        
        q.push(beg);
        st.insert(beg);
        q.push(nullptr);
        
        while(!q.empty()){
            Node* cur=q.front();
            q.pop();
            
            if(cur==nullptr){
                if(a==k){
                    sort(temp.begin(), temp.end());
                    return temp;
                } 
                temp.clear();
                a++;
                if(q.empty()) break;
                q.push(nullptr);
            }
            
            else{
                temp.push_back(cur->data);
               
                // left push
                
                if(cur->left!=nullptr && !st.count(cur->left)){
                    q.push(cur->left);
                    st.insert(cur->left);
                }
                
                // right push
                if(cur->right!=nullptr && !st.count(cur->right)){
                    q.push(cur->right);
                    st.insert(cur->right);
                }
                
                 // parent push
                if(mp.find(cur->data)!=mp.end()){
                    if(mp[cur->data]!=nullptr && st.find(mp[cur->data])==st.end()){
                        q.push(mp[cur->data]);
                        st.insert(mp[cur->data]);
                    }
                }
            }
            
        }
        return {};
    }
};


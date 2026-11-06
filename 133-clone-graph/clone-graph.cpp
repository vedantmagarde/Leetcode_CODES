/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector<Node*>regNode;

    void dfs(Node *actual,Node* clone){
        if(actual==NULL)return ;

        for(auto neigh: actual->neighbors){
            if(regNode[neigh->val]==NULL){

                Node* newNode=new Node(neigh->val);
                regNode[neigh->val]=newNode;
                clone->neighbors.push_back(newNode);
                dfs(neigh,newNode);

            }else{
                clone->neighbors.push_back(regNode[neigh->val]);

            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(node== NULL)return NULL;

        Node*clone= new Node(node->val);
        regNode.resize(110,NULL);
        regNode[clone->val]=clone;

        dfs(node,clone);

        return clone;
    }
};
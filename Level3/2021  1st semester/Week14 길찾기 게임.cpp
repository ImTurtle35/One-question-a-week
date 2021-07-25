#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
  int num,x,y;
  Node* left_node = NULL;
  Node* right_node = NULL;
};

bool cmp(Node node1, Node node2) {
    if(node1.y == node2.y) return node1.x < node2.x;
    else return node1.y > node2.y;
}

void makeTree(Node* cur_node, Node* child_node) {
    if (cur_node->x > child_node->x) {
        if (cur_node->left_node == NULL) cur_node->left_node = child_node;
        else makeTree(cur_node->left_node, child_node);
    }
    else {
        if (cur_node->right_node == NULL) cur_node->right_node = child_node;
        else makeTree(cur_node->right_node, child_node);
    }
}

void preorder(vector<int> &vec, Node* cur_node) {
    if (cur_node == NULL) {
    	return;
    }
    vec.push_back(cur_node->num);
    preorder(vec, cur_node->left_node);
    preorder(vec, cur_node->right_node);
}

void postorder(vector<int> &vec, Node* cur_node) {
    if (cur_node == NULL) {
    	return;
    }
    postorder(vec, cur_node->left_node);
    postorder(vec, cur_node->right_node);
    vec.push_back(cur_node->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Node>Tree;
    for(int i{0}; i < nodeinfo.size(); i++) {
        Tree.push_back({i+1,nodeinfo[i][0],nodeinfo[i][1]});
    }
    sort(Tree.begin(),Tree.end(),cmp);
    for (int i = 1; i < Tree.size(); i++) {
        makeTree(&Tree[0], &Tree[i]);
    }
    vector<int>prevec;
    vector<int>postvec;
    preorder(prevec, &Tree[0]);
    postorder(postvec, &Tree[0]);
    answer.push_back(prevec);
    answer.push_back(postvec);
    return answer;
}

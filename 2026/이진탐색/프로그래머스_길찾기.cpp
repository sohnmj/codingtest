/*
Y좌표를 신경써서 이진 탐색 트리를 고려하려 처음에 생각했지만 생각해보니 이진 탐색트리는 삽입한 순서에 따라 트리의 레벨이 달라져서 그냥 Y좌표로 내림차순으로 정렬한 다음에 
이진 탐색트리에 삽입하여 이를 해결했다.
 */
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include<set>
#include<deque>
#include<cmath>
#include<queue>
typedef long long ll;
using namespace std;
bool compare(vector<int>& a, vector<int>& b) {
    return a[1] > b[1];
}
vector<vector<int>>ans(2);
class BST {
    struct Node {
        int key;
        int index;
        Node* left = nullptr;
        Node* right = nullptr;
        Node(int key, int index): key(key),index(index){        }
    };

    Node* root = nullptr;

    // 삽입: 작으면 왼쪽, 크면 오른쪽, 빈 자리에 붙임
    Node* insert(Node* node, int key,int index) {
        if (!node) return new Node(key,index);
        if (key < node->key) node->left = insert(node->left, key,index);
        else if (key > node->key) node->right = insert(node->right, key,index);
        return node; // 중복 무시
    }

    // 삭제
    Node* remove(Node* node, int key) {
        if (!node) return nullptr;
        if (key < node->key) node->left = remove(node->left, key);
        else if (key > node->key) node->right = remove(node->right, key);
        else {
            // 자식 0개 또는 1개
            if (!node->left) { Node* r = node->right; delete node; return r; }
            if (!node->right) { Node* l = node->left; delete node; return l; }
            // 자식 2개: 오른쪽 서브트리의 최솟값(후계자)으로 대체
            Node* succ = node->right;
            while (succ->left) succ = succ->left;
            node->key = succ->key;
            node->right = remove(node->right, succ->key);
        }
        return node;
    }

    void preorder(Node* node) {
        if (!node) return;
        ans[0].push_back(node->index);
        preorder(node->left);
        preorder(node->right);
    }
    void postorder(Node* node) {
        if (!node) return;

        postorder(node->left);
        postorder(node->right);
        ans[1].push_back(node->index);
    }

    // 후위 순회로 전체 해제
    void destroy(Node* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    ~BST() { destroy(root); }

    void insert(int key,int index) { root = insert(root, key,index); }
    void remove(int key) { root = remove(root, key); }

    bool contains(int key) const {
        Node* cur = root;
        while (cur) {
            if (key == cur->key) return true;
            cur = (key < cur->key) ? cur->left : cur->right;
        }
        return false;
    }

    void preorder() { preorder(root); }
    void postorder() { postorder(root); }
};
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    BST bst;
    int idx = 1;
    for (auto &i : nodeinfo) {
        i.push_back(idx++);
    }
    sort(nodeinfo.begin(), nodeinfo.end(), compare);
    for (auto node : nodeinfo) {
        bst.insert(node[0], node[2]);
    }
    bst.postorder();
    bst.preorder();


    return ans;
}
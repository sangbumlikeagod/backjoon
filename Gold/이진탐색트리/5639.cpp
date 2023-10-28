#include <iostream>
#include <fstream>
using namespace std;

struct node{
    int val;
    int size = 1;
    node* parent;
    node* leftchild;
    node* rightchild;
    void insert(node* arg){
        size += 1;
        if (arg -> val >= val){
            if (rightchild == nullptr){
                rightchild = arg;
                // cout << this->val << "뿌잉" << this->rightchild << '\n';
                (*arg).parent = this;
            } else {
                rightchild -> insert(arg);
                // cout << this->val << "뿌잉" << '\n';
                (*arg).parent = this;

                // (*arg->parent) = *this;
            }
        } else {
            if (leftchild == nullptr){
                leftchild = arg;
            } else {
                leftchild -> insert(arg);
            }
        }
    }

};

void dfs(node* nd){
    if (nd->leftchild != nullptr){
        dfs(nd->leftchild);
    }
    if (nd->rightchild != nullptr){
        dfs(nd->rightchild);
    }
    cout << nd->val << '\n'; 
}

int main(){
    node *root = nullptr;
    ifstream cin("5639.txt", ios_base::in);
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    int n;
    while (cin >> n)
    {
        // cout << n << '\n';
        node *a = new node{n};

        if (root == nullptr){
            // cout << '\t' << n << '\n';
            root = a;
        } else {
            // cout << '\t' << n << '\n';
            (*root).insert(a);
        }
    }
    // cout << root -> val;
    // cout << a.val << '\n';

    // cout << a.rightchild->val << '\n';
    // cout << a.rightchild->leftchild->val << '\n';
    // cout << a.size << ' ' << a.rightchild -> size << ' ' << a.rightchild -> leftchild -> size;
    // cout << a.rightchild -> parent -> val;
    dfs(root);
}
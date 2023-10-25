#include <iostream>
#include <fstream>
using namespace std;

struct node{
    int val;
    int size = 1;
    node* leftchild;
    node* rightchild;
    void insert(node* arg){
        size += 1;
        if (arg -> val >= val){
            if (rightchild == nullptr){
                rightchild = arg;
            } else {
                rightchild -> insert(arg);
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

int main(){
    node a = {1};
    cout << a.val;
    node b = {3};
    node c = {2};
    a.insert(&b);
    a.insert(&c);
    node* root = &a;
    cout << a.rightchild->val << '\n';
    cout << a.rightchild->leftchild->val << '\n';
    cout << a.size << ' ' << a.rightchild -> size << ' ' << a.rightchild -> leftchild -> size;
}
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};

int WinMain()
{
    // Windows GUI 응용 프로그램의 진입점 코드를 작성합니다.
    // ...
    int a = 30;
    int *ptr_a;
    ptr_a = &a;
    // printf("%d", *ptr_a);

    TreeNode root;
    root.val = 1;
    TreeNode left;
    left.val = 3;

    root.left = &left;
    TreeNode *ptr;
    ptr = &root;


    TreeNode *ptr_t;
    ptr_t = ptr -> left;
    cout << (*ptr_t).val;

    // cout << ptr -> left -> left; 
    // cout << ptr -> left; 
    // cout << *(ptr -> left).val; <<- 이새끼는 .의 우선순위가 ->보다 높다는 아주 합리적인 아이디어 때문에 안됨
    cout << (*(ptr -> left)).val; 
    // 이렇게 하면 포인터를 객체로 유연하게 바꿔줄 수 있다.

    queue<TreeNode*> q;
    q.push(ptr_t);
    cout << q.front() -> val;
    

    return 0;

}
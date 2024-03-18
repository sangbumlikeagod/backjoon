#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;


int inOrder[100001] = {0};
int postOrder[100001] = {0};
int indexOfInOrderOfValue[100001] = {0};
int indexOfPostOrderOfValue[100001] = {0};
pair<int, int> rangeOfNode[100001] = {};
int N;

vector<int> stack = {};

void preOrder(int node)
{
    cout << node << ' ';

    // 자신의 오른쪽 자식 확인.
    int leftmost = rangeOfNode[node].first;
    int rightmost = rangeOfNode[node].second;

    int indexOfNodeInPostOrder = indexOfPostOrderOfValue[node];
    int indexOfNodeInInOrder = indexOfInOrderOfValue[node];
    int HowManyRightCommand = rightmost - indexOfNodeInInOrder - 1;
    int HowManyLeftCommand = indexOfNodeInInOrder - leftmost;
    // 오른쪽 애가 남았을 경우 자기 바로앞이 바로 자기 오른쪽 자식임
    // cout << '\t' << '\t' <<indexOfNodeInInOrder << '\t' << HowManyLeftCommand << '\t' << node  <<'\t' << HowManyRightCommand << "(" << leftmost << ",  " << rightmost  << ")" << '\n';

    // 있다면 그놈의 범위가 내 범위를 
    if (HowManyRightCommand > 0) {
        stack.push_back(postOrder[indexOfNodeInPostOrder - 1]);
        rangeOfNode[postOrder[indexOfNodeInPostOrder - 1]] = make_pair(indexOfNodeInInOrder + 1, rightmost);
        }
    if (HowManyLeftCommand > 0) {
        stack.push_back(postOrder[indexOfNodeInPostOrder - 1 - HowManyRightCommand]);
        rangeOfNode[postOrder[indexOfNodeInPostOrder - 1 - HowManyRightCommand]] = make_pair(leftmost, indexOfNodeInInOrder);
      
    }
    if (stack.empty()) return;
    int nextNodeValue = stack[stack.size() - 1];
    stack.pop_back();
    preOrder(nextNodeValue); 
}
// 1의 오른쪽에 아무것도 없어야하는데 있는것으로 나오기 때문에 이런일이 일어남 그렇다면 얘가 온전히 자기의 것이 몇개인지 분명히 알아야함
// 범위를 알려줘? 

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("2263.txt", ios_base::in);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int Value = 0;
        cin >> Value;
        inOrder[i] = Value;
        indexOfInOrderOfValue[Value] = i;
    }
    for (int i = 0; i < N; i++)
    {
        int Value = 0;
        cin >> Value;
        indexOfPostOrderOfValue[Value] = i;
        postOrder[i] = Value;
    }
    // 왼쪽의 경우 자신의 인덱스 개수 만큼 커맨드가 있다
    // 오른쪽의 경우 전체 개수 - 자신의 인덱스 개수 - 1 개 만큼 커맨드가 있다
    // 커맨드가 있을때만 스택에 추가할 것
    // 오른쪽 자식이 있다면 먼저 추가하고 왼쪽 자식이 있다면 나중에 추가한다
    int root = postOrder[N - 1];
    // cout << root << '\n';
    rangeOfNode[root] = make_pair(0, N);
    preOrder(root);
    
}
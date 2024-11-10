#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int index;
    int type;
    int fullfill;
    vector<node *> adjList;
    node(int idx)
    {
        index = idx;
        type = 0;
        fullfill = 0;
        adjList = {};
    }
};

void dfs(int &action, int &empty, int &remain, node *root)
{
    cout << action << ' ' << empty << ' ' << remain << ' ' << root->index << '\n';
    if (root->type == 2 && empty)
    {
        remain--;
        empty = 0;
        action += 2;
        int plus = root->adjList.size() == 1 ? 4 : 2;
        for (node *adj : root->adjList)
        {
            if (adj->fullfill == adj->type)
                continue;

            adj->fullfill += plus;
            dfs(action, empty, remain, adj);
        }
    }
    else if (root->type == root->fullfill)
    {
        // 제거 가능하다는 뜻
        if (root->type == 3)
        {
            remain--;
            empty = 0;
            action++;
            for (node *adj : root->adjList)
            {
                if (adj->fullfill == adj->type)
                    continue;

                adj->fullfill += 2;
                dfs(action, empty, remain, adj);
            }
        }
        else if (root->type == 4)
        {
            empty = 1;
            remain--;
            action++;
        }
    }
    else if (root->type == 3 && empty)
    {
        root->fullfill += 2;
        empty = 0;
        action += 2;
        remain--;
        for (node *adj : root->adjList)
        {
            if (adj->fullfill == adj->type)
                continue;

            adj->fullfill += 2;
            dfs(action, empty, remain, adj);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("32070.txt", ios_base::in);
    vector<node *> cups(200001, nullptr);

    int N;
    cin >> N;
    int remain = N;
    int empty = 1;
    int action = 0;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
        {
            remain--;
            continue;
        }
        if (!cups[a])
        {
            cups[a] = new node(a);
        }
        if (!cups[b])
        {
            cups[b] = new node(b);
        }
        cups[a]->type += 1;
        cups[a]->fullfill += 1;

        cups[b]->type += 2;

        if (!cups[a]->adjList.size() || cups[a]->adjList[0]->index != b)
        {
            cups[a]->adjList.push_back(cups[b]);
        }
    }

    // cout << "sex" << '\n';
    node *start = nullptr;
    for (int idx = 1; idx <= N; idx++)
    {
        node *adj = cups[idx];
        if (!adj)
        {
            continue;
        }

        if (adj->type == 2 || adj->type != adj->fullfill)
        {
            empty = 1;
            dfs(action, empty, remain, adj);
        }
    }

    if (remain)
    {
        cout << -1;
    }
    else
    {
        cout << action;
    }
}
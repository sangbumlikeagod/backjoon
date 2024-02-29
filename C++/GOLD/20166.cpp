#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
using namespace std;


int dx[8] = {1, 0, -1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int M;
int N;
int K;
char jigoku[10][10] = {0};

    struct Node
    {
        char chr;
        int count;
        Node(char chr) : chr(chr), count(1) {};
    };

    class Trie
    {
        public:
        Node* Head;
        vector<pair<int, int>> cords;
        vector<Trie*> child;

        Trie(char chr, int i, int j) : cords({}), child({}), Head(new Node(chr)) {
            cords.push_back(make_pair(i, j));
        };
        long long search(string s){
                    
            if (s.length() == 0) return Head->count;

            for (Trie* i : child)
            {
                if (i->Head->chr == s[0])
                {
                    return i->search(s.substr(1, s.length() - 1));
                }
            }
            for (pair<int, int> j : cords)
            {
                for (int k = 0; k < 8; k++)
                {
                    int nx = (j.first + dx[k]);
                    int ny = (j.second + dy[k]);
                    if (nx < 0)
                    {
                        nx += M;
                    }
                    else if ( nx == M )
                    {
                        nx -= M;
                    }
                    if ( ny < 0 )
                    {
                        ny += N;
                    }
                    else if ( ny == N )
                    {
                        ny -= N;
                    }
                    this->insert(jigoku[nx][ny], nx, ny);                
                }   
            }
            for (Trie* i : child)
            {
                if (i->Head->chr == s[0])
                {
                    return i->search(s.substr(1, s.length() - 1));
                }
            }
            return 0;
        };
        void insert(char s, int x, int y){
            for (Trie* i : child)
            {
                if (i->Head->chr == s)
                {
                    i->cords.push_back(make_pair(x, y));
                    i->Head->count++;
                    return;
                }
            }
            this->child.push_back(new Trie(s, x, y));
        };
    };

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("20166.txt", ios_base::in);

    cin >> M >> N >> K;
    Trie* head = new Trie(' ', 1000, 1000);
    for (int i = 0; i < M; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            jigoku[i][j] = s[j];
            head->insert(jigoku[i][j], i, j);
        }   
    }

    for (int k = 0; k < K; k++)
    {
        string s;
        cin >> s;
        cout << head->search(s) << '\n';
    }

    // cout << '\n' << '\n';
}

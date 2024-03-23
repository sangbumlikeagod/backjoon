#include <map>
#include <unordered_map>
using namespace std;

struct node
{
    int key;
    int val;
    node *before;
    node *next;
    node(int key, int val) : key(key), val(val), before(nullptr), next(nullptr){};
};

class LinkedList
{
public:
    int metaTotalNode;
    int metaMAXNUM;
    node *head;
    node *tail;
    void popHead()
    {

        head->next->next->before = head;
        head->next = head->next->next;

        metaTotalNode--;
    }
    void pushTail(node *node)
    {
        tail->before->next = node;
        node->before = tail->before;
        node->next = tail;
        tail->before = node;
        metaTotalNode++;
    }

    LinkedList() : metaMAXNUM(0), metaTotalNode(0), head(nullptr), tail(nullptr)
    {
        head = new node(-1, -1);
        tail = new node(300001, 300001);
        head->next = tail;
        tail->before = head;
    };
    LinkedList(int maxC) : metaMAXNUM(maxC), metaTotalNode(0), head(nullptr), tail(nullptr)
    {
        head = new node(-1, -1);
        tail = new node(300001, 300001);
        head->next = tail;
        tail->before = head;
    };
};

class LRUCache
{
    LinkedList list;
    unordered_map<int, node *> cacheMapping;

public:
    LRUCache(int capacity)
    {
        list.metaMAXNUM = capacity;
    }

    int get(int key)
    {
        // 없으면
        if (cacheMapping.find(key) == cacheMapping.end())
        {
            return -1;
        }
        else
        {
            // 있으면
            int ans = cacheMapping[key]->val;
            node *tmpNode = cacheMapping[key];
            // cout << "자 이제부터 여기서 문제있는 놈을 찾아내겠어'\n";
            tmpNode->before->next = tmpNode->next;
            // cout << "\t" << tmpNode->before->key << "이건 반드시 -1이어야함" << '\n';
            // cout << "\t\t" << tmpNode->next->key << "얘도 뭐가 나와야해\n";
            tmpNode->next->before = tmpNode->before;
            tmpNode->next = nullptr;
            tmpNode->before = nullptr;
            list.metaTotalNode--;
            // cout << "\t\t\t 이제 바뀐점이 보여야함" << list.head -> next -> key << '\n';
            list.pushTail(tmpNode);
            return ans;
        }
    }

    void put(int key, int value)
    {
        cout << list.metaTotalNode << '\n';
        if (cacheMapping.find(key) == cacheMapping.end())
        {
            // 없다면
            cacheMapping[key] = new node(key, value);
            if (list.metaTotalNode == list.metaMAXNUM)
            {
                int willBeErased = list.head->next->key;
                // cout << "꽉 찼 다 " << willBeErased << '\n';
                list.popHead();
                cacheMapping.erase(willBeErased);
            }
            list.pushTail(cacheMapping[key]);
        }
        else
        {
            cacheMapping[key]->val = value;
            node *tmpNode = cacheMapping[key];
            tmpNode->before->next = tmpNode->next;
            tmpNode->next->before = tmpNode->before;
            tmpNode->next = nullptr;
            tmpNode->before = nullptr;
            list.metaTotalNode--;
            list.pushTail(tmpNode);
        }
    }
};

#include <map>
#include <unordered_map>
using namespace std;

struct node
{
    int key;
    int val;
    node* before;
    node* next;
    node(int key, int val) : key(key), val(val), before(nullptr), next(nullptr){};
};

class LinkedList
{
    public:
    int metaTotalNode;
    int metaMAXNUM;
    node* head;
    node* tail;
    void popHead()
    {
        if (head->next)
        {
            head->next->before = nullptr;
        }
        
        head = head->next;
        
        metaTotalNode--;
    }
    void pushTail(node* node)
    {
        if (head == nullptr)
        {
            head = node;
            tail = node;
            metaTotalNode++;
            return;
        }
        if (tail)
        {
            tail->next = node; 
        }
        node->before = tail;
        metaTotalNode++;
    }

    LinkedList() : metaMAXNUM(0) , metaTotalNode(0), head(nullptr), tail(nullptr) {}; 
    LinkedList(int maxC) : metaMAXNUM(maxC) , metaTotalNode(0), head(nullptr), tail(nullptr) {}; 
};


class LRUCache {
     LinkedList list;
     unordered_map<int, node*> cacheMapping;
     
public:
    LRUCache(int capacity) {
        list.metaMAXNUM = capacity; 
    }
    
    int get(int key) {
        // 없으면
        if (cacheMapping.find(key) == cacheMapping.end())
        {
            return -1;
        }
        else
        {   
            // 있으면
            int ans = cacheMapping[key]->val;
            list.metaTotalNode--;
            if (cacheMapping[key]->before)
            {
                cacheMapping[key]->before->next =  cacheMapping[key]->next;
            }
            if (cacheMapping[key]->next)
            {
                cacheMapping[key]->next->before = cacheMapping[key]->before;
            }
            if (list.head == cacheMapping[key]) 
            {
                list.head = list.head->next;
            }
            if (list.tail == cacheMapping[key])
            {
                list.tail = list.tail->before;
            }

            list.pushTail(cacheMapping[key]);
            return ans;
        }
    }
    
    void put(int key, int value) {
        if (cacheMapping.find(key) == cacheMapping.end())
        {
            cacheMapping[key] = new node(key, value);
            if (list.metaMAXNUM == list.metaTotalNode)
            {
                cacheMapping.erase(list.head->key);
                list.popHead();
            }
            list.pushTail(cacheMapping[key]);
        } 
        else 
        {
            cacheMapping[key]->val = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
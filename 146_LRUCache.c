#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int key;
    int val;
    struct Node* next;
    struct Node* prev; 
} NODE;

typedef struct {
    int capacity;
    int size;
    NODE* head;
    NODE* tail;
    NODE* map[10001];
} LRUCache;

void removeNode(LRUCache* obj, NODE* node)
{
    if (node->prev)
        node->prev->next = node->next;
    else
        obj->head = node->next;  // node was head

    if (node->next)
        node->next->prev = node->prev;
    else
        obj->tail = node->prev;  // node was tail

    node->prev = NULL;
    node->next = NULL;
}

void insertAtFront(LRUCache* obj, NODE* node)
{
    node->prev = NULL;
    node->next = obj->head;

    if (obj->head)
        obj->head->prev = node;
    else
        obj->tail = node; // empty list

    obj->head = node;
}

LRUCache* lRUCacheCreate(int capacity) 
{
    LRUCache* lru = calloc(1,sizeof(LRUCache));
    lru->capacity = capacity;    
    return lru;
}

int lRUCacheGet(LRUCache* obj, int key) 
{
    NODE* node = obj->map[key];
    if(node == NULL) return -1;

    removeNode(obj,node);
    insertAtFront(obj,node);

    return node->val;
}

void lRUCachePut(LRUCache* obj, int key, int value) 
{
    if(obj->capacity == 0) return;   
    NODE* node = obj->map[key];

    if(node) {
        node->val = value;
        removeNode(obj,node);
        insertAtFront(obj,node);        
        return;
    }

    if(obj->size == obj->capacity) {
        NODE* oldNode = obj->tail;
        obj->map[oldNode->key] = NULL;
        removeNode(obj,oldNode);
        free(oldNode);
        obj->size--;
    }

    // Add the new node
    NODE* newn = calloc(1,sizeof(NODE));
    newn->key = key;
    newn->val = value;

    insertAtFront(obj,newn);
    obj->map[key] = newn;
    obj->size++;
}

void lRUCacheFree(LRUCache* obj) 
{
    NODE* curr = obj->head;
    while(curr) {
        NODE* tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/

int main()
{

    return 0;
}
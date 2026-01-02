#include<stdio.h>
#include<stdlib.h>

#define SIZE 1000

typedef struct Node {
    int key;
    int val;
    struct Node* next;
} NODE;

typedef struct { 
    NODE* bucket[SIZE];
} HASHMAP;

HASHMAP* myHashMapCreate() 
{
    HASHMAP* map = calloc(1, sizeof(HASHMAP));
    if(map == NULL) return NULL;
    return map;
}

int hash(int key)
{
    return key % SIZE;
}

NODE* createNode(int key,int val) 
{
    NODE* new_node = malloc(sizeof(NODE));
    if(new_node == NULL) return NULL;

    new_node->key = key;
    new_node->val = val;
    new_node->next = NULL;

    return new_node;
}

void myHashMapPut(HASHMAP* obj, int key, int value) 
{
    int hash_key = hash(key);
    NODE* _head = obj->bucket[hash_key];

    if(_head == NULL) {
        obj->bucket[hash_key] = createNode(key,value);
    } else {
        NODE* _prev = NULL;
        while(_head) {
            if(_head->key == key) {
                _head->val = value;
                return;
            }
            _prev = _head;
            _head = _head->next;
        }
        _prev->next = createNode(key,value);
    }
}

int myHashMapGet(HASHMAP* obj, int key) 
{
    int hash_key = hash(key);

    NODE* _head = obj->bucket[hash_key];
    if(_head == NULL) return -1;

    while(_head) {
        if(_head->key == key) return _head->val;
        _head = _head->next;
    }
    return -1;
}

void myHashMapRemove(HASHMAP* obj, int key) 
{
    int hash_key = hash(key);

    NODE* _curr = obj->bucket[hash_key];
    if(_curr == NULL) return;
    NODE* _prev = NULL;

    while(_curr) {
        if(_curr->key == key) {
            if(_prev == NULL) {
                obj->bucket[hash_key] = _curr->next;
            } else {
                _prev->next = _curr->next;
            }
            free(_curr);
            return;
        }
        _prev = _curr;
        _curr = _curr->next;
    }
}

void myHashMapFree(HASHMAP* obj) 
{
    if(obj == NULL) return;

    for(int i = 0; i < SIZE; i++)
    {
        NODE* _curr = obj->bucket[i];
        while(_curr)
        {
            NODE* _next = _curr->next;
            free(_curr);
            _curr = _next;
        }
    }
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/

int main()
{
    return 0;
}
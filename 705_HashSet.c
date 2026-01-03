#include<stdio.h>
#include<stdlib.h>

#define SIZE 100003

typedef struct Node 
{
    int key;
    struct Node* next;
} NODE;

typedef struct 
{
    NODE* bucket[SIZE];
} MyHashSet;

NODE* createNode(int key)
{
    NODE* newn = (NODE*)malloc(sizeof(NODE));
    if(newn == NULL) return NULL;
    newn->key = key;
    newn->next = NULL;

    return newn;
}

int Hash(int key)
{
    return key % SIZE;
}

MyHashSet* myHashSetCreate() 
{
    MyHashSet* set = (MyHashSet*)calloc(1, sizeof(MyHashSet));
    if(set == NULL) return NULL;
    return set;
}

void myHashSetAdd(MyHashSet* obj, int key) 
{
    int hash_key = Hash(key);
    NODE* _curr = obj->bucket[hash_key];
    NODE* _prev = NULL;

    if(_curr == NULL) {
        obj->bucket[hash_key] = createNode(key);
    } else {
        while(_curr) {
            if(_curr->key == key) return;
            _prev = _curr;
            _curr = _curr->next;
        }
        _prev->next = createNode(key);
    }
}

void myHashSetRemove(MyHashSet* obj, int key) 
{
    int hash_key = Hash(key);
    NODE* _curr = obj->bucket[hash_key];
    NODE* _prev = NULL;

    while(_curr) 
    {
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

bool myHashSetContains(MyHashSet* obj, int key) 
{
    int hash_key = Hash(key);
    NODE* _curr = obj->bucket[hash_key];

    while(_curr) 
    {
        if(_curr->key == key) {
            return true;
        }
        _curr = _curr->next;
    }    
    return false;   
}

void myHashSetFree(MyHashSet* obj) 
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
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/

int main()
{
    return 0;
}
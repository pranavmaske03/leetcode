#include<iostream>
#include<vector>

using namespace std;

class MyHashSet {
    int n = 10000;
    vector<unordered_set<int>> arr;
    
    public:
        MyHashSet() {
            arr.resize(n);
        }
        
        void add(int key) {
            arr[key % n].insert(key);
        }
        
        void remove(int key) {
            arr[key % n].erase(key);
        }
        
        bool contains(int key) {
            return arr[key % n].count(key) > 0;
        }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main() 
{

    return 0;
}
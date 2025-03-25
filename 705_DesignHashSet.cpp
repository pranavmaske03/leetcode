#include<iostream>
#include<vector>

using namespace std;

class MyHashSet {
    public:
        int n = 10000;
        vector<vector<int>> arr;
        
        MyHashSet() {
            arr.resize(n);
        }
        
        void add(int key) {
            int idx = key % n;
            for(int x : arr[idx]) {
                if (x == key) return;
            }
            arr[idx].push_back(key);
        }
        
        void remove(int key) {
            int idx = key % n;
            for (int i = 0; i < arr[idx].size(); i++) {
                if (arr[idx][i] == key) {
                    arr[idx].erase(arr[idx].begin() + i);
                    return;
                }
            }
        }
        
        bool contains(int key) {
            int idx = key % n;
            for (int x : arr[idx]) {
                if (x == key) return true;
            }
            return false;
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
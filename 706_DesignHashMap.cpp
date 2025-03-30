#include<iostream>
#include<vector>
using namespace std;

class MyHashMap {
    public:
        unordered_map<int, int> m1;

        MyHashMap() {}

        void put(int key, int value) {
            m1[key] = value;
        }

        int get(int key) {
            return m1.count(key) ? m1[key] : -1;
        }

        void remove(int key) {
            m1.erase(key);
        }
};


int main() 
{
    
    return 0;
}
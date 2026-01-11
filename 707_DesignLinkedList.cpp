#include<iostream>
using namespace std;


class MyLinkedList 
{
    private:
        typedef struct Node {
            int val;
            Node *next;
            Node *prev;
           Node(int _val, Node* _next, Node* _prev) : val(_val), next(_next), prev(_prev) {}
        } NODE,*PNODE;

    public:
        PNODE head;
        PNODE tail;
        int nodeCount;

        MyLinkedList() 
        {
            this->head = nullptr;
            this->tail = nullptr;
            nodeCount = 0;
        }
        
        int get(int index) 
        {
            if(index < 0 || index >= this->nodeCount) return -1;

            PNODE _curr = this->head;
            int currCount = 0;

            while(_curr) {
                if(currCount == index) return _curr->val;
                currCount++;
                _curr = _curr->next;
            }
            return -1;
        }
        
        void addAtHead(int val) 
        {
            PNODE newn = new NODE(val, nullptr, nullptr);

            if(this->head == nullptr && this->tail == nullptr) {
                this->head = newn;
                this->tail = newn;
            } else {
                newn->next = this->head;
                this->head->prev = newn;
                this->head = newn;
            }
            this->nodeCount++;
        }
        
        void addAtTail(int val) 
        {
            PNODE newn = new NODE(val, nullptr, nullptr);

            if(this->head == nullptr && this->tail == nullptr) {
                this->head = newn;
                this->tail = newn;
            } else {
                newn->prev = this->tail;
                this->tail->next = newn;
                this->tail = newn;
            }
            this->nodeCount++;
        }
        
        void addAtIndex(int index, int val) 
        {
            if(index < 0 || index > this->nodeCount) return;

            if(index == 0) {
                addAtHead(val);
            } else if(index == this->nodeCount) {
                addAtTail(val);
            } else {
                PNODE _curr = this->head;
                PNODE newn = new NODE(val, nullptr, nullptr);
                
                for(int i = 0; i < index - 1; i++)
                {
                    _curr = _curr->next;
                }
                newn->next = _curr->next;
                _curr->next->prev = newn;

                newn->prev = _curr;
                _curr->next = newn;

                nodeCount++;
            }
        }
        
        void deleteAtIndex(int index) 
        {
            if(index < 0 || index >= this->nodeCount) return;

            if(index == 0) {                
                PNODE temp = this->head;
                if(this->head == this->tail) {
                    this->head = this->tail = nullptr;
                } else {
                    this->head = this->head->next;
                    this->head->prev = nullptr;
                }
                delete temp;

            } else if(index == this->nodeCount - 1) {
                PNODE temp = this->tail;
                this->tail = tail->prev;
                delete this->tail->next;
                this->tail->next = nullptr;

            } else {
                PNODE _curr = this->head;

                for(int i = 0; i < index - 1; i++)
                {
                    _curr = _curr->next;
                }

                PNODE node = _curr->next;
                _curr->next = _curr->next->next;
                _curr->next->prev = _curr;
                delete node;
            }
            nodeCount--;
        }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
 
int main()
{

    return 0;
}
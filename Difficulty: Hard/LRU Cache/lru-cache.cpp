class Node{
public: 
    int key, value;
    Node* next;
    Node* prev;
    
    Node() {
        key = value = -1;
        next = prev = nullptr;
    }
    
    Node(int key_, int value_) {
        key = key_;
        value = value_;
        next = prev = nullptr;
    }
};

class LRUCache {
  private:
    unordered_map<int, Node*> mpp;
    int cap;
    Node* head, *tail; // dummy head, tail
    
    void deleteTail(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    void insertAfterHead(Node* node) {
        Node* nextNode = head->next;
        head->next = node;
        nextNode->prev = node;
        node->next = nextNode;
        node->prev = head;
    }
  public:
    LRUCache(int cap_) {
        // code here
        cap = cap_;
        mpp.clear();
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        // if key not found
        if(mpp.find(key) == mpp.end()) {
            return -1;
        }
        
        Node* node = mpp[key];
        
        deleteTail(node);
        insertAfterHead(node);
        
        return node->value;
    }

        
    void put(int key, int value) {
        // if already present : 
        if(mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->value = value;
            
            deleteTail(node);
            insertAfterHead(node);
            return;
        }
        
        // if present but capacity is full : 
        if(mpp.size() == cap) {
            Node* nodeToDelete = tail->prev;
            mpp.erase(nodeToDelete->key);
            deleteTail(nodeToDelete);
            delete nodeToDelete;
        }
        
        Node* newNode = new Node(key, value);
        mpp[key] = newNode;
        insertAfterHead(newNode);
    }
};




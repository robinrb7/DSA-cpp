class LRUCache {
    
public:
    class ListNode{
        public:
            int key, value;
            ListNode* prev;
            ListNode* next;

            ListNode(int key, int value){
                this->key = key;
                this->value = value;
                this->prev = NULL;
                this->next = NULL;
            }

    };

    unordered_map<int,ListNode*> nodeMap;
    ListNode* head = new ListNode(-1,-1);
    ListNode* tail = new ListNode(-1,-1);
    int mapCapacity;

    LRUCache(int capacity) {
        mapCapacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(nodeMap.find(key)== nodeMap.end()) return -1;

        deleteNode(nodeMap[key]);
        insertAfterHead(nodeMap[key]);

        return nodeMap[key]->value;
    }
    
    void put(int key, int value) {
        if(nodeMap.find(key)!=nodeMap.end()){
            nodeMap[key]->value = value;
            deleteNode(nodeMap[key]);
            insertAfterHead(nodeMap[key]);
        }
        else{
            if(nodeMap.size()==mapCapacity){
                ListNode* nodeToDelete = tail->prev;
                deleteNode(nodeToDelete);
                nodeMap.erase(nodeToDelete->key);
                delete nodeToDelete;     
            }
            
            ListNode* newNode = new ListNode(key,value);
            insertAfterHead(newNode);
            nodeMap[key] = newNode;
        }
    }

    void insertAfterHead(ListNode* node){
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }
    void deleteNode(ListNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
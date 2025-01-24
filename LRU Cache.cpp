class Node {
public:
    int key, value;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head; 
    Node* tail;

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void addNodeToFront(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(-1, -1); 
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; // Key not found
        }

        // Move the accessed node to the front of the list
        Node* node = cache[key];
        removeNode(node);
        addNodeToFront(node);

        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
           
            Node* node = cache[key];
            node->value = value;

            removeNode(node);
            addNodeToFront(node);
        } else {
            if (cache.size() == capacity) {
                // If capacity is full, remove the least recently used node
                Node* lru = tail->prev; // Node before the tail is LRU
                removeNode(lru);
                cache.erase(lru->key);
                delete lru; // Free memory
            }

            // Create a new node and add it to the front
            Node* newNode = new Node(key, value);
            addNodeToFront(newNode);
            cache[key] = newNode;
        }
    }

    // Destructor to free allocated memory
    ~LRUCache() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};


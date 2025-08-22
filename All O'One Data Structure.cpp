class AllOne {
    // Definition of the node structure representing a frequency bucket in the doubly linked list
    struct node {
        unordered_set<string> keys;  // Set of keys with the same frequency
        int freq;                    // Frequency of the keys
        node *next, *prev;           // Pointers to the next and previous nodes
    };
    
    node *head, *tail;               // Pointers to the dummy head and tail nodes of the list
    unordered_map<string, node*> keyStore; // Map to store the mapping of keys to their respective frequency node
    
    // Helper function to create a new node with a given key and frequency
    node* getNewNode(string key, int freq) {
        node* newnode = new node;
        newnode->keys.insert(key);  // Add the key to the new node's key set
        newnode->freq = freq;       // Set the node's frequency
        newnode->next = newnode->prev = NULL; // Initialize pointers to NULL
        return newnode;
    }
    
    // Helper function to remove a node from the doubly linked list
    void removeNode(node* curr) {
        curr->prev->next = curr->next;  // Update the previous node's next pointer
        curr->next->prev = curr->prev;  // Update the next node's prev pointer
        curr->next = curr->prev = NULL; // Isolate the current node
        delete curr;                    // Delete the node to free memory
    }
    
    // Helper function to insert a new node to the right of a given node
    void add_right_node(node* curr, string key, int freq) {
        node *newnode = getNewNode(key, freq);  // Create a new node with the key and frequency
        newnode->next = curr->next;             // Link the new node's next pointer to current's next
        newnode->prev = curr;                   // Link the new node's prev pointer to the current node
        curr->next->prev = newnode;             // Update the next node's prev pointer to the new node
        curr->next = newnode;                   // Update the current node's next pointer to the new node
    }
    
public:
    // Constructor to initialize the data structure
    AllOne() {
        head = getNewNode("", -10);   // Create a dummy head node with a sentinel frequency (-10)
        tail = getNewNode("", -10);   // Create a dummy tail node with a sentinel frequency (-10)
        head->next = tail;            // Link the head's next pointer to the tail
        tail->prev = head;            // Link the tail's prev pointer to the head
    }
    
    // Increases the count of a key by 1
    void inc(string key) {
        if (keyStore.count(key)) {    // If the key is already present
            node *curr = keyStore[key];  // Get the node where the key currently exists
            curr->keys.erase(key);       // Remove the key from the current node's key set
            
            // If the next node has the correct frequency, add the key there
            if (curr->next->freq == curr->freq + 1) {
                curr->next->keys.insert(key);
            } else {
                // Otherwise, create a new node for the increased frequency
                add_right_node(curr, key, curr->freq + 1);
            }
            
            keyStore[key] = curr->next;  // Update the key's position in the keyStore map
            
            // If the current node is empty, remove it
            if (curr->keys.empty()) removeNode(curr);
        } else {  // If the key is not present
            // If there's already a node with frequency 1 after head, add the key there
            if (head->next->freq == 1) {
                head->next->keys.insert(key);
            } else {
                // Otherwise, create a new node with frequency 1
                add_right_node(head, key, 1);
            }
            keyStore[key] = head->next;  // Update keyStore to point to the new node
        }
    }
    
    // Decreases the count of a key by 1
    void dec(string key) {
        node *curr = keyStore[key];   // Get the node where the key currently exists
        curr->keys.erase(key);        // Remove the key from the current node's key set
        
        if (curr->freq == 1) {  // If the key's frequency becomes zero
            keyStore.erase(key);  // Remove the key from keyStore
        } else {
            // If there's already a node with the correct frequency before the current node
            if (curr->prev->freq == curr->freq - 1) {
                curr->prev->keys.insert(key);  // Move the key to the previous node
            } else {
                // Otherwise, create a new node for the decreased frequency
                add_right_node(curr->prev, key, curr->freq - 1);
            }
            keyStore[key] = curr->prev;  // Update the key's position in the keyStore map
        }
        
        // If the current node is empty, remove it
        if (curr->keys.empty()) removeNode(curr);
    }
    
    // Returns one of the keys with the maximum frequency
    string getMaxKey() {
        if (tail->prev == head) return "";  // If the list is empty, return an empty string
        return *(tail->prev->keys.begin()); // Return any key from the node with the highest frequency
    }
    
    // Returns one of the keys with the minimum frequency
    string getMinKey() {
        if (head->next == tail) return "";  // If the list is empty, return an empty string
        return *(head->next->keys.begin()); // Return any key from the node with the lowest frequency
    }
};

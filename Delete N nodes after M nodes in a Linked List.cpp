class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        Node* current = head;
        
        while(current != NULL) {
            //Skip m nodes
            for(int i = 1; i < m && current != NULL; i++) {
                current = current->next;
            }
            
            //reached end? => break loop
            if(current == NULL) break;
            
            //Delete n nodes
            Node* temp = current->next;
            for(int i = 0; i<n && temp != NULL; i++){
                Node* nextTemp = temp->next;
                delete temp;    // Deallocate memory for the node to be deleted
                temp = nextTemp;    
            }
            current->next = temp;
            
            current = temp; 
        }
        return head;
    }
};

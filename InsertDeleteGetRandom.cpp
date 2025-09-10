#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
using namespace std;

class RandomizedSet {
private:
    // Vector to store the actual values - allows O(1) random access
    vector<int> nums;
    
    // HashMap to store value -> index mapping for O(1) lookup
    unordered_map<int, int> valToIndex;

public:
    // Constructor: Initialize the data structure
    RandomizedSet() {
        // Seed the random number generator
        srand(time(nullptr));
    }
    
    // Insert operation: Add val to set if not present
    // Returns true if val was inserted, false if already present
    bool insert(int val) {
        // Step 1: Check if val already exists using hashmap
        if (valToIndex.find(val) != valToIndex.end()) {
            return false; // Value already exists
        }
        
        // Step 2: Add val to the end of vector
        nums.push_back(val);
        
        // Step 3: Store the mapping of val -> its index in vector
        // Index is size-1 since we just added to the end
        valToIndex[val] = nums.size() - 1;
        
        return true; // Successfully inserted
    }
    
    // Remove operation: Remove val from set if present
    // Returns true if val was removed, false if not present
    bool remove(int val) {
        // Step 1: Check if val exists in the set
        if (valToIndex.find(val) == valToIndex.end()) {
            return false; // Value doesn't exist
        }
        
        // Step 2: Get the index of val to be removed
        int indexToRemove = valToIndex[val];
        
        // Step 3: Get the last element in the vector
        int lastElement = nums.back();
        
        // Step 4: Move the last element to the position of element to be removed
        // This avoids shifting all elements (which would be O(n))
        nums[indexToRemove] = lastElement;
        
        // Step 5: Update the hashmap for the moved element
        // The last element now has a new index (indexToRemove)
        valToIndex[lastElement] = indexToRemove;
        
        // Step 6: Remove the last element from vector (now it's duplicated)
        nums.pop_back();
        
        // Step 7: Remove the mapping from hashmap
        valToIndex.erase(val);
        
        return true; // Successfully removed
    }
    
    // GetRandom operation: Return a random element from the set
    // Each element has equal probability of being selected
    int getRandom() {
        // Step 1: Generate a random index between 0 and size-1
        int randomIndex = rand() % nums.size();
        
        // Step 2: Return the element at that random index
        return nums[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

/*
APPROACH EXPLANATION:

The key insight is to use TWO data structures together:
1. Vector (Dynamic Array): For O(1) random access and storage
2. HashMap (Unordered Map): For O(1) value lookup and index tracking

WHY THIS COMBINATION WORKS:

1. INSERT Operation:
   - HashMap provides O(1) lookup to check if element exists
   - Vector provides O(1) insertion at the end
   - HashMap stores value->index mapping for future operations

2. REMOVE Operation:
   - HashMap provides O(1) lookup to find element's index
   - Instead of shifting elements (O(n)), we use a clever trick:
     * Move the last element to the position of element to be removed
     * Update the moved element's index in hashmap
     * Remove the last element (O(1) operation)
   - This maintains the vector's compactness without O(n) shifting

3. GETRANDOM Operation:
   - Vector allows O(1) random access by index
   - Generate random index and return element at that position
   - All elements have equal probability since vector is compact

TIME COMPLEXITY ANALYSIS:

1. INSERT: O(1) average
   - HashMap lookup: O(1) average
   - Vector push_back: O(1) amortized
   - HashMap insertion: O(1) average

2. REMOVE: O(1) average  
   - HashMap lookup: O(1) average
   - Vector element access: O(1)
   - Vector pop_back: O(1)
   - HashMap update and erase: O(1) average

3. GETRANDOM: O(1)
   - Random number generation: O(1)
   - Vector random access: O(1)

SPACE COMPLEXITY: O(n) where n is the number of elements
- Vector stores n elements: O(n)
- HashMap stores n key-value pairs: O(n)

EXAMPLE WALKTHROUGH:
Initial: nums=[], valToIndex={}

insert(1): nums=[1], valToIndex={1:0} → return true
remove(2): 2 not found → return false  
insert(2): nums=[1,2], valToIndex={1:0, 2:1} → return true
getRandom(): random from [1,2] → could return 1 or 2
remove(1): 
  - Find 1 at index 0
  - Move 2 (last element) to index 0
  - nums=[2], valToIndex={2:0}
  - return true
insert(2): 2 already exists → return false
getRandom(): only 2 exists → return 2

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Create adjacency list to represent the graph
        // Each index represents a course, and the vector at that index contains courses that depend on it
        vector<vector<int>> graph(numCourses);
        
        // Step 2: Create indegree array to track how many prerequisites each course has
        // indegree[i] = number of courses that must be taken before course i
        vector<int> indegree(numCourses, 0);
        
        // Step 3: Build the graph and calculate indegrees
        for (int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];        // Course that has a prerequisite
            int prerequisite = prerequisites[i][1];  // The prerequisite course
            
            // Add an edge from prerequisite to course
            graph[prerequisite].push_back(course);
            
            // Increment indegree of the course (it has one more prerequisite)
            indegree[course]++;
        }
        
        // Step 4: Find all courses with no prerequisites (indegree = 0)
        // These courses can be taken immediately
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Step 5: Process courses using BFS (Kahn's Algorithm for topological sort)
        vector<int> result;
        
        while (!q.empty()) {
            // Take a course with no remaining prerequisites
            int currentCourse = q.front();
            q.pop();
            
            // Add this course to our result (we can take it now)
            result.push_back(currentCourse);
            
            // For all courses that depend on the current course
            for (int i = 0; i < graph[currentCourse].size(); i++) {
                int nextCourse = graph[currentCourse][i];
                
                // Reduce the indegree (one prerequisite is now satisfied)
                indegree[nextCourse]--;
                
                // If this course now has no more prerequisites, we can take it
                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        
        // Step 6: Check if we were able to take all courses
        // If result size equals numCourses, we found a valid ordering
        // If not, there's a cycle and it's impossible to complete all courses
        if (result.size() == numCourses) {
            return result;
        } else {
            return vector<int>(); // Return empty vector if impossible
        }
    }
};

/*
APPROACH EXPLANATION:

This problem is solved using Topological Sorting with Kahn's Algorithm.

Key Concepts:
1. Directed Graph: Each prerequisite relationship forms a directed edge
2. Indegree: Number of incoming edges to a node (number of prerequisites for a course)
3. Topological Sort: Linear ordering of vertices where for every directed edge (u,v), u comes before v

Algorithm Steps:
1. Build adjacency list representation of the graph
2. Calculate indegree for each course
3. Start with courses having 0 indegree (no prerequisites)
4. Process courses in BFS manner:
   - Take a course with 0 indegree
   - Add it to result
   - Reduce indegree of all dependent courses
   - Add newly available courses (indegree becomes 0) to queue
5. If we process all courses, return the order; otherwise return empty array

Time Complexity: O(V + E) where V = numCourses, E = prerequisites.length
Space Complexity: O(V + E) for the graph and auxiliary data structures

Example Walkthrough for numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]:
1. Graph: 0->[1,2], 1->[3], 2->[3], 3->[]
2. Indegree: [0,1,1,2]
3. Start with course 0 (indegree=0)
4. Take 0, reduce indegree of 1,2 to [0,0,2]
5. Take 1,2, reduce indegree of 3 to 0
6. Take 3
7. Result: [0,1,2,3] or [0,2,1,3] (both valid)
*/

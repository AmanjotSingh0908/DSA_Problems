class NumArray {
public:
    struct segmenttree {
        vector<int> st;
        int n;

        void init(int n) {
            this->n = n;
            st.resize(4 * n, 0);
        }

        // Building the segment tree
        void build(int start, int ending, int node, vector<int>& v) {
            // Base case: leaf node
            if (start == ending) {
                st[node] = v[start];
                return;
            }

            int mid = (start + ending) / 2;
            // Left subtree (start, mid)
            build(start, mid, 2 * node + 1, v);
            // Right subtree (mid+1, ending)
            build(mid + 1, ending, 2 * node + 2, v);

            // Combine the results
            st[node] = st[2 * node + 1] + st[2 * node + 2];
        }
           
        // Update function
        void update(int start, int ending, int node, int index, int value) {
            // Base case: leaf node
            if (start == ending) {
                st[node] = value;
                return;
            }

            int mid = (start + ending) / 2;
            if (index <= mid) {
                // Left subtree
                update(start, mid, 2 * node + 1, index, value);
            } else {
                // Right subtree
                update(mid + 1, ending, 2 * node + 2, index, value);
            }

            // After updating, recalculate the value at the current node
            st[node] = st[2 * node + 1] + st[2 * node + 2];
        }

        // Public update function
        void update(int index, int val) {
            update(0, n - 1, 0, index, val);
        }

        // Query function to get the sum in the range [l, r]
        int query(int start, int ending, int l, int r, int node) {
            if (start > r || ending < l) {
                // No overlap
                return 0;
            }

            // Complete overlap
            if (start >= l && ending <= r) {
                return st[node];
            }

            // Partial overlap
            int mid = (start + ending) / 2;
            int q1 = query(start, mid, l, r, 2 * node + 1);
            int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

            return q1 + q2;
        }

        // Public sumRange function
        int sumRange(int left, int right) {
            return query(0, n - 1, left, right, 0);
        }
    };

    segmenttree segTree;

    NumArray(vector<int>& nums) {
        segTree.init(nums.size());
        segTree.build(0, nums.size() - 1, 0, nums);
    }

    void update(int index, int val) {
        segTree.update(index, val);
    }

    int sumRange(int left, int right) {
        return segTree.sumRange(left, right);
    }
};

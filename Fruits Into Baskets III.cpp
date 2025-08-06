class Solution {
public:

    void buildTree(vector<int>& segTree, vector<int>& baskets, int i, int l, int r){
        if(l == r){
            segTree[i] = baskets[l];
            return;
        }
        int mid = l + (r - l) / 2;
        buildTree(segTree, baskets, 2*i+1, l, mid);
        buildTree(segTree, baskets, 2*i+2, mid+1, r);
        segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
    }
    
    int querySegmentTree(vector<int>& segTree, int i, int l, int r, int val){
        if(segTree[i] < val){
            return -1;
        }
        if(l == r){
            segTree[i] = 0;
            return l;
        }
        int mid = l + (r - l) / 2, ans = 0;
        if(segTree[2*i+1] >= val){
            ans = querySegmentTree(segTree, 2*i+1, l, mid, val);
        }else{
            ans = querySegmentTree(segTree, 2*i+2, mid+1, r, val);
        }
        segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
        return ans;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> segTree(4 * n);
        buildTree(segTree, baskets, 0, 0, n-1);
        int unplaced = 0;
        for(int i = 0; i < n; i++){
            int val = querySegmentTree(segTree, 0, 0, n-1, fruits[i]);
            if(val == -1){
                unplaced++;
            }
        }
        return unplaced;
    }
};

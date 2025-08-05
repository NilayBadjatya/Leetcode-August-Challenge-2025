class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), placed = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(baskets[j] >= fruits[i]){
                    baskets[j] = -1;
                    placed++;
                    break;
                }
            }
        }
        return n - placed;
    }
};

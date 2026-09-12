class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();

        int ans = 0;
        // cumulative sum:

        for(int i = 0; i < row; i++){
            for(int j = 1; j < col; j++){
                matrix[i][j] +=  matrix[i][j-1];
            }
        }


                unordered_map<int,int> mpp;
        // now finding ans as per the concept of lc560;

        for(int srtCol = 0; srtCol < col; srtCol++){
            for(int j = srtCol; j < col; j++){
                mpp.clear();
                mpp[0] = 1;
                int sum = 0;
                for(int i = 0; i < row; i++){
                    if( srtCol == 0){
                        sum += matrix[i][j];
                    }else{
                         sum += matrix[i][j] - matrix[i][srtCol-1];
                    }

                    if(mpp.count(sum - k)){
                        ans += mpp[sum - k];
                    }

                    mpp[sum]++;
                }

            }
        }
return ans;

    }
};
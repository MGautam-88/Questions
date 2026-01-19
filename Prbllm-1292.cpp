int maxLength(vector<int> A, int threshold) {
    int n = (int)A.size();
    int PSUM[n + 1];
    // here you need to build the prefix sum for A
    
    auto sum_range = [&](int l, int r) -> int{
        // returns the sum in the range [l, r]
    };
    auto binary_search = [&](int r) -> int{
        // find best length of subarray ending at r
        // this function will use sum_range as a tool
    };
    
    int ans = 0;
    for(int i = 1; i <= n; i ++){
        ans = max(ans, binary_search(i));
    }
    return ans;
}

vector<vector<int>> twoSum(vector<int>& v, int target, int st) {
    vector<vector<int>> res;
    int L = st, R = v.size() - 1;
    while (L < R) {
        int sum = v[L] + v[R];
        if (sum < target || (L > st && v[L] == v[L - 1]))
            ++L;
        else if (sum > target || (R < v.size() - 1 && v[R] == v[R + 1]))
            --R;
        else
            res.push_back({ v[L++], v[R--]});
    }
    return res;
}

vector<vector<int>> kSum(vector<int>& v, int target, int st, int k) {
    vector<vector<int>> res;
    if (st == v.size() || v[st] * k > target || target > v.back() * k)
        return res;
    if (k == 2)
        return twoSum(v, target, st);
    for (int i = st; i < v.size(); ++i)
        if (i == st || v[i - 1] != v[i])
            for (auto &set : kSum(v, target - v[i], i + 1, k - 1)) {
                res.push_back({v[i]});
                res.back().insert(end(res.back()), begin(set), end(set));
            }
    return res;
}

/*
Given an array v of n integers and an integer target, 
are there elements a1, a2... ak in v such that sum = target? 
Find all unique quadruplets in the array which gives the sum of target.

v is sorted before calling this function.
*/

// Similar for K dimensions, better to flatten matrix in higher dimensions
int prefix[X][Y][Z]; // prefix = a
auto getPrefix = [&](int x, int y, int z) -> long long {
    if (x < 0 || y < 0 || z < 0) return 0;
    return prefix[x][y][z];
};
for (int dim = 0; dim < 3; dim++) {
    for (int i = 0; i < X; i++) for (int j = 0; j < Y; j++) for (int k = 0; k < Z; k++)
        prefix[i][j][k] += getPrefix(i - (dim == 0), j - (dim == 1), k - (dim == 2));
}
// vectors for ranges [l_i, r_i] in the sub-matrix query
auto query = [&](vector<int> l, vector<int> r) -> long long {
    int k = l.size();
    long long res = 0;
    for (int mask = 0; mask < (1 << k); mask++) {
        vector<int> coord(k);
        for (int d = 0; d < k; d++) {
            coord[d] = (mask & (1 << d)) ? l[d] - 1 : r[d];
        }
        long long val = getPrefix(coord[0], coord[1], coord[2]);
        if (__builtin_popcount(mask) % 2) res -= val;
        else res += val;
    }
    return res;
};
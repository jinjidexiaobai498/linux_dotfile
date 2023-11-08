#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class UnionFind {

private:
    struct Unit {
        int rank {}; // depth
        int parent {};
        Unit() = default;
    };

    vector<Unit> data;

public:
    UnionFind(size_t SIZE)
    {
        data.assign(SIZE, {});
        for (int i = 0; i < SIZE; i++) {
            data[i].parent = i;
        }
    }
    auto find(int point) -> int
    {
        if (point == data[point].parent) {
            return point;
        }
        data[point].parent = find(data[point].parent);
        return data[point].parent;
    }

    void merge(int point1, int point2)
    {
        int xRoot = find(point1);
        int yRoot = find(point2);

        if (xRoot == yRoot)
            return;

        if (data[xRoot].rank < data[yRoot].rank) {
            data[xRoot].parent = yRoot;
            data[yRoot].rank = max(data[yRoot].rank, data[xRoot].rank + 1);
        } else {
            data[yRoot].parent = xRoot;
            data[xRoot].rank = max(data[xRoot].rank, data[yRoot].rank + 1);
        }
    }

    auto isUnion(int set1, int set2) -> bool
    {
        return find(set1) == find(set2);
    }
    void display(int len = 20)
    {
        for (int l = 0; l < data.size(); l += len) {

            for (int i = 0; l + i < data.size() && i < len; i++) {
                // cout << l + i << ":" << data[l + i].parent << " ";
                printf("%4d:%-4d ", l + i, data[l + i].parent);
            }
            cout << endl;
        }
        cout << endl;
    }
};
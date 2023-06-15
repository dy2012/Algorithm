// 判断输入序列是否是二叉搜索树的后续遍历

#include <iostream>
#include <vector>

using namespace std;

bool judge(vector<int>& a, int l, int r) {
    if (l >= r) {
        return true;
    }

    int i = r;
    while (i > l && a[i - 1] > a[r]) {
        i--;
    }
    for (int j = i - 1; j >= l; --j) {
        if (a[j] > a[r]) {
            return false;
        }
    }
    return judge(a, l, i - 1) && judge(a, i, r - 1);
}

bool VerifyBST(vector<int>& a) {
    if (a.empty()) {
        return false;
    }
    return judge(a, 0, a.size() - 1);
}

int main(int argc, char* argv[]) {
    vector<int> nums = {1, 3, 2};

    cout << VerifyBST(nums) << endl;
    return 0;
}

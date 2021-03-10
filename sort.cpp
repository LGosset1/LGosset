#include <bits/stdc++.h>

using namespace std;

// O(n^2)
void bubble_sort(vector<int> &v);
void selection_sort(vector<int> &v);
void insertion_sort(vector<int> &v);
// O(n^1.3)
void shell_sort(vector<int> &v);

int main() {
    vector<int> v = {3, 5, 2, 3, 6, 7, 1, 4, 9, 8};
    
    // bubble_sort(v);
    // selection_sort(v);
    // insertion_sort(v);
    shell_sort(v);

    for (auto n: v) {
        cout << n << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}

void bubble_sort(vector<int> &v) {
    int length = v.size();

    // i表示固定了几个最大值
    for (int i=0; i < length-1; i++) {
        // j表示当前要比较的元素索引
        for (int j=0; j < length-1-i; j++) {
            if (v[j] > v[j+1]) {
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}

void selection_sort(vector<int> &v) {
    int length = v.size();
    int min_index;

    for (int i=0; i < length-1; i++) {
        min_index = i;
        for (int j=i+1; j < length; j++) {
            // 找到最小值的索引
            if (v[j] < v[min_index]) {
                min_index = j;
            }
        }
        int temp = v[min_index];
        v[min_index] = v[i];
        v[i] = temp;
    }
}

void insertion_sort(vector<int> &v) {
    int length = v.size();
    int current, pre_index;

    for (int i=1; i < length; i++) {
        current = v[i];
        pre_index = i - 1;
        while (pre_index >=0 && v[pre_index] > current) {
            v[pre_index + 1] = v[pre_index];
            pre_index--;
        }
        v[pre_index + 1] = current;
    }
}

void shell_sort(vector<int> &v) {
    int length = v.size();
    int current, pre_index;

    for (int gap=length/2; gap > 0; gap/=2) {
        // 插入排序改进
        for (int i=gap; i < length; i++) {
            current = v[i];
            pre_index = i - gap;
            while (pre_index >= 0  && v[pre_index] > current) {
                v[pre_index + gap] = v[pre_index];
                pre_index -= gap;
            }
            v[pre_index + gap] = current;
        }
    }
}
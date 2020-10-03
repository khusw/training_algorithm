#include <iostream>

using namespace std;

int num = 9;
int heap[9] = {7, 6, 5, 8, 3, 5, 9, 1, 6};

int main() {
    for (int i = 1; i < num; i++) {
        int c = i;
        do {
            int root = (c - 1) / 2;
            if (heap[root] < heap[c]) {
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;

        } while (c != 0);
    }
    for (int i = num - 1; i >= 0; i--) {
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        int root = 0;
        int c = 1;
        do {
            c = 2 * root + 1;
            if (heap[c] < heap[c + 1] && c < i - 1) {
                c++;
            }
            if (heap[root] < heap[c] && c < i) {
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while (c < i);
    }

    for (int i = 0; i < num; i++) {
        cout << heap[i] << ' ';
    }
}
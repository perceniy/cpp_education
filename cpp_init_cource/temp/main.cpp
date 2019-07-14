#include <iostream>

using namespace std;


void swap (int *l, int *r) {
    int buf = *r;
    *r = *l;
    *l = buf;
}

void quicksort(int* l, int * r) {
    if (r - l <= 1) return;
    int* ll = l;
    int* rr = r - 1;
    int z = *(l + (r-l)/2);
    while (ll<=rr) {
        while (*ll < z) ll++;
        while (*rr > z) rr--;
        if (ll <= rr) {
            swap(ll, rr);
            ll++;
            rr--;
        }
    }
    if (l < rr) quicksort(l, rr + 1);
    if (ll < r) quicksort(ll, r);
}

int main() {

    int a[8] = {5,4,6,3,8,3,9,1};


    quicksort(a, a + 8);

    for (int i = 0; i<8; i++) {
        cout << a[i] << endl;
    }


    return EXIT_SUCCESS;
}
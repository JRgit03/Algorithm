#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // find the first decreasing element
    int p = -1;
    for (int i = n - 2; i >= 0; i--)
        if (a[i] > a[i + 1]) {
            p = i;
            break;
        }

    if (p == -1) {  // the permutation is already lexicographically maximum
        reverse(a, a + n);
    } else {
        // find the first element greater than a[p] in suffix
        int mx = -1, q = -1;
        for (int i = n - 1; i > p; i--) {
            if (a[i] > a[p] && a[i] > mx) {
                mx = a[i];
                q = i;
            }
        }

        // swap a[p] and a[q], then reverse the suffix
        swap(a[p], a[q]);
        reverse(a + p + 1, a + n);
    }

    // output
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}

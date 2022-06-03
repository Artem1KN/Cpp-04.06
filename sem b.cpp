#include <iostream>

using namespace std;

int main()
{
    int mont[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int n, m, g;

    cin >> n >> m >> g;

	cout << mont[m-1]<<endl;

    if (m == 12 and n == mont[11]) {
        g++;

        cout << 1 << "." << 1 << "." << g;
    }
    else if (n == mont[m - 1] and m < 12) {
        m++;

        cout << 1 << "." << m << "." << g;
    }
    else {
        cout << n + 1 << "." << m << "." << g;
    }

    return 0;
}
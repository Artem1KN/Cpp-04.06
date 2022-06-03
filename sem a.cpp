#include <iostream>

using namespace std;

int main()
{
    int mont[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int n, m, g;

    cin >> n >> m >> g;

	cout << mont[m-1]<<endl;

    if (m == 1 and n == 1) {
        g--;
        cout << 31 << "." << 12 << "." << g;
    }
    else if (n == 1 and m > 1) {
        cout << mont[m--] << "." << m << "." << g;
    }
    else {
        cout << n - 1 << "." << m << "." << g;
    }

    return 0;
}
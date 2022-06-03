#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 26; i > 0; i--){
        if (n == 1) {
            cout << char('a' + i - 1);
            return 0;
        } else {
            if (n <= pow(2, i - 1))
                n--;
            else
                n -= int(pow(2, i - 1));
        }
    }
    return 0;
}

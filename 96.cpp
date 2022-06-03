#include <iostream>
#include <vector>

using namespace std;

int nah[4] { 0, 1, 2, 3 };
int got = 0;
int dX[4] { 1, 0, -1, 0 };
int dY[4] { 0, 1, 0, -1 };
int dx = dX[0], dy = dY[0];

int main()
{
    int n, m;
    cin >> n >> m;
    if (n * m == 0){
        cout << 0;
        return 0;
    }
    int polyana[102][102];
    for (int i = 0; i <= n + 1; i++){
        for (int j = 0; j <= m + 1; j++){
            polyana[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            polyana[i][j] = 1;
        }
    }
    int x, y;
    cin >> y >> x;
    polyana[y][x] = 2;
    x = 1; y = 1;
    int cup = 0;
    while (polyana[y][x] != 2){
        if (polyana[y][x] == 0){
            x = x - dx; y = y - dy;
            got = (got + 5) % 4;
            dx = dX[got]; dy = dY[got];
            x = x + dx; y = y + dy;
        }
        if (polyana[y][x] != 2){
            cup++;
            polyana[y][x] = 0;
            x = x + dx;
            y = y + dy;
        }
    }
    cup++;
    cout << cup;
    return 0;
}

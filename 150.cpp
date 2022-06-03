#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    int n, s;
    int answer = 0;
    cin >> n >> s;
    vector<vector<bool>> mas(n + 1, vector<bool> (n + 1));
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int c;
            cin >> c;
            mas[i][j] = (c == 1);
        }
    }
    function<void(int)> visit = [&](int cur){
        if (visited[cur])
            return;
        answer++;
        visited[cur] = true;
        for (int i = 1; i <= n; i++){
            if (mas[cur][i])
                visit(i);
        }
    };
    visit(s);
    cout << answer - 1;
    return 0;
}

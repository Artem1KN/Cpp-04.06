#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <fstream>
#include <numeric>

using namespace std;

#define ut unsigned int

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    int sum = 0;
    fin >> n;
    vector<int> massiv(n);
    for (int i = 0; i < n; i++) {
        fin >> massiv[i];
        sum += massiv[i];
    }
    sort(massiv.begin(), massiv.end());
    int massivMax = massiv[n - 1];
    int massivMin = min(sum / 2, sum - massivMax);
    fout << massivMin;

    return 0;
}

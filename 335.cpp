#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

vector<int> digitsToNumber(int number, int amountOfDigits)
{
    vector<int> arr(amountOfDigits);
    for (int i = amountOfDigits - 1; i >= 0 && number > 0; --i, number /= 10)
    {
        arr[i] = number % 10;
    }
    return arr;
}

bool isSimple(int number)
{
    int temp;
    for (int i = 2; i < number / 2; ++i)
    {
        temp = number % i;
        if (temp == 0)
            return false;
    }
    return true;
}

bool isTripleSimple(vector<int> arr)
{
    bool isTriple = false;
    for (int i = 0; i < arr.size() - 2; ++i)
    {
        string sNumber = "";
        sNumber += to_string(arr[i]);
        sNumber += to_string(arr[i + 1]);
        sNumber += to_string(arr[i + 2]);
        int tempNumber = stoi(sNumber);
        if (tempNumber >= 100 && isSimple(tempNumber))
            isTriple = true;
        else
            return false;
    }
    return isTriple;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;
    int count = 0;
    for (int numb = int(pow(10, n - 1)); numb < pow(10, n); ++numb)
    {
        vector<int> arr = digitsToNumber(numb, n);
        if (isTripleSimple(arr))
            count++;
    }
    fout << count;

    return 0;
}

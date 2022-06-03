#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string a, b;
    fin >> a;
    fin >> b;

    int minlen = a.length() + b.length();

    for (int dvr = 0 - (int)b.length(); dvr <= (int)a.length(); dvr++) {
        int first = min(dvr, 0);
        int last = max(dvr + (int)b.length() - 1, (int)a.length() - 1);
        bool flag= true;

        for (int i = first; i <= last; i++) {
            int aVal, bVal;
            if (0 <= i && i < (int)a.length()) {
                aVal = a[i] - '0';
            }
            else {
                aVal = 1;
            }
            if (dvr <= i && i < dvr + (int)b.length()) {
                bVal = b[i - dvr] - '0';
            }
            else {
                bVal = 1;
            }
            if (aVal + bVal > 3) {
                flag = false;
                break;
            }
        }
        if (flag) {
            int len = last - first + 1;
            if (len < minlen)
                minlen = len;
        }
    }
    fout << minlen;

    return 0;
}
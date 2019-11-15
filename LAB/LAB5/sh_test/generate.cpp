#include<iostream>
#include<cstdlib>
#include<string>
#include<time.h>
using namespace std;
int main(int argc,char**argv)
{
    srand(time(NULL));
    string s = argv[1];
    int n = stoi(s);
    int max = INT32_MAX / (n * n);
    cout << n << "\n";
    cout << n << "\n";
    cout << "0 0" << endl;
    cout << n - 1 << " " << n - 1 << endl;
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n;j++)
        {
            cout << rand() % max << " ";
        }
        cout << "\n";
    }
}
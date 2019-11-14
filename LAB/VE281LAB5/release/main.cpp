#include "interface.h"
#include "graph.h"
#include <iostream>
#include<time.h>
int main(int argc,char** argv)
{
    using namespace std;
    ios::sync_with_stdio(false);
    cin.tie(0);
    myOption option = parseArgs(argc,argv);
    if(option.implement == -1)
    {
        return -1;
    }
    Graph graph(option);
    clock_t start = clock();
    graph.solve();
#ifdef TIME
    cout << float(clock() - start)/CLOCKS_PER_SEC << "\n";
#else
    cerr << "Time: " << float(clock() - start)/CLOCKS_PER_SEC << "\n";
#endif
    return 0;
}

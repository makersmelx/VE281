//
// Created by 吴佳遥 on 2019-11-06.
//

#include "interface.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <getopt.h>
#include <iostream>
//#define  DEBUG
myOption parseArgs(int argc, char** argv)
{
    using namespace std;
    int inputChar = 0;
    struct option opts[] = {
            {"implementation", 1, NULL, 'i'},
            {"verbose", 0, NULL, 'v'}
    };
    myOption res;
    res.verbose = false;
    res.implement = -1;
    while((inputChar = getopt_long(argc,argv,"i:v",opts,NULL)) != -1)
    {
        switch(inputChar)
        {
            case 'i':
            {
#ifdef DEBUG
                cout << optarg << endl;
#endif
                if(!strcmp(optarg,"BINARY"))
                {
                    res.implement = BINARY;
                }
                else if(!strcmp(optarg,"UNSORTED"))
                {
                    res.implement = UNSORT;
                }
                else if(!strcmp(optarg,"FIBONACCI"))
                {
                    res.implement = FIB;
                }
                break;
            }
            case 'v':
            {
                res.verbose = true;
                break;
            }
        }
    }
    return res;
}

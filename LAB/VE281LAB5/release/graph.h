//
// Created by 吴佳遥 on 2019-11-06.
//

#ifndef VE281LAB5_GRAPH_H
#define VE281LAB5_GRAPH_H
#include <vector>
#include "priority_queue.h"
#include "binary_heap.h"
#include "fib_heap.h"
#include "unsorted_heap.h"
#include<sstream>
#define FIB 1
#define BINARY 2
#define UNSORT 3
//#define TIME

struct myOption
{
    bool verbose;
    int implement;
};

struct Axis
{
    int r;
    int c;
};
class Vertex
{
public:
    int pathCost;
    int row;
    int column;
    int cost;
    bool visited;
    Axis prev;
    Vertex(int _row, int _column, int _cost):row(_row),column(_column),cost(_cost)
    {
        pathCost = 0;
        prev = {-1,-1};
        visited = false;
    }
    struct compare_t
    {
        bool operator()(Vertex *a,Vertex *b) const
        {
            if (a->pathCost < b->pathCost)
            {
                return true;
            }
            else if (a->pathCost == b->pathCost)
            {
                if(a->column < b->column)
                {
                    return true;
                }
                else if(a->column == b->column)
                {
                    if(a->row < b->row)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
    };

};

class Graph
{
private:
    std::vector<std::vector<Vertex>> points;
    Axis start;
    Axis end;
    int shortest;
    int mode;
    int row_num;
    int column_num;
    bool verbose;
    priority_queue<Vertex *, Vertex::compare_t> *pq;

public:
    Graph(const myOption &option);
    ~Graph();
    void solve();
private:
    void check();
    Vertex& get_point(const Axis &a);
    int set_neighbor(Vertex* v, const int& a, const int &b,std::stringstream &ss);
    void track_path(const Axis &a, std::stringstream &ss);
    void result_print(std::stringstream &ss);
};

#endif //VE281LAB5_GRAPH_H

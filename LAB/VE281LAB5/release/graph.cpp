//
// Created by 吴佳遥 on 2019-11-06.
//

#include "graph.h"
#include <iostream>
std::ostream &operator<<(std::ostream &os, const Axis &axis)
{
    return os << "(" << axis.c << ", " << axis.r << ")";
}

std::ostream &operator<<(std::ostream &os, const Vertex &v)
{
    return os << "(" << v.column << ", " << v.row << ")" << " with accumulated length " << v.pathCost ;
}

Graph::Graph(const myOption &option){
    using namespace std;
    cin >> column_num;
    cin >> row_num;
    int st_r = 0, st_c = 0;
    cin >> st_r;
    cin >> st_c;
    int ed_r = 0, ed_c = 0;
    cin >> ed_r;
    cin >> ed_c;
    for(int i = 0 ; i < row_num;i++)
    {
        points.emplace_back();
        for(int j = 0 ; j < column_num;j++)
        {
            int tmp = 0;
            cin >> tmp;
            points[i].emplace_back(i,j,tmp);
        }
    }
    start = {st_c,st_r};
    end = {ed_c,ed_r};
    shortest = 0;
    switch (option.implement)
    {
        case BINARY:
        {
            pq = new binary_heap<Vertex*,Vertex::compare_t>;
            break;
        }
        case UNSORT:
        {
            pq = new unsorted_heap<Vertex*,Vertex::compare_t>;
            break;
        }
        case FIB:
        {
            pq = new fib_heap<Vertex*,Vertex::compare_t>;
            break;
        }
        default:break;
    }
    verbose = option.verbose;
#ifdef TIME
    cout << row_num << ",";
#endif
    //check();
}

Graph::~Graph()
{
    delete pq;
}

void Graph::solve()
{
    using namespace std;
    int counter = 0;
    Vertex &s = get_point(start);
    s.pathCost = s.cost;
    s.visited = true;
    pq->enqueue(&s);
    std::string output;
    stringstream ss;
    while (!pq->empty())
    {
        if(verbose)
        {
            ss << "Step " << counter++ << "\n";
        }
        Vertex* minimum = pq->dequeue_min();
        if(verbose)
        {
            ss << "Choose cell " << *minimum << ".\n";
        }
        if(set_neighbor(minimum,0,1,ss) == 1)
            break;
        if(set_neighbor(minimum,1,0,ss) == 1)
            break;
        if(set_neighbor(minimum,0,-1,ss) == 1)
            break;
        if(set_neighbor(minimum,-1,0,ss) == 1)
            break;
        //std::cerr << "??" << "\n";
    }
#ifndef TIME
    result_print(ss);
    output = ss.str();
    cout << output;
#endif
}

void Graph::check()
{
    for(auto &p:points)
    {
        for(auto &q : p)
        {
            std::cout << q.cost << " ";
        }
        std::cout << std::endl;
    }
}

Vertex& Graph::get_point(const Axis &a)
{
    return points[a.r][a.c];
}

void Graph::result_print(std::stringstream &ss)
{
    ss << "The shortest path from "
         << start << " to " << end
         << " is " << shortest << ".\n"
         << "Path:" << "\n";
    track_path(end,ss);
}

void Graph::track_path(const Axis &a, std::stringstream &ss)
{
    Vertex &v = get_point(a);
    if(v.prev.r >= 0)
    {
        track_path(v.prev, ss);
    }
    ss << a << "\n";
}

int Graph::set_neighbor(Vertex* v, const int& r, const int &c,std::stringstream &ss)
{
    if(v->row + r >= 0 && v->row + r < row_num &&
        v->column + c >= 0 && v->column + c < column_num)
    {
        Vertex &neighbor = points[v->row+r][v->column+c];
        if(!neighbor.visited)
        {
            neighbor.visited = true;
            neighbor.pathCost = neighbor.cost + v->pathCost;
            neighbor.prev = {v->row,v->column};
            if(v->row+r == end.r && v->column + c == end.c)
            {
                if(verbose)
                    ss << "Cell " << neighbor << " is the ending point.\n";
                shortest = neighbor.pathCost;
                return 1;
            }
            else
            {
                pq->enqueue(&neighbor);
                if(verbose)
                    ss << "Cell " << neighbor << " is added into the queue.\n";
            }
        }

    }
    return 0;

}


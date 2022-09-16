#include "UnionFind.h"
#include <limits>

void UnionFind::connect(int a, int b)
{
    // Check if _data space is not sufficient to hold new data as index then increase the size.
    if(_data.size() < a)
        _data.resize(a*2, -1);
    if(_data.size() < b)
        _data.resize(b*2, -1);

    if(_data.at(a)==-1 && _data.at(b)==-1){
        _id += 1;
        _data[a] = _id;
        _data[b] = _id;
    }
    else if(_data.at(a) == -1){
        _data[a] = _data[b];
    }
    else if(_data.at(b) == -1){
        _data[b] = _data[a];
    }
    else {
        int oldId;
        if(_data.at(a) < _data.at(b)){
            oldId =_data[b];
            _data[b] = _data[a];
        }
        else{
            oldId = _data[a];
            _data[a] = _data[b];
        }
        for( auto& x: _data){
            if(x == oldId)
                x=_data[a];
        }
    }
}
bool UnionFind::isConnected(int a, int b) const
{
    return (_data.at(a) == _data.at(b));
}
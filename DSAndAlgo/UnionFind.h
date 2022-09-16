#include <vector>
#include <ostream>
class UnionFind{
public:
    UnionFind() : _id(0){
    }
public:
    void connect(int a, int b);
    bool isConnected(int a, int b) const;

private:
    std::vector<int> _data;
    unsigned int _id;

friend std::ostream& operator << (std::ostream& os, UnionFind& uf){
    for(auto x: uf._data){
        os << x << " ";
    }
    return os;
}
};
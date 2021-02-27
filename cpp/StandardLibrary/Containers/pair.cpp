#include <iostream>
#include <map>
#include <string>
#include <unistd.h>
template <class key_type, class value_type>
class pair{
public:
    pair(const key_type& key, const value_type& value){
        this->key = key;
        this->value = value;
    }
public:
    const key_type& first() const{
        return key;
    }
    const value_type& second() const{
        return value;
    }
public:
    key_type key;
    value_type value;
};


pair<int,int> getPoint(){
    int x = 10;
    int y = 20;
    return pair<int,int>(x,y);
}

// class abc{
// public:
//     abc(){
//         index = 0;
//     }
//     std::string& operator [] (std::string key){
//         p[index].key = key;
//         return p[index++].value;
//     }
//     pair<std::string, std::string> p[30];
//     int index;
// }

int main(){

    // abc obj;
    // obj["name"] = "ram";
    // obj["name1"] = "shyam";

    std::map<std::string,std::string> m;

    // inserting data to map 
    m["name"] = "Ram";  // assign key <-> value
    if(!m.insert(std::pair<std::string,std::string>("name1","Ramesh")).second){
        std::cout << "Couldn't insert" << std::endl;
    }
    if(!m.emplace("name2","Ramesh").second){
        std::cout << "Couldn't insert" << std::endl;
    }   

    auto it = m.find("name3");
    if(it != m.end()){
        std::cout << it->first << "|" << it->second << std::endl;
    }else{
        std::cout << "Couldn't find" << std::endl;
    }
    //for(auto it = m.begin(); it < m.end(); ++it)
    for(auto it : m){
        std::cout << it.first << "|" << it.second << std::endl;
    }
}
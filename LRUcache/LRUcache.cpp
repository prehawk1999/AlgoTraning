/*
 * LRUcache.hpp
 *
 *  Created on: 2014年5月26日
 *      Author: admin
 */

#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <unordered_map>
#include <list>


namespace {

using std::list;
using std::unordered_map;
using std::pair;
using std::string;
using std::cout;
using std::endl;
using std::ostream;

class LRUCache {
    typedef unordered_map<int, list< pair<int, int> >::iterator>        LRU_hash_t;
    typedef list< pair<int, int> >::iterator                            Item_iter_t;
public:

    LRUCache(int capacity)
    :
    _cap_limit(capacity) {}

    friend ostream &operator<<(ostream &os, const LRUCache &cache);

    int get(int key) {
        if(key <= 0 || _cap_limit == 0) return -1;

        // if get, promote the rank of get item.
        auto it = _hash_key.find(key);
        if(it == _hash_key.end()) return -1;

        _hash_key[key] = promote(it->second);
        return _hash_key[key]->second;
    }

    void set(int key, int value) {
        if(_cap_limit == 0) return;

        auto it = _hash_key.find(key);
        if(it != _hash_key.end()) {
            _hash_key[key] = promote(it->second);
            _hash_key[key]->second = value;
        }
        else {
            _hash_key[key] = _list_value.insert(_list_value.begin(), pair<int,int>(key,value));
            if( _hash_key.size() > _cap_limit) {
                _hash_key.erase(_hash_key.find(_list_value.back().first));
                _list_value.pop_back();
            }
        }
    }

    Item_iter_t promote(Item_iter_t it) {
        auto itNew = _list_value.insert(_list_value.begin(), *it);
        _list_value.erase(it);
        return itNew;
    }

private:
    size_t                                                 _cap_limit;
    list< pair<int, int> >                                 _list_value; // key, value
    LRU_hash_t                                             _hash_key;   // key, list iterator
};

inline ostream&
operator<<(ostream &os, const LRUCache &cache)
{
    for(auto it=cache._list_value.begin(); it!= cache._list_value.end(); ++it) {
        os << " key: " << it->first << " value: " << it->second << endl;
    }
    return os;
}


} // namespace



// /10,[set(7,28),set(7,1),set(8,15),get(6),set(10,27),set(8,10),get(8),set(6,29),set(1,9),get(6),set(10,7),get(1),get(2),get(13),set(8,30),set(1,5),get(1),set(13,2),get(12)]
int main() {
    auto s = LRUCache(10);
    s.set(7,28);
    s.set(7,1);
    s.set(8,15);
    cout << s.get(6) << endl;
    s.set(10,27);
    s.set(8,10);
    cout << s.get(8) << endl;
    s.set(6,29);
    s.set(1,9);
    cout << s.get(6) << endl;
    s.set(10,7);
    cout << s.get(1) << endl;
    cout << s.get(2) << endl;
    cout << s.get(13) << endl;
    s.set(8,30);
    s.set(1,5);
    cout << s << endl;
    cout << s.get(1) << endl;
    s.set(13,2);
    cout << s.get(12) << endl;
}
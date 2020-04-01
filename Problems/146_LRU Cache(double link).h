/**
 * @Problem https://leetcode.com/problems/lru-cache/
 * @Author  MinRam
 * @Date    02/04/2020
 * @Describe Achieved with a double list and a unordered hash map;
 */
 
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class LRUCache {
public:
    unordered_map<int,list<pair<int,int>>::iterator> mymap;
    list<pair<int,int>> v_l;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mymap.find(key)==mymap.end()) return -1;
        v_l.splice(v_l.end(),v_l,mymap[key]);
        return (--v_l.end())->second;
    }
    
    void put(int key, int value) {
        if(mymap.find(key)!=mymap.end())
        {
           mymap[key]->second=value;
           v_l.splice(v_l.end(),v_l,mymap[key]);
        }
        else if(mymap.size()==cap)
        {
            mymap.erase(v_l.begin()->first);
            v_l.erase(v_l.begin());
            v_l.push_back(make_pair(key,value));
            mymap[key]=--v_l.end();
        }
        else
        {
             v_l.push_back(make_pair(key,value));
             mymap[key]=--v_l.end();
        }
       
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
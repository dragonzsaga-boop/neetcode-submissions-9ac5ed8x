class LRUCache {
    struct node {
        int key;
        int val;
    };
    unordered_map<int, list<node>::iterator> hasher;
    list<node> vals;
    int capacity;
public:
    LRUCache(int capacity):capacity(capacity) {
    }
    void putInFront(node keyValPair) {
        // cout<<"Inserting : "<<keyValPair.key<<", "<<keyValPair.val<<endl;
        vals.push_front(keyValPair);
        hasher[keyValPair.key] = vals.begin();
        // for(auto iter:hasher) {
        //     cout<<" :: "<<iter.first<<" : "<<iter.second->val<<endl;
        // }
    }
    int get(int key) {
        if(!hasher.count(key)) {
            // cout<<key<<" not found"<<endl;
            return -1;
        }
        // cout<<"Getting element for :"<<key<<endl; 
        auto currNodeIter = hasher[key];
        auto retVal = currNodeIter->val;

        vals.erase(currNodeIter);
        putInFront({key,retVal});
        return retVal;
    }
    
    void put(int key, int value) {
        if(!hasher.count(key) && hasher.size() == capacity) {
            auto lastElem = vals.rbegin();
            hasher.erase(lastElem->key);
            vals.pop_back();
        }
        if(hasher.count(key)) {
            //remove current element
            auto existingIter = hasher[key];
            vals.erase(existingIter);
            putInFront({key,value});
            return;
        }
        putInFront({key,value});
    }
};

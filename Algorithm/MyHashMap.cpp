class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        arr = vector<LinkL *>(capacity, nullptr);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int idx = key % capacity;
        
        if(!arr[idx]){
            arr[idx] = new LinkL(key, value);
        }else{
            LinkL *prev_ptr = nullptr;
            for(LinkL *ptr = arr[idx] ; ptr ; prev_ptr = ptr, ptr = ptr->next){
                if(ptr->key == key){
                    ptr->value = value;
                    return;
                }
            }
            prev_ptr->next = new LinkL(key, value);
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int idx = key % capacity;
        for(LinkL *ptr = arr[idx]; ptr; ptr = ptr->next){
            if(ptr->key == key){
                return ptr->value;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int idx = key % capacity;
        LinkL *prev_ptr = nullptr;
        for(LinkL *ptr = arr[idx]; ptr; ptr = ptr->next){
            if(ptr->key == key){
                if(prev_ptr){
                    prev_ptr->next = ptr->next;
                    return ;
                }else{
                    arr[idx] = ptr->next;
                    return;
                }
            }
            prev_ptr = ptr;
        }
    }
private:
    
    class LinkL{
    public:
        
        int key;
        int value;
        LinkL *next;
        
        LinkL(int k, int v){
            key = k;
            value=v;
            next=nullptr;
        }
        LinkL(){
            key=-1;
            value=-1;
            next=nullptr;
        }   
    };
    
    int capacity=1000;
    vector<LinkL *> arr;
};
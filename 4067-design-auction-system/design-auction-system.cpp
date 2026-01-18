class AuctionSystem {
public:
    typedef pair<int,int> pr;

    unordered_map<int,unordered_map<int,int>> itemToUser; // {itemId,{userId,bidAmount}}
    unordered_map<int,priority_queue<pr>> pq; // {itemid,{bidAmount,userId}}

    AuctionSystem() {
        
    }
    

    void addBid(int userId, int itemId, int bidAmount) {
        itemToUser[itemId][userId]=bidAmount;
        pq[itemId].push({bidAmount,userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        auto &_pq=pq[itemId];
        itemToUser[itemId][userId]=newAmount;
        _pq.push({newAmount,userId});
    }
    
    void removeBid(int userId, int itemId) {
        itemToUser[itemId].erase(userId);
    }
    
    int getHighestBidder(int itemId) {
        auto &_pq=pq[itemId];
        while(_pq.size()){
            auto [bidAmt,id]=_pq.top();
            if(itemToUser[itemId].count(id) && itemToUser[itemId][id]==bidAmt) return id;
            _pq.pop();
        }
        return -1;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */
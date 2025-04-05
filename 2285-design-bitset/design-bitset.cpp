class Bitset {
public:
    string bits, bitsRev;
    int ones, onesRev, flips;

    Bitset(int size) {
        bits=string (size,'0');
        bitsRev=string (size,'1');
        ones=0;
        onesRev=size;
        flips=0;
    }
    
    void fix(int idx) {
        if(!(flips&1)){ // even flips
            ones+=(bits[idx]=='0');
            bits[idx]='1';
            onesRev-=(bitsRev[idx]=='1');
            bitsRev[idx]='0';
        }
        else{
            ones-=(bits[idx]=='1');
            bits[idx]='0';
            onesRev+=(bitsRev[idx]=='0');
            bitsRev[idx]='1';
        }
    }
    
    void unfix(int idx) {
        if(!(flips&1)){ // even flips
            ones-=(bits[idx]=='1');
            bits[idx]='0';
            onesRev+=(bitsRev[idx]=='0');
            bitsRev[idx]='1';
        }
        else{
            ones+=(bits[idx]=='0');
            bits[idx]='1';
            onesRev-=(bitsRev[idx]=='1');
            bitsRev[idx]='0';
        }
    }
    
    void flip() {
        flips++;
    }
    
    bool all() {
        if(flips&1) return onesRev==bits.length();
        return ones==bits.length();
    }
    
    bool one() {
        if(flips&1) return onesRev>=1;
        return ones>=1;
    }
    
    int count() {
        if(flips&1) return onesRev;
        return ones;
    }
    
    string toString() {
        return flips&1 ? bitsRev : bits;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
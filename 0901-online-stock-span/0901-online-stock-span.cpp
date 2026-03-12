class StockSpanner {
public:
    vector<int> spans;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 0;
        spans.push_back(price);
        for(int i=spans.size()-1; i>=0; i--){
            if(spans[i] <= price){
                span++;
            }
            else{
                break;
            }
        }
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
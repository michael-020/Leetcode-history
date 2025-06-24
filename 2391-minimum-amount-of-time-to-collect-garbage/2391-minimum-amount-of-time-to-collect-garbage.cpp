class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickM = 0, pickP = 0, pickG = 0;
        int travelM = 0, travelP = 0, travelG = 0;
        int lastM = 0, lastP = 0, lastG = 0;

        for(auto it=0; it<garbage.size(); it++){
            string s = garbage[it];
            for(int i=0; i<s.size(); i++){
                char ch = s[i];
                if(ch == 'M'){
                    pickM++;
                    lastM = it;
                }

                if(ch == 'P'){
                    pickP++;
                    lastP = it;
                }

                if(ch == 'G'){
                    pickG++;
                    lastG = it;
                }
            }
        }

        for(int i=0; i<lastM; i++){
            travelM += travel[i];
        }

        for(int i=0; i<lastP; i++){
            travelP += travel[i];
        }

        for(int i=0; i<lastG; i++){
            travelG += travel[i];
        }

        int totalAns = (pickM + pickP + pickG) + (travelM + travelP + travelG);
        return totalAns;
    }
};
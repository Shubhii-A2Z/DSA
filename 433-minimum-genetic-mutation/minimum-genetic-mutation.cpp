class Solution {
public:
    // Standard BFS solution ==> Similar to "Word Ladder"
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> q;
        unordered_set<string> visitedStrings, isValid(begin(bank),end(bank));

        visitedStrings.insert(startGene);
        q.push(startGene);
        int stepsTaken=0;

        while(q.size()){
            int sze=q.size();
            while(sze--){
                string currGene=q.front(); q.pop();

                if(currGene==endGene) return stepsTaken;

                for(int i=0;i<currGene.length();++i){
                    string newGene=currGene;
                    for(char ch:{'A','C','G','T'}){
                        newGene[i]=ch;
                        if(isValid.count(newGene) &&  !visitedStrings.count(newGene)){
                            visitedStrings.insert(newGene);
                            q.push(newGene);
                        }
                    }
                }
            }
            stepsTaken++;
        }

        return -1;
    }
};
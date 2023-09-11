class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        // Approach 1
        /*
        unordered_map<int, vector<int>> group;

        for(int i=0; i<groupSizes.size(); i++){
            group[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> answer;
        for(auto child:group){
            int size = child.first;
            int groupcount = child.second.size()/size;

            if(groupcount == 1){
                answer.push_back(child.second);
                continue;
            }

            for(int i=0; i<groupcount; i++){
                vector<int> temp;
                for(int j=0; j<size; j++){
                    temp.push_back(child.second[i * size + j]);
                }
                answer.push_back(temp);
            }
        }

        return answer;
        */

        // Approach 2
        unordered_map<int,vector<int>> order;
        vector<vector<int>> answer;
        for(int i=0; i<groupSizes.size(); i++){
            int index = groupSizes[i];
            order[index].push_back(i);
            
            if(index == order[index].size()){
                answer.push_back(order[index]);
                order[index].clear();
            }
        }
        return answer;
    }
};
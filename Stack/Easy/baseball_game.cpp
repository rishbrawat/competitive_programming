class Solution {
public:
    int calPoints(vector<string>& operations) {
        // ops = [5, 2, c, d, +]
        //integer x (add to the record) record = 5
        //x (add the record) record = 5, 2
        // operation c => invalidate the previous record=> record = 5
        // d => double the previous score and add it to the record => 5, 10
        // + => record a new element that is sum of previous two elements => 5, 10, 15

        // check the individual operation on each index and perform the operation
        vector<int> ans;
        
        for(const string& op: operations) {
            if(op == "D") {
                // get the element and double it
                ans.push_back(ans.back() * 2);
            }
            else if (op == "C") {
                // remove previous element
                ans.pop_back();
            }
            else if(op == "+") {   
                int size = ans.size()-1;  
                ans.push_back(ans[size-1] + ans[size]);
            }
            else 
                ans.push_back(stoi(op));
        }

        int result = 0;
        for(auto score: ans) {
            result += score;
        }
        return result;
    }
};
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        deque<int> dq(students.begin() , students.end());
        deque<int> s (sandwiches.begin() , sandwiches.end());
        int count = 0;
        while(s.size() != count && !s.empty()){
            if(dq.front() == s.front()){
                count = 0;
                dq.pop_front();
                s.pop_front();
            }else{
                dq.push_back(dq.front());
                dq.pop_front();
                count++;
            }       }

        return s.size();
    }
};
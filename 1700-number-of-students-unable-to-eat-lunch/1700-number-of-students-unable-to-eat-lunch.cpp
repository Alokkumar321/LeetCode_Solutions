class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> preferences;
        for (int student : students)
            preferences.push(student);
        
        int rotations = 0;
        while (!preferences.empty() && rotations < preferences.size()) {
            if (preferences.front() == sandwiches.front()) {
                preferences.pop();
                sandwiches.erase(sandwiches.begin());
                rotations = 0;
            } else {
                int front_element = preferences.front();
                preferences.pop();
                preferences.push(front_element);
                rotations++;
            }
        }
        
        return preferences.size();
    }
};
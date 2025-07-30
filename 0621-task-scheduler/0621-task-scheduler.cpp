class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int tasksSize = tasks.size();

        vector<int> taskFreq(26,0);
        for(int i=0;i<tasksSize;i++) taskFreq[tasks[i]-'A']++;

        sort(taskFreq.begin(),taskFreq.end());
        int maxFreq = taskFreq[25];
        int maxSlots = maxFreq - 1;
        int spotsLeft = maxSlots * n;

        for(int i =24;i>=0;i--){
            spotsLeft -= min(maxSlots,taskFreq[i]);
        }

        if(spotsLeft > 0) return (tasks.size() + spotsLeft);
        return tasks.size();
    }
};
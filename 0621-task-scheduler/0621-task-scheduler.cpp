class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int tasksSize = tasks.size();

        vector<int> taskFreq(26,0);
        for(int i=0;i<tasksSize;i++) taskFreq[tasks[i]-'A']++;

        priority_queue<int> maxHeap;
        for(int i=0;i<26;i++){
            if(taskFreq[i]!=0) maxHeap.push(taskFreq[i]);
        } 

        int minTimeRequired = 0;
        while(!maxHeap.empty()){
            vector<int> temp;
            for(int i= 0;i<n+1;i++){
                if(!maxHeap.empty()){
                    int topFreq = maxHeap.top();
                    maxHeap.pop();
                    topFreq--;
                    temp.push_back(topFreq);
                }
            }

            for(int i =0;i<temp.size();i++){
                if(temp[i]!=0) maxHeap.push(temp[i]);
            }

            if(maxHeap.empty()){
                minTimeRequired += temp.size();
            }
            else{
                minTimeRequired += n+1;
            }

        }

        return minTimeRequired;
    }
};
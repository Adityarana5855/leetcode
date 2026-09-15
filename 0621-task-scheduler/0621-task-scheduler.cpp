class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for(char task : tasks) {
            freq[task - 'A']++;
        }

        int maxFreq = 0;
        int countMax = 0;

        for(int f : freq) {
            maxFreq = max(maxFreq, f);
        }

        for(int f : freq) {
            if(f == maxFreq)
                countMax++;
        }

        int result = (maxFreq - 1) * (n + 1) + countMax;

        return max((int)tasks.size(), result);
    }
};
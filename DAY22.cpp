/*Question 1: Mr. Amit have some jobs to be scheduled. Each job must meet the deadline to be counted as completed i.e. scheduling a job after its deadline is of no use.
Each job has some profit associated with it. Mr. Amit wants to schedule the as much jobs as he can and also want to earn the maximum profit.
Note: Each job needs 1 time unit for execution.
Input Format:
The 1st line contains an integer N, the number of jobs.
The 2nd line contains N integers separated by space denoting deadline times of N jobs.
The 3rd line contains N integers separated by space denoting profits of N jobs.
Output Format:
Print the maximum profit that can be earned.
Constraints:
1 <= N <= 10^5
1 <= Deadline <= 100
1 <= Profit <= 500
Sample Input
4
2 1 1 2
6 8 5 10
Sample Output
18
Explanation:
Job2 can be scheduled to execute at time 1 with profit 8.
Job4 can be scheduled to exec﻿ute at time 2 with profit 10. 
So maximum profit that can be earned is 18.*/

struct Job {
    int deadline;
    int profit;
};
bool jobComparator(Job a, Job b) {
    return a.profit > b.profit;
}
int jobScheduling(vector<int> deadlines, vector<int> profits) {
  int N = deadlines.size();
    
    
    vector<Job> jobs(N);
    for (int i = 0; i < N; i++) {
        jobs[i] = {deadlines[i], profits[i]};
    }

    
    sort(jobs.begin(), jobs.end(), jobComparator);

 
    vector<bool> timeSlot(101, false); 
    int maxProfit = 0;

    
    for (int i = 0; i < N; i++) {
      
        for (int j = min(100, jobs[i].deadline); j > 0; j--) {
            if (!timeSlot[j]) { 
                timeSlot[j] = true;
                maxProfit += jobs[i].profit;
                break;
            }
        }
    }

    return maxProfit; // Return the maximum profit
}


/*Question 2: The knapsack problem or rucksack problem is a problem in combinatorial optimization: Given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible.
In this problem we will solve a variant of it, in which the items can have a binary decision only i.e. either you can pick the item or leave it. No partial items allowed to fill the bag at fullest. This is also known as 0-1 knapsack problem.
Given two integer arrays values[0..n-1] and weight[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of values[] such that sum of the weights of this subset is smaller than or equal to W.
Note: You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
Input Format
First Line will contain an integer N denoting the number of items.
Second line contains N integers separated by space as values of N items.
Third line contains N integers separated by space as weights of N items.
Fourth line contains an integer denoting the capcacity of knapsack.
Output Format
Print the maximum value that can be earned with above knapsack.
Constraints
1 <= N <= 10^3
1 <= val[i] <= 10^3
1 <= weight[i]  <= 10^3
1 <= capacity <= 10^3
Sample Input
3
60 100 120
10 20 30
50
Sample Output
220
Explanation
Pick 2nd and 3rd item with weight 20 and 30 and profit 100 and 120.*/

int zeroOneKnapsack(int val[], int weight[], int n, int capacity){
  int dp[1001][1001] = {0}; 

    
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weight[i - 1] <= w) {
                
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i - 1]] + val[i - 1]);
            } else {
              
                dp[i][w] = dp[i - 1][w];
            }
        }
    }


    return dp[n][capacity];
}
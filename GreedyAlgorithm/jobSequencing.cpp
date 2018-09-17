#include <bits/stdc++.h>
using namespace std;
//GEEKSFORGEEEKS PROBLEM LINK - "https://practice.geeksforgeeks.org/problems/job-sequencing-problem/0"

//declaration of structure
typedef struct job
{
    int deadline;
    int profit;
    int id;
}job;

//Sorting according to descending order of profits
//If same profit then sort according to ascending deadline 
bool sortingAlgo(job a, job b)
{
    if(a.profit>b.profit || a.profit<b.profit)
        return a.profit>b.profit;
    else
        return a.deadline<b.deadline;
}
int main() {
    
	int testNum,i,j,jobNum,profit,jobsCompleted;
	job jobsListed[1000];
	
	cin>>testNum;
	
	while(testNum--)
	{
	    profit = 0;
	    jobsCompleted = 0;
	    vector<bool> timeSlotAvailable(1000,true);
	    
	    cin>>jobNum;
	    
	    for(i=0;i<jobNum;i++)
	    {
	        cin>>jobsListed[i].id;
	        cin>>jobsListed[i].deadline;
	        cin>>jobsListed[i].profit;
	    }
	    
	    //sorting the list of jobs
	    sort(jobsListed,jobsListed+jobNum,sortingAlgo);
	    
	    for(i=0;i<jobNum;i++)
	    {
	           //for each job tries to book a slot by beginning from the deadline 
	           for(j=jobsListed[i].deadline;j>=0;j--)
	           {
	               if(timeSlotAvailable[j])
	               {
	                   timeSlotAvailable[j] = false;
	                   jobsCompleted++;
	                   profit+=jobsListed[i].profit;
	                   break;
	               }
	           }
	    }
	    cout<<jobsCompleted<<" "<<profit<<"\n";
	}
	return 0;
}

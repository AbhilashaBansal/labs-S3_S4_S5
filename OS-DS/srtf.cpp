#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <climits>
using namespace std;
#define pi pair<int,int>
#define pti pair <int, pair<int,int> > 

// 3) SRTF Scheduling Algorithm

bool myComp(pti p1, pti p2){
    if(p1.second.first==p2.second.first) 
        return p1.second.second <= p2.second.second;
    return p1.second.first < p2.second.first;
}

class customComp{
    public:
    bool operator () (pti p1, pti p2){
        // for max heap
        if(p1.second.second == p2.second.second)
            return p1.second.first > p2.second.first;
        return p1.second.second > p2.second.second;     
    }
};

int main() {
    int n;
    cin>>n;

    vector <pti> v;
    map <int, int> total_burst;
    vector <int> waiting_times(n, 0);
    vector <int> turnaround_times(n, 0);
    priority_queue <pti, vector<pti>, customComp> ready_queue;

    for(int i=0; i<n; i++){
        int arrival, burst;
        cin>>arrival>>burst;
        pti ele = make_pair(i+1, make_pair(arrival, burst));
        v.push_back(ele);
        total_burst[i] = burst;
    }

    sort(v.begin(), v.end(), myComp);

    cout<<left<<setw(10)<<"Time "<<setw(25)<<"ID of process in CPU"<<setw(25)<<"Remaining Burst Time";
    cout<<endl;

    int current_time=0;
    int it=0;
    
    while(it<n){
        while(it<n && v[it].second.first <= current_time){
            ready_queue.push(v[it]);
            it++;
        }
        if(!ready_queue.empty()){
            pti cur_proc = ready_queue.top();
            ready_queue.pop();
            int procid = cur_proc.first;
            int arrt = cur_proc.second.first;
            int bt = cur_proc.second.second;

            cout<<left<<setw(10)<<current_time<<setw(25)<<procid<<setw(25)<<bt; // remaining burst time
            cout<<endl;

            int diff = ((it==n)?INT_MAX:(v[it].second.first-current_time));
            if(diff>=bt){
                current_time += bt;
                turnaround_times[procid-1] = current_time-arrt;
                waiting_times[procid-1] = turnaround_times[procid-1] - total_burst[procid-1];
            }
            else{
                //update time differently
                int rem_time = bt-diff;
                current_time += diff;
                pti temp = make_pair(procid, make_pair(arrt, rem_time));
                ready_queue.push(temp);
            }

            // waiting_times[procid-1] = current_time-arrt;
            // turnaround_times[procid-1] = waiting_times[procid-1]+bt;   
        }
        else{
            cout<<left<<setw(10)<<current_time<<setw(25)<<"none"<<setw(25)<<"nil";
            cout<<endl;
            current_time = v[it].second.first;
        }
    }

    while(!ready_queue.empty()){
        //all processes have arrived already and have been stored into ready_queue, sorted basis (remaining) burst times
        //no new processes are coming, hence now this just works like the non-preemptive SJF algorithm
        pti cur_proc = ready_queue.top();
        ready_queue.pop();
        int procid = cur_proc.first;
        int arrt = cur_proc.second.first;
        int bt = cur_proc.second.second;

        cout<<left<<setw(10)<<current_time<<setw(25)<<procid<<setw(25)<<bt; // remaining burst time
        cout<<endl;

        current_time += bt;
        turnaround_times[procid-1] = current_time-arrt;
        waiting_times[procid-1] = turnaround_times[procid-1] - total_burst[procid-1];
    }

    cout<<"\nEnd Time: "<<current_time<<endl<<endl;

    // --> list of processes in ready queue, with arrival & burst times
    // At the end, show waiting and turnaround time for each process

    cout<<left<<setw(20)<<"Process ID"<<setw(20)<<"Waiting Time"<<setw(10)<<"Turnaround Time\n";
    for(int i=0; i<n; i++){
        cout<<left<<setw(20)<<i+1<<setw(20)<<waiting_times[i]<<setw(10)<<turnaround_times[i]<<endl;
    }
    cout<<endl;

    return 0;
}
 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;
#define pi pair<int,int>
#define pti pair <int, pair<int,int> > 

// 2) SJF Scheduling Algorithm
int current_time=0;

bool myComp(pti p1, pti p2){
    if(p1.second.first==p2.second.first) 
        return p1.second.second <= p2.second.second;
    return p1.second.first < p2.second.first;
}

class customComp{
    public:
    bool operator () (pti p1, pti p2){
        // for max heap
        int ar1 = p1.second.first;
        int ar2 = p2.second.first;
        if(p1.second.second == p2.second.second)
            return p1.second.first > p2.second.first;
        return p1.second.second > p2.second.second;     
    }
};

int main() {
    int n;
    cin>>n;

    vector <pti> v;
    vector <int> waiting_times(n);
    vector <int> turnaround_times(n);
    priority_queue <pti, vector<pti>, customComp> ready_queue;

    for(int i=0; i<n; i++){
        int arrival, burst;
        cin>>arrival>>burst;
        pti ele = make_pair(i+1, make_pair(arrival, burst));
        v.push_back(ele);
    }

    sort(v.begin(), v.end(), myComp);

    cout<<left<<setw(10)<<"Time "<<setw(25)<<"ID of process in CPU"<<setw(20)<<"Arrival Time"<<setw(20)<<"Burst Time";
    cout<<endl;

    int it=0;
    while(it<n){
        while(it<n && v[it].second.first<=current_time){
            ready_queue.push(v[it]);
            it++;
        }
        if(!ready_queue.empty()){
            // completing one process rn
            pti cur_proc = ready_queue.top();
            ready_queue.pop();
            int procid = cur_proc.first;
            int arrt = cur_proc.second.first;
            int bt = cur_proc.second.second;
            waiting_times[procid-1] = current_time-arrt;
            turnaround_times[procid-1] = waiting_times[procid-1]+bt;
            cout<<left<<setw(10)<<current_time<<setw(25)<<procid<<setw(20)<<arrt<<setw(20)<<bt;
            cout<<endl;
            current_time += bt;
        }
        else{
            cout<<left<<setw(10)<<current_time<<setw(25)<<"none"<<setw(20)<<"nil"<<setw(20)<<"nil";
            cout<<endl;
            current_time = v[it].second.first;
        }
    }

    while(!ready_queue.empty()){
        pti cur_proc = ready_queue.top();
        ready_queue.pop();
        int procid = cur_proc.first;
        int arrt = cur_proc.second.first;
        int bt = cur_proc.second.second;
        waiting_times[procid] = current_time-arrt;
        turnaround_times[procid] = waiting_times[procid]+bt;
        current_time += bt;
        cout<<left<<setw(10)<<current_time<<setw(25)<<procid<<setw(20)<<arrt<<setw(20)<<bt;
        cout<<endl;
    }
    cout<<"\nEnd Time: "<<current_time<<endl<<endl;

    // output format
    // At each context switch/ arrival of new job, print:
    // --> process getting cpu
    // --> list of processes in ready queue, with arrival & burst times
    // At the end, show waiting and turnaround time for each process

    cout<<left<<setw(20)<<"Process ID"<<setw(20)<<"Waiting Time"<<setw(10)<<"Turnaround Time\n";
    for(int i=0; i<n; i++){
        cout<<left<<setw(20)<<i+1<<setw(20)<<waiting_times[i]<<setw(10)<<turnaround_times[i]<<endl;
    }
    cout<<endl;

    return 0;
}
 

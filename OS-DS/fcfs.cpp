#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;
#define pi pair<int,int>
#define pti pair <int, pair<int,int> > 

// 1) FCFS Scheduling Algorithm

bool myComp(pti p1, pti p2){
    if(p1.second.first==p2.second.first) 
        return p1.second.second <= p2.second.second;
    return p1.second.first < p2.second.first;
}

int main() {

    // input
    int n;
    cin>>n;
    vector <pti> processes(n);
    for(int i=0; i<n; i++){
        int arrival_time, burst_time;
        cin>>arrival_time>>burst_time;
        processes[i] = make_pair(i+1, make_pair(arrival_time, burst_time));
    }

    //sorting the processes based on arrival time
    sort(processes.begin(), processes.end(), myComp);

    queue <pti> ready_queue;
    for(int i=0; i<n; i++){
        ready_queue.push(processes[i]);
    }

    vector <int> waiting_times(n);
    vector <int> turnaround_times(n);

    cout<<left<<setw(10)<<"Time "<<setw(25)<<"ID of process in CPU";
    cout<<endl;

    int cur_time = 0;
    while(!ready_queue.empty()){
        pti cur_proc = ready_queue.front();
        ready_queue.pop();
        int proc_getting_cpu = cur_proc.first;
        if(cur_time<cur_proc.second.first){
            cout<<left<<setw(10)<<cur_time;
            cout<<left<<setw(25)<<"none";
            cout<<endl;
            cur_time = cur_proc.second.first;
        }
        cout<<left<<setw(10)<<cur_time;
        cout<<left<<setw(25)<<proc_getting_cpu;
        // queue <pti> temp;
        // // cout<<left<<setw(20)<<"";
        // while(!ready_queue.empty()){
        //     pti ele = ready_queue.front();
        //     ready_queue.pop();
        //     temp.push(ele);
        //     cout<<"P"<<ele.first<<"("<<ele.second.first<<","<<ele.second.second<<") --> ";
        // }
        // ready_queue = temp;
        cout<<endl;
        int wait_time = cur_time-cur_proc.second.first;
        int ta_time = wait_time + cur_proc.second.second;
        waiting_times[proc_getting_cpu-1] = wait_time;
        turnaround_times[proc_getting_cpu-1] = ta_time;

        cur_time += cur_proc.second.second;
    }
    cout<<"\nEnd Time: "<<cur_time<<endl<<endl;
    // output format
    // At each context switch/ arrival of new job, print:
    // --> process getting cpu
    // --> list of processes in ready queue, with arrival & burst times
    // At the end, show waiting and turnaround time for each process

    float avg_waiting_time=0, avg_ta_time=0;
    cout<<left<<setw(20)<<"Process ID"<<setw(20)<<"Waiting Time"<<setw(10)<<"Turnaround Time\n";
    for(int i=0; i<n; i++){
        cout<<left<<setw(20)<<i+1<<setw(20)<<waiting_times[i]<<setw(10)<<turnaround_times[i]<<endl;
        avg_waiting_time+=waiting_times[i];
        avg_ta_time+=turnaround_times[i];
    }
    cout<<endl;
    avg_waiting_time /= n;
    avg_ta_time /= n;
    cout<<endl<<"Average Waiting Time: "<<avg_waiting_time<<endl;
    cout<<"Average Turnaround Time: "<<avg_ta_time<<endl<<endl;
    return 0;
}

// ABHILASHA BANSAL

#include <iostream>
#include<fstream>
#include<map>
#include<vector>
#include<string>
#include <queue>
using namespace std;


// Global Variables
int disp_time=0;
double fcfs_awt=0, fcfs_atat=0, spn_awt=0, spn_atat=0, pp_awt=0, pp_atat=0, prr_awt=0, prr_atat=0, ps_awt=0, ps_atat=0, srtf_awt=0, srtf_atat=0;


// Process Class
class process{
	public:
	string pid;
	int ar_t, ex_t, priority;
	int waiting_time, ta_time;
	process(string id, int a, int b, int c){
		pid=id;
		ar_t=a;
		ex_t=b;
		priority=c;
	}
};



// -------------------- 1) FCFS SCHEDULING -------------------- 
void fcfs(vector <process> Processes){
	cout<<"FCFS:\n";
	int cur_time = disp_time;
	for(int i=0; i<Processes.size(); i++){
		if(Processes[i].ar_t >= cur_time){
			cur_time = Processes[i].ar_t+disp_time;
		}
		cout<<"T"<<cur_time<<": "<<Processes[i].pid<<"("<<Processes[i].priority<<")\n";

		Processes[i].waiting_time = cur_time - Processes[i].ar_t;
		Processes[i].ta_time = Processes[i].waiting_time + Processes[i].ex_t;
		cur_time += (Processes[i].ex_t + disp_time);
	}
    cout<<endl;
    cout<<"Process Turnaround Time Waiting Time\n";
    for(int i=0; i<Processes.size(); i++){
    	fcfs_awt += Processes[i].waiting_time;
    	fcfs_atat += Processes[i].ta_time;
    	cout<<left<<setw(8)<<Processes[i].pid<<setw(16)<<Processes[i].ta_time<<Processes[i].waiting_time<<endl;
    }
    cout<<endl;
    fcfs_atat /= Processes.size();
    fcfs_awt /= Processes.size();
}




// -------------------- 2) SJF SCHEDULING (Shortest Job First) --------------------

class customComp{
    public:
    bool operator () (process P1, process P2){
        // for min heap
        int ar1 = P1.ar_t;
        int ar2 = P2.ar_t;
        if(P1.ex_t == P2.ex_t){
            if(P1.ar_t==P2.ar_t) return P1.pid>P2.pid;
            return P1.ar_t > P2.ar_t;
        }
        return P1.ex_t > P2.ex_t;     
    }
};


void sjf(vector <process> Processes){
	int n = Processes.size();
	priority_queue <process, vector<process>, customComp> ready_queue;
	map<string, int> waiting_times;
	map<string, int> turnaround_times;

	cout<<"SJF:\n";
	int cur_time = disp_time;
	int it=0;
    while(it<n){
        while(it<n && Processes[it].ar_t<=(cur_time-disp_time)) {
            ready_queue.push(Processes[it]);
            it++;
        }
        if(!ready_queue.empty()){
            // completing one process rn
            process cur_proc = ready_queue.top();
            ready_queue.pop();

            string procid = cur_proc.pid;
            int ar_t = cur_proc.ar_t;
            int et = cur_proc.ex_t;

            cout<<"T"<<cur_time<<": "<<procid<<"("<<cur_proc.priority<<")\n";
            waiting_times[procid] = cur_time-ar_t;
            turnaround_times[procid] = waiting_times[procid] + et;
            
            cur_time += (et+disp_time);
        }
        else{
            cur_time = Processes[it].ar_t;
        }
    }

    while(!ready_queue.empty()){
        process cur_proc = ready_queue.top();
        ready_queue.pop();

        string procid = cur_proc.pid;
        int ar_t = cur_proc.ar_t;
        int et = cur_proc.ex_t;

        cout<<"T"<<cur_time<<": "<<procid<<"("<<cur_proc.priority<<")\n";
        waiting_times[procid] = cur_time-ar_t;
        turnaround_times[procid] = waiting_times[procid] + et;
        cur_time += (et+disp_time);
    }
    cout<<endl;
    cout<<"Process Turnaround Time Waiting Time\n";
    for(int i=0; i<Processes.size(); i++){
    	Processes[i].waiting_time = waiting_times[Processes[i].pid];
    	Processes[i].ta_time = turnaround_times[Processes[i].pid];
    	spn_awt += Processes[i].waiting_time;
    	spn_atat += Processes[i].ta_time;
    	cout<<left<<setw(8)<<Processes[i].pid<<setw(16)<<Processes[i].ta_time<<Processes[i].waiting_time<<endl;
    }
    cout<<endl;
    spn_awt /= Processes.size();
    spn_atat /= Processes.size();
    return;
}



// -------------------- 3) SRTF Shortest Remaining Time First (Pre-emptive) --------------------
class customComp2{
    public:
    bool operator () (process P1, process P2){
        // for min heap
        int ar1 = P1.ar_t;
        int ar2 = P2.ar_t;
        if(P1.ex_t == P2.ex_t){
            if(P1.ar_t==P2.ar_t) return P1.pid>P2.pid;
            return P1.ar_t > P2.ar_t;
        }
        return P1.ex_t > P2.ex_t;     
    }
};
void srtf(vector <process> Processes){
    int n = Processes.size();
    priority_queue <process, vector<process>, customComp2> ready_queue;
    map<string, int> waiting_times;
    map<string, int> turnaround_times;
    map<string, int> total_burst;
    for(int i=0; i<n; i++) 
        total_burst[Processes[i].pid] = Processes[i].ex_t;

    cout<<"SRTF:\n";
    int cur_time = 0;
    int it=0;
    string prev_proc_id = "-1";
    while(it<n){
        while(it<n && Processes[it].ar_t<=(cur_time)) {
            ready_queue.push(Processes[it]);
            it++;
        }
        if(!ready_queue.empty()){
            // completing i unit of one process rn
            process cur_proc = ready_queue.top();
            ready_queue.pop();

            string procid = cur_proc.pid;
            int ar_t = cur_proc.ar_t;
            int et = cur_proc.ex_t;

            if(procid!=prev_proc_id){
                cur_time+=disp_time;
                cout<<"T"<<cur_time<<": "<<procid<<"("<<cur_proc.priority<<")\n";
                et--; cur_time++;
                if(et){
                    process intermediate(procid, ar_t, et, cur_proc.priority);
                    ready_queue.push(intermediate);
                }
                else{
                    //update waiting time & ta time
                    turnaround_times[procid] = cur_time-ar_t;
                    waiting_times[procid] = turnaround_times[procid] - total_burst[procid];
                }
                prev_proc_id = procid;
            }

            else{
                et--; cur_time++;
                if(et){
                    process intermediate(procid, ar_t, et, cur_proc.priority);
                    ready_queue.push(intermediate);
                }
                else{
                    //update waiting time & ta time
                    turnaround_times[procid] = cur_time-ar_t;
                    waiting_times[procid] = turnaround_times[procid] - total_burst[procid];
                }
            }
        }

        else{
            cur_time = Processes[it].ar_t;
        }
    }

    while(!ready_queue.empty()){
        process cur_proc = ready_queue.top();
        ready_queue.pop();

        string procid = cur_proc.pid;
        int ar_t = cur_proc.ar_t;
        int et = cur_proc.ex_t;

        if(procid!=prev_proc_id){
            cur_time+=disp_time;
            cout<<"T"<<cur_time<<": "<<procid<<"("<<cur_proc.priority<<")\n";
            et--; cur_time++;
            if(et){
                process intermediate(procid, ar_t, et, cur_proc.priority);
                ready_queue.push(intermediate);
            }
            else{
                //update waiting time & ta time
                turnaround_times[procid] = cur_time-ar_t;
                waiting_times[procid] = turnaround_times[procid] - total_burst[procid];
            }
            prev_proc_id = procid;
        }

        else{
            et--; cur_time++;
            if(et){
                process intermediate(procid, ar_t, et, cur_proc.priority);
                ready_queue.push(intermediate);
            }
            else{
                //update waiting time & ta time
                turnaround_times[procid] = cur_time-ar_t;
                waiting_times[procid] = turnaround_times[procid] - total_burst[procid];
            }
        }
    }
    cout<<endl;
    cout<<"Process Turnaround Time Waiting Time\n";
    for(int i=0; i<Processes.size(); i++){
        Processes[i].waiting_time = waiting_times[Processes[i].pid];
        Processes[i].ta_time = turnaround_times[Processes[i].pid];
        srtf_awt += Processes[i].waiting_time;
        srtf_atat += Processes[i].ta_time;
        cout<<left<<setw(8)<<Processes[i].pid<<setw(16)<<Processes[i].ta_time<<Processes[i].waiting_time<<endl;
    }
    cout<<endl;
    srtf_awt /= Processes.size();
    srtf_atat /= Processes.size();
    return;
}




// -------------------- 4) Priority Scheduling (Non-Preemptive) --------------------

class customComp3{
    public:
    bool operator () (process P1, process P2){
        // for min heap
        if(P1.priority == P2.priority){
            if(P1.ar_t==P2.ar_t) return P1.pid>P2.pid;
            return P1.ar_t > P2.ar_t;
        }

        return P1.priority > P2.priority;     
    }
};


void ps(vector <process> Processes){
	int n = Processes.size();
	priority_queue <process, vector<process>, customComp3> ready_queue;
	map<string, int> waiting_times;
	map<string, int> turnaround_times;

	cout<<"Priority Scheduling (Non-Preemptive):\n";
	int cur_time = disp_time;
	int it=0;
    while(it<n){
        while(it<n && Processes[it].ar_t<=(cur_time-disp_time)) {
            ready_queue.push(Processes[it]);
            it++;
        }
        if(!ready_queue.empty()){
            // completing one process rn
            process cur_proc = ready_queue.top();
            ready_queue.pop();

            string procid = cur_proc.pid;
            int ar_t = cur_proc.ar_t;
            int et = cur_proc.ex_t;

            cout<<"T"<<cur_time<<": "<<procid<<"("<<cur_proc.priority<<")\n";
            waiting_times[procid] = cur_time-ar_t;
            turnaround_times[procid] = waiting_times[procid] + et;
            
            cur_time += (et+disp_time);
        }
        else{
            cur_time = Processes[it].ar_t;
        }
    }

    while(!ready_queue.empty()){
        process cur_proc = ready_queue.top();
        ready_queue.pop();

        string procid = cur_proc.pid;
        int ar_t = cur_proc.ar_t;
        int et = cur_proc.ex_t;

        cout<<"T"<<cur_time<<": "<<procid<<"("<<cur_proc.priority<<")\n";
        waiting_times[procid] = cur_time-ar_t;
        turnaround_times[procid] = waiting_times[procid] + et;
        cur_time += (et+disp_time);
    }
    cout<<endl;
    cout<<"Process Turnaround Time Waiting Time\n";
    for(int i=0; i<Processes.size(); i++){
    	Processes[i].waiting_time = waiting_times[Processes[i].pid];
    	Processes[i].ta_time = turnaround_times[Processes[i].pid];
    	ps_awt += Processes[i].waiting_time;
    	ps_atat += Processes[i].ta_time;
    	cout<<left<<setw(8)<<Processes[i].pid<<setw(16)<<Processes[i].ta_time<<Processes[i].waiting_time<<endl;
    }
    cout<<endl;
    ps_awt /= Processes.size();
    ps_atat /= Processes.size();
    return;
}




// -------------------- 5) PP SCHEDULING (Pre-emptive Priority) --------------------

class customComp4{
    public:
    bool operator () (process P1, process P2){
        // for min heap
        if(P1.priority == P2.priority){
            if(P1.ar_t==P2.ar_t) return P1.pid>P2.pid;
            return P1.ar_t > P2.ar_t;
        }
        return P1.priority > P2.priority;     
    }
};


void pp(vector <process> Processes){
	int n = Processes.size();
	priority_queue <process, vector<process>, customComp4> ready_queue;
	map<string, int> waiting_times;
	map<string, int> turnaround_times;
	map<string, int> total_burst;
	for(int i=0; i<n; i++) 
		total_burst[Processes[i].pid] = Processes[i].ex_t;

	cout<<"PP:\n";
	int cur_time = 0;
	int it=0;
	string prev_proc_id = "-1";
    while(it<n){
        while(it<n && Processes[it].ar_t<=(cur_time)) {
            ready_queue.push(Processes[it]);
            it++;
        }
        if(!ready_queue.empty()){
            // completing i unit of one process rn
            process cur_proc = ready_queue.top();
            ready_queue.pop();

            string procid = cur_proc.pid;
            int ar_t = cur_proc.ar_t;
            int et = cur_proc.ex_t;

            if(procid!=prev_proc_id){
            	cur_time+=disp_time;
            	cout<<"T"<<cur_time<<": "<<procid<<"("<<cur_proc.priority<<")\n";
            	et--; cur_time++;
            	if(et){
            		process intermediate(procid, ar_t, et, cur_proc.priority);
            		ready_queue.push(intermediate);
            	}
            	else{
            		//update waiting time & ta time
            		turnaround_times[procid] = cur_time-ar_t;
                	waiting_times[procid] = turnaround_times[procid] - total_burst[procid];
            	}
            	prev_proc_id = procid;
            }

            else{
            	et--; cur_time++;
            	if(et){
            		process intermediate(procid, ar_t, et, cur_proc.priority);
            		ready_queue.push(intermediate);
            	}
            	else{
            		//update waiting time & ta time
            		turnaround_times[procid] = cur_time-ar_t;
                	waiting_times[procid] = turnaround_times[procid] - total_burst[procid];
            	}
            }
        }

        else{
            cur_time = Processes[it].ar_t;
        }
    }

    while(!ready_queue.empty()){
        process cur_proc = ready_queue.top();
        ready_queue.pop();

        string procid = cur_proc.pid;
        int ar_t = cur_proc.ar_t;
        int et = cur_proc.ex_t;

        if(procid!=prev_proc_id){
        	cur_time+=disp_time;
        	cout<<"T"<<cur_time<<": "<<procid<<"("<<cur_proc.priority<<")\n";
        	et--; cur_time++;
        	if(et){
        		process intermediate(procid, ar_t, et, cur_proc.priority);
        		ready_queue.push(intermediate);
        	}
        	else{
        		//update waiting time & ta time
        		turnaround_times[procid] = cur_time-ar_t;
            	waiting_times[procid] = turnaround_times[procid] - total_burst[procid];
        	}
        	prev_proc_id = procid;
        }

        else{
        	et--; cur_time++;
        	if(et){
        		process intermediate(procid, ar_t, et, cur_proc.priority);
        		ready_queue.push(intermediate);
        	}
        	else{
        		//update waiting time & ta time
        		turnaround_times[procid] = cur_time-ar_t;
            	waiting_times[procid] = turnaround_times[procid] - total_burst[procid];
        	}
        }
    }
    cout<<endl;
    cout<<"Process Turnaround Time Waiting Time\n";
    for(int i=0; i<Processes.size(); i++){
    	Processes[i].waiting_time = waiting_times[Processes[i].pid];
    	Processes[i].ta_time = turnaround_times[Processes[i].pid];
    	pp_awt += Processes[i].waiting_time;
    	pp_atat += Processes[i].ta_time;
    	cout<<left<<setw(8)<<Processes[i].pid<<setw(16)<<Processes[i].ta_time<<Processes[i].waiting_time<<endl;
    }
    cout<<endl;
    pp_awt /= Processes.size();
    pp_atat /= Processes.size();
    return;
}



// -------------------- 6) RR SCHEDULING (Round Robin) --------------------
void rr(vector <process> Processes){
	int n = Processes.size();
	queue <process> ready_queue;
	map<string, int> waiting_times;
	map<string, int> turnaround_times;
	map<string, int> total_burst;
	for(int i=0; i<n; i++) 
		total_burst[Processes[i].pid] = Processes[i].ex_t;

	cout<<"RR:\n";
	int cur_time = 0;
	int it=0;
	string prev_proc_id = "-1";
	ready_queue.push(Processes[it++]);

    while(it<n){
        if(!ready_queue.empty()){
            // completing i unit of one process rn
            process cur_proc = ready_queue.front();
            ready_queue.pop();
            while(it<n && Processes[it].ar_t<=(cur_time)) {
        	    ready_queue.push(Processes[it]);
            	it++;
       		}

            string procid = cur_proc.pid;
            int ar_t = cur_proc.ar_t;
            int et = cur_proc.ex_t;

            if(procid!=prev_proc_id){
            	cur_time+=disp_time;
            	cout<<"T"<<cur_time<<": "<<procid<<"("<<cur_proc.priority<<")\n";
            	int timeQuanta = 4; 	// (cur_proc.priority<3?4:2);
            	// cout<<timeQuanta<<"-";

            	if(et>=timeQuanta){
            		et -= timeQuanta;
            		cur_time += timeQuanta;
            	}
            	else{
            		cur_time += et;
            		et = 0;
            	}
            	// cout<<cur_time<<"-";
            	while(it<n && Processes[it].ar_t<=(cur_time)) {
        	    	ready_queue.push(Processes[it]);
            		it++;
       			}

            	if(et){
            		process intermediate(procid, ar_t, et, cur_proc.priority);
            		ready_queue.push(intermediate);
            	}
            	else{
            		// process is over,
            		// update waiting time & ta time
            		turnaround_times[procid] = cur_time-ar_t;
                	waiting_times[procid] = turnaround_times[procid] - total_burst[procid];
            	}
            	prev_proc_id = procid; // update procid of last executed process
            }

            else{
            	int timeQuanta = 4;		// (cur_proc.priority<3?4:2);

            	if(et>=timeQuanta){
            		et -= timeQuanta;
            		cur_time += timeQuanta;
            	}
            	else{
            		cur_time += et;
            		et = 0;
            	}

            	while(it<n && Processes[it].ar_t<=(cur_time)) {
        	    	ready_queue.push(Processes[it]);
            		it++;
       			}

            	if(et){
            		process intermediate(procid, ar_t, et, cur_proc.priority);
            		ready_queue.push(intermediate);
            	}
            	else{
            		// process is over,
            		//update waiting time & ta time
            		turnaround_times[procid] = cur_time-ar_t;
                	waiting_times[procid] = turnaround_times[procid] - total_burst[procid];
            	}
            }
        }

        else {
            cur_time = Processes[it].ar_t;
            ready_queue.push(Processes[it++]);
        }
    }

    while(!ready_queue.empty()){
        process cur_proc = ready_queue.front();
        ready_queue.pop();

        string procid = cur_proc.pid;
        int ar_t = cur_proc.ar_t;
        int et = cur_proc.ex_t;

        if(procid!=prev_proc_id){
        	cur_time+=disp_time;
        	cout<<"T"<<cur_time<<": "<<procid<<"("<<cur_proc.priority<<")\n";
        	int timeQuanta = 4; //(cur_proc.priority<3?4:2);

        	if(et>=timeQuanta){
        		et -= timeQuanta;
        		cur_time += timeQuanta;
        	}
        	else{
        		cur_time += et;
        		et = 0;
        	}

        	while(it<n && Processes[it].ar_t<=(cur_time)) {
        	    ready_queue.push(Processes[it]);
            	it++;
       		}

        	if(et){
        		process intermediate(procid, ar_t, et, cur_proc.priority);
        		ready_queue.push(intermediate);
        	}
        	else{
        		// process is over,
        		// update waiting time & ta time
        		turnaround_times[procid] = cur_time-ar_t;
            	waiting_times[procid] = turnaround_times[procid] - total_burst[procid];
        	}
        	prev_proc_id = procid; // update procid of last executed process
        }

        else{
        	int timeQuanta = 4; //(cur_proc.priority<3?4:2);

        	if(et>=timeQuanta){
        		et -= timeQuanta;
        		cur_time += timeQuanta;
        	}
        	else{
        		cur_time += et;
        		et = 0;
        	}

        	while(it<n && Processes[it].ar_t<=(cur_time)) {
        	    ready_queue.push(Processes[it]);
            	it++;
       		}

        	if(et){
        		process intermediate(procid, ar_t, et, cur_proc.priority);
        		ready_queue.push(intermediate);
        	}
        	else{
        		// process is over,
        		//update waiting time & ta time
        		turnaround_times[procid] = cur_time-ar_t;
            	waiting_times[procid] = turnaround_times[procid] - total_burst[procid];
        	}
        }
    }
    cout<<endl;
    cout<<"Process Turnaround Time Waiting Time\n";
    for(int i=0; i<Processes.size(); i++){
    	Processes[i].waiting_time = waiting_times[Processes[i].pid];
    	Processes[i].ta_time = turnaround_times[Processes[i].pid];
    	prr_awt += Processes[i].waiting_time;
    	prr_atat += Processes[i].ta_time;
    	cout<<left<<setw(8)<<Processes[i].pid<<setw(16)<<Processes[i].ta_time<<Processes[i].waiting_time<<endl;
    }
    cout<<endl;
    prr_awt /= Processes.size();
    prr_atat /= Processes.size();
    return;
}



// -------------------- SUMMARY FN --------------------
void summary(){
	cout<<left<<setw(16)<<"Algorithm"<<setw(26)<<"Average Turnaround Time"<<"Average Waiting Time\n";
	cout<<left<<setw(16)<<"1 FCFS"<<setw(26)<<fixed<<setprecision(2)<<fcfs_atat<<fixed<<setprecision(2)<<fcfs_awt<<endl;
	cout<<left<<setw(16)<<"2 SJF"<<setw(26)<<fixed<<setprecision(2)<<spn_atat<<fixed<<setprecision(2)<<spn_awt<<endl;
    cout<<left<<setw(16)<<"3 SRTF"<<setw(26)<<fixed<<setprecision(2)<<srtf_atat<<fixed<<setprecision(2)<<srtf_awt<<endl;
    cout<<left<<setw(16)<<"4 Priority"<<setw(26)<<fixed<<setprecision(2)<<ps_atat<<fixed<<setprecision(2)<<ps_awt<<endl;
	cout<<left<<setw(16)<<"5 PP"<<setw(26)<<fixed<<setprecision(2)<<pp_atat<<fixed<<setprecision(2)<<pp_awt<<endl;
	cout<<left<<setw(16)<<"6 Round Robin"<<setw(26)<<fixed<<setprecision(2)<<prr_atat<<fixed<<setprecision(2)<<prr_awt<<endl;
}



int main(int argc, char *argv[]){
    // ifstream f1(argv[1]);
    #ifndef ONLINE_JUDGE
        freopen("input2.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    string temp;
    cin>>temp>>temp>>disp_time>>temp;
    // cout<<disp_time;

    vector <process> Processes;
   
    cin>>temp;
    while(temp!="EOF"){
    	string id; int ar_t, ex_t, prio;
    	cin>>id>>temp>>ar_t>>temp>>ex_t>>temp>>prio>>temp>>temp;
    	process p(id, ar_t, ex_t, prio);
    	Processes.push_back(p);
    }

    // cout<<Processes.size()<<endl;
    int n = Processes.size();
    fcfs(Processes);
    sjf(Processes);
    srtf(Processes);
    ps(Processes);
    pp(Processes);
    rr(Processes);
    summary();
    return 0;
}

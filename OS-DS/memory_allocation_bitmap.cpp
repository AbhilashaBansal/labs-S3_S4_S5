// #include <bits/stdc++.h>
#include<iostream>
#include<map>
#include<string>
#include<iomanip>

using namespace std;
int main() {
    int siz=100;
    int ar[100]={0}; //array for bitmap

    map <string, pair<int, int> > occ;
    map <int, int> free;
    //initial state, when all blocks are free
    free[0] = 100;
    cout<<"1: Memory Allocation to Process\n";
    cout<<"2: Memory Deallocation on Process Termination\n";
    cout<<"3: Exit\n\n";

    int d; cin>>d;
    do{
        if(d==1){
            string id; 
            int mem_siz;
            cin>>id>>mem_siz;
            if(occ.count(id)){
                cout<<"Process ID already exists, memory not allocated again\n\n";
            }
            else {
                int start=-1;
                for(auto x: free){
                    if(x.second>=mem_siz){
                        start = x.first;
                        occ[id] = make_pair(start, mem_siz);
                        int diff = x.second-mem_siz;
                        if(diff) free[start+mem_siz]=diff;
                        break;
                    }
                }
                if(start==-1) cout<<"Insufficient memory\n\n";
                else {
                    for(int it=start; it!=start+mem_siz; it++) ar[it]=1;
                    free.erase(start);
                }
            }
        }
        else if(d==2){
            string id;
            cin>>id;
            if(occ.count(id)==0){
                cout<<"Process does not exist\n\n";
            }
            else{
                int st = occ[id].first;
                int mem_siz=occ[id].second;
                for(int it=st; it!=st+mem_siz; it++) ar[it]=0;
                occ.erase(id);
                if(free.count(st+mem_siz)){
                    free[st] = free[st+mem_siz]+mem_siz;
                    free.erase(st+mem_siz);
                }
                else{
                    free[st]=mem_siz;
                }
            }
        }

        //display
        cout<<"Allocated Memory\n";
        cout<<right<<setw(15)<<"Process ID"<<right<<setw(15)<<"Start Address"<<right<<setw(10)<<"Size"<<endl;
        for(auto x: occ){
            cout<<right<<setw(15)<<x.first<<right<<setw(15)<<x.second.first<<right<<setw(10)<<x.second.second<<endl;
        }
        cout<<"Free Memory\n";
        cout<<right<<setw(15)<<"Start Address"<<right<<setw(10)<<"Size"<<endl;
        for(auto x: free){
            cout<<right<<setw(15)<<x.first<<right<<setw(10)<<x.second<<endl;
        }
        cout<<endl;
        //displaying bitmap
        for(int it=0; it<siz; it++) cout<<ar[it]; 
        cout<<endl;
        //menu
        cout<<"1: Memory Allocation to Process\n";
        cout<<"2: Memory Deallocation on Process Termination\n";
        cout<<"3: Exit\n\n";
        cin>>d;
    }while(d!=3);

    return 0;
}

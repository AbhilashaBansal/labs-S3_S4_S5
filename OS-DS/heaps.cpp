#include <bits/stdc++.h>
using namespace std;

class Heap {
    public:
    vector <int> v;

    void upheapify(int idx){
        if(idx==0) return;

        int parent_id = (idx-1)/2;
        if(v[parent_id]<v[idx]){
            swap(v[parent_id], v[idx]);
            upheapify(parent_id);
        }
        return;
    }

    void insert(int key){
        v.push_back(key);
        upheapify(v.size()-1);
    }

    void downheapify(int idx){
        if(idx==v.size()-1) return;
        int leftc = 2*idx + 1;
        int rightc = 2*idx + 2;
        if(leftc>=v.size()) return;

        int largest_idx = idx;
        if(v[leftc]>v[largest_idx]){
            largest_idx = leftc;
        }
        if(rightc<v.size() && v[rightc]>v[largest_idx]){
            largest_idx = rightc;
        }

        if(largest_idx==idx) return; // no more down heapification needed

        swap(v[largest_idx], v[idx]);
        downheapify(largest_idx);
        return;
    }

    void deleteMax(){
        swap(v[0], v[v.size()-1]);
        v.pop_back();
        downheapify(0);
    }

    void increasePriority(int idx, int delta){
        v[idx] += delta;
        upheapify(idx);
    }

    void decreasePriority(int idx, int delta){
        v[idx] -= delta;
        downheapify(idx);
    }

    void display(){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
    Heap h;
    h.insert(10);
    h.insert(-100);
    h.insert(59);
    h.insert(23);
    h.insert(1);
    h.insert(1000); //up heapification (insertion)
    h.display();
    h.insert(-2);
    h.display();

    h.deleteMax(); //down heapification (deletion)
    h.display();

    h.increasePriority(3, 200);
    h.display();

    h.decreasePriority(4, 50);
    h.display();
    return 0;
}

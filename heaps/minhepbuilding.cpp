#include<iostream>
#include<vector>
using namespace std;
class Heap{
    vector<int>vec;
    public:
    void push(int val){
        vec.push_back(val);
        int x=vec.size()-1;
        int parnt=(x-1)/2;
        while(x>0 && vec[x]>vec[parnt]){
            
                swap(vec[parnt],vec[x]);
                x=parnt;
                parnt=(x-1)/2;
            }
        }
        
        
void heapify(int idx){
        int left=2*idx+1;
        int right=2*idx+2;
        int maxIdx=idx;
        int last=vec.size()-1;

        if(left<=last && vec[left]>vec[maxIdx]){
            maxIdx=left;
        }
        if(right<=last && vec[right]>vec[maxIdx]){
            maxIdx=right;
        }
        if(maxIdx!=idx){
            swap(vec[idx],vec[maxIdx]);
            heapify(maxIdx);
        }
    } 

    
    void pop(){
       swap(vec[0],vec[vec.size()-1]);
       vec.pop_back();
       heapify(0);

        }

    
    void top(){
        if(vec.empty()){
            cout<<"Heap is empty"<<endl;
            return;
        }
        cout<<vec[0]<<endl;
    }
    bool empty(){
        return vec.empty();
    }

};
int main(){
    Heap h;
    h.push(5);
    h.push(2);
    h.push(8);
    h.push(1);
    h.push(6);

    cout<<"Top element: ";
    h.top(); // Output: 1

    cout<<"Removing top element..."<<endl;
    h.pop();

    cout<<"Top element after pop: ";
    h.top(); // Output: 2

    return 0;
}

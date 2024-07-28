#include <bits/stdc++.h>
using namespace std;
class MaxHeap{
private:
    vector<int> v;

    int leftChild(int ind){
        return 2*ind+1;
    }

    int rightChild(int ind){
        return 2*ind+2;
    }

    int findParent(int ind){
        return (ind-1)/2;
    }

    void heapifyDown(int ind){
        int left = leftChild(ind);
        int right = rightChild(ind);
        int largest = ind;
        if(left < v.size() && v[left] > v[largest]){
            largest = left;
        }
        if(right < v.size() && v[right] > v[largest]){
            largest = right;
        }
        if(largest != ind){
            swap(v[ind], v[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int ind){
        int parent = findParent(ind);
        if(ind > 0 && v[parent] < v[ind]){
            swap(v[parent], v[ind]);
            heapifyUp(parent);
        }
    }

public:
    int top(){
        if(v.size() == 0){
            cerr << "Heap is empty!\n";
            return -1;
        }
        return v[0];
    }

    void pop(){
        if(v.size() == 0){
            cerr << "Heap is empty!\n";
            return ;
        }
        v[0] = v.back();
        v.pop_back();
        heapifyDown(0);
    }

    void push(int val){
        v.push_back(val);
        heapifyUp(v.size()-1);
    }

    int isEmpty(){
        return v.size() == 0;
    }
};

int main()
{
    MaxHeap pq;
    pq.push(1);
    pq.push(5);
    pq.push(-3);
    pq.push(4);
    pq.push(10);
    cout << pq.top() << "\n";
    pq.pop();
    cout << pq.top() << "\n";
    pq.pop();
    cout << pq.top() << "\n";
    pq.pop();
    cout << pq.top() << "\n";
    pq.pop();
    cout << pq.top() << "\n";
    return 0;
}
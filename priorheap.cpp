#include <iostream>
using namespace std;
class Heap{
public:
    int arr[100];
    int size = 0;
    void insert(){
        int val;
        cout<<"Enter the number: ";
        cin>>val;
        size++;
        int k = size;
        arr[k] = val;
        while(k > 1){
            int parent = k/2;
            if(arr[k] > arr[parent]){
                swap(arr[parent], arr[k]);
                k = parent;
            }
            else{
                return;
            }
        }
        cout<<"Element inserted\n";
    }
    int deletemax(){
        if(size == 0){
            cout<<"It's Empty\n";
            return -1;
        }
        int deleted = arr[1];
        arr[1] = arr[size];
        size--;
        heapify(1);  
        return deleted;
    }
    void heapify(int i){
        int max = i;
        int left = 2*i;
        int right = 2*i+1;
        if(left <= size && arr[left] > arr[max]){
            max = left;
        }
        if(right <= size && arr[right] > arr[max]){
            max = right;
        }
        if(max != i){
            swap(arr[max], arr[i]);
            heapify(max); 
        }
    }
    void display(){
        for(int i = 1; i <= size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
};

int main(){
    Heap heappq;
    while(true){
        cout<<"1.Insert\n";
        cout<<"2.Delete\n";
        cout<<"3.Display\n";
        cout<<"4.Exit\n";
        int a;
        cout<<"Enter your choice: ";
        cin>>a;
        switch(a){
            case 1:
                heappq.insert();
                break;
            case 2:
                cout<<heappq.deletemax()<<" Deleted\n";
                break;
            case 3:
                heappq.display();
                break;
            case 4:
                cout<<"Exiting\n";
                return 0;
            default:
                cout<<"Invalid choice\n";
        }
    }
    return 0;
}


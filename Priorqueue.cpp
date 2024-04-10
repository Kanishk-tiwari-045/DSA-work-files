// DEFINE
// A priority queue is an abstract data type that shows efficient 
// retrieval of the highest-priority element. In this, elements have 
// a priority, and the element with the highest priority is deleted first.

// DIFFERENCE
// 1.While a normal queue follows first-in, first-out approach,whereas a priority 
// queue shows the concept of prioritizing elements based on certain criteria.
// 2.Peek, when used in queue gives up the first element as its outcome whereas in prority
// queue it gives the maximum number present there.

#include <iostream>
using namespace std;
#define SIZE 10
class Queue{
    int queue[SIZE]; 
    int n=0;
public:
    void insert(){
        int ele;
        cout<<"Enter the element: ";
        cin>>ele;
        if(n<SIZE) {
            queue[n]=ele;
            n++;
            cout<<"Element inserted\n";
        }
        else{
            cout<<"It's Full\n";
        }
    }
    int deletemax(){
        if(n>0){
            int max=queue[0];
            int maxIndex=0;
            for(int i=1;i<n;i++){
                if(queue[i]>max){
                    max=queue[i];
                    maxIndex=i;
                }
            }
            for(int i=maxIndex;i<n-1;i++){
                queue[i]=queue[i+1];
            }
            n--;
            return max;
        }
        else{
            return -1;
        }
    }
    int peek(){
        if(n==0){
            return -1;
        }
        else{
            int max=queue[0];
            for(int i=1;i<n;i++){
                if(queue[i]>max){
                    max=queue[i];
                }
            }
            return max;
        }
    }
    void display(){
        if(n>0){
            cout<<"Elements: ";
            for(int i=0;i<n;i++){
                cout<<queue[i]<<" ";
            }
            cout<<"\n";
        }
        else{
            cout<<"It's Empty\n";
        }
    }
};
int main() {
    Queue pq;
    while(true){
        cout<<"1.Insert\n";
        cout<<"2.Delete\n";
        cout<<"3.Peek\n";
        cout<<"4.Display\n";
        cout<<"5.Exit\n";
        int a;
        cout<<"Enter your choice: ";
        cin>>a;
        switch(a){
            case 1:
                pq.insert();
                break;
            case 2: 
                cout<<pq.deletemax()<<" Deleted\n";
                break;
            case 3:
                cout<<pq.peek()<<"\n";
                break;
            case 4:
                pq.display();
                break;
            case 5:
                cout<<"Exiting\n";
                return 0;
            default:
                cout<<"Invalid choice\n";
        }
    }
}

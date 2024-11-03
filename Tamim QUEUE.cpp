#include<iostream>
using namespace std;

class CircularQueue{
    private:
        int*items;
        int front,rear,count,size;

    public:
      CircularQueue(int s){
        size=s;
        items=new int[size];
        for(int i=0; i<size; i++){
            items[i]=0;
        }
        front=-1;
        rear=-1;
        count=0;
      }
      CircularQueue(){
        delete[]items;
      }
      bool isFull(){
        return count==size;
      }
      bool isEmpty(){
        return count==0;
      }
      //Enqueue function
      void enqueue(int value, int pos=-1){
        if(isFull()){
            cout<<"Queue is Overflow!!"<<endl;
        }else{
            if(pos==-1){
                pos=(rear+1)%size;
            }
            if(pos<0||pos>=size){
                cout<<"Invalied Position sir!!"<<endl;
                return;
            }
            if(count==0){
                front=pos;
                rear=pos;
            }else{
                if(items[pos] !=0){
                   cout<<"Position already full!"<<endl;
                   return;
                }
                rear=pos;
            }
            items[rear]=value;
            count++;
            cout<<" Enqueued "<< value <<" at position "<<pos<<endl;
        }
      }
      //Dequeue function
      void dequeue(int pos=-1){
        if(isEmpty()){
            cout<<"Queue is underflow!" <<endl;
        }else{
            if(pos==-1){
                pos=front;
            }
            if(pos<0||pos>=size||items[pos]==0){
                cout<<"Invalid position or position empty!"<<endl;
                return;
            }
            cout<<" Dequeued "<<items[pos]<<" from position "<< pos <<endl;
            items[pos]=0;
            count--;

            if(count==0){
                front=-1;
                rear=-1;
            }else if(pos==front){
                front=(front+1)%size;
                while(items[front]==0 &&front !=rear){
                    front=(front+1)%size;
                }
            }
        }
      }

//Display function
      void display(){
        if(isEmpty()){
            cout<<"Queue is empty."<<endl;
        }else{
            cout<<"Queue elements:\n";
            for(int i=0; i<size;i++){
                cout<<" Position " << i <<" : ";
                if(items[i]==0){
                    cout<<"[-empty-]";
                }else{
                    cout<<items[i];
                }
                if(i==front){
                    cout<<" <-front";
                }
                if(i==rear){
                    cout<<" <-rear";
                }
                cout<<endl;
            }
        }
      }
};

//Main function
int main(){
    int queueSize;
    cout<<"Enter the size of the Queue: ";
    cin>>queueSize;

    CircularQueue q(queueSize);
    int choice,value,position;

    cout<<"Queue main function:\n";
    cout<<" 1.Enqueue\n 2.Dequeue\n 3.Display queue\n 4.Function exit\n";

    do{
        cout<<"Enter user choice: ";
        cin>>choice;
        switch(choice){
         case 1:
            cout<<"Enter value to enqueue: ";
            cin>>value;
            cout<<"Enter position(0 to " << queueSize-1 <<", or -1 for default rear position): ";
            cin>>position;
            q.enqueue(value, position);
         break;
         case 2:

            cout<<"Enter position to dequeue(0 to "<< queueSize-1 <<", or -1 for default front position): ";
            cin>>position;
            q.dequeue(position);
         break;
         case 3:
            q.display();
         break;
         case 4:
            cout<<"Function is exiting...\nHave a good day."<<endl;
         break;
         default:
         cout<<"Invalid choice sir! Please try again."<<endl;
        }
    }while(choice !=4);
    return 0;
}

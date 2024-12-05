#include<iostream>
using namespace std;

int main(){
    int queueSize;
    cout<<"Enter the size of the Queue: ";
    cin>>queueSize;

    int* items=new int[queueSize];
    int front=-1,rear=-1,count=0;
    for(int i=0;i<queueSize;i++){
        items[i]=0;
    }
    cout<<"Main function:\n";
    cout<<"1.Enqueue\n2.Dequeue\n3.Display queue list\n4.Exit program\n";

    int choice,v,pos;
    do{
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice==1){
            cout<<"Enter value: ";
            cin>>v;
            cout<<"Enter Position(0 to "<< queueSize-1 << ", -1 for default rear pos): ";
            cin>>pos;
            if(count == queueSize){
                cout<<"Overflow!!"<<endl;
            }else{
                if(pos==-1){
                    pos=(rear+1)%queueSize;
                }
                if(pos<0||pos>=queueSize){
                    cout<<"Invalid Position sir!"<<endl;
                }else if(count==0){
                    front=pos;
                    rear=pos;
                    items[rear]=v;
                    count++;
                    cout<<"Enqued "<< v <<" at Position "<<pos<<endl;
                }else if(items[pos] !=0){
                    cout<<"Position already full.!"<<endl;
                }else{
                    rear=pos;
                    items[rear]=v;
                    count++;
                    cout<<"Enqued "<< v <<" at Position "<<pos<<endl;
                }
            }
        }else if(choice==2){
            cout<<"Enter Position(0 to "<< queueSize-1 << ", -1 for default front pos): ";
            cin>>pos;
            if(count==0){
                cout<<"Underflow!!"<<endl;
            }else{
                  cout<<"dequeued "<< items[pos] <<" from Position "<<pos<<endl;
                  items[pos]=0;
                  count--;
                  if(count==0){
                    front=-1;
                    rear=-1;
                  }else if(pos==front){
                    front=(front+1)%queueSize;
                    while(items[front]==0 && front !=rear){
                        front=(front+1)%queueSize;
                    }
                  }
            }
        }else if(choice==3){
        if(count==0){
            cout<<"Queue is empty."<<endl;
        }else{
            cout<<"Queue elements:\n";
            for(int i=0;i<queueSize;i++){
                cout<<" Position "<< i <<" : ";
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
    }else if(choice==4){
        cout<<"Program is exiting...\nHave a good day."<<endl;
    }else{
        cout<<"Invalid choice! please try agein."<<endl;
    }
    }while(choice !=4);
    delete[]items;
return 0;
}

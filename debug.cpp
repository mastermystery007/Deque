// C++ implementation of De-queue using circular 
// array 
#include<iostream> 
using namespace std; 



class Dequeue{


int size;
int front;
int rear;
int* a ; 


public : 
	Dequeue(int size,int dv) 
	{ 
		front = -1; 
		rear = 0; 
        this->size = size;
        a = new int[size];    
        for(int i=0;i<size;i++){a[i]=dv;}
	} 
    
    Dequeue()
    {
        front= -1;
        rear= -1;
        size=100;
        a = new int[100];

    }
int getSize();

void pushFront(int data);
void pushRear(int data);

int popFront();
int popRear();

int getFront();
int getRear();

bool isEmpty();
bool isFull();

void resize();

void clear();

void resize(int length,int defaultVal);
void showElements();

int D(int index); 
};

int Dequeue::D(int index)
{   
    if(index>=size){cout<<"No such index exists"<<"\n";return 0;}
    
    else if(front==-1 && rear==-1 ){cout<<"The DQ is empty  ";}

    else if(index>(size-rear+front+1)){cout<<"Out of bounds ";}//TODO for front=-1 case

    else if(index<=front || index >=rear)
    {
    if(index>(front)){cout<<"elelment is="<<a[size-index+front]<<"\n";return a[size-index+front];} 
    
    else if(index<=front){cout<<"elelment is="<<a[index]<<"\n";return a[index];}
    }
    else{return 0;}
    
    return 0;
}

bool Dequeue::isFull(){
    if(front==size-1 && rear==-1){cout<<"DQ is full.."<<"\n";return true;}

    else if(front+1==rear){
        return true;
        
        }
      
    return false;
}

void Dequeue::pushRear(int key) 
{ 
    if (isFull()) {cout << "Overflow\n" << endl; return; } 
    if(rear=-1){rear=size-1;}
    else{rear = rear-1;} 
    
    cout<<"pushing "<<key <<" at postion "<<rear<<"\n";
	a[rear] = key ; 
} 

void Dequeue::pushFront(int key) 
{ 

	if (isFull())
    {   cout << "Overflow\n" << endl; 
		return;
    } 
    
    front = front+1; 
    
    cout<<"pushing "<<key <<" at postion "<<front<<"\n";
	a[front] = key ; 
}  

int Dequeue::getSize()
{
    cout<<"the size is"<<size;
    return size;
}

void Dequeue::resize(int newSize,int defaultValue)
{   
    int arr[newSize];
    
    if(newSize>size)
    {
    if(front>=0){
    for(int i=0;i<=(front);i++)
        {
        arr[i]=a[i];
        cout<<"pushing "<<a[i]<<"at position "<<i<<" to new array"<<"\n"; 
        }
    cout<<" finished pushing front "<<"\n";
    }
   if(rear>=0 && rear <=(size-1))
   {     for(int i=1;i<=size-rear;i++)
        {
          
        cout<<"rear elements of a are"<<a[size-i]<<"\n";
        
       
        } 
       
       
       int constan=size-rear;
        for(int i=1;i<=size-rear;i++)
        {
          
        arr[newSize-i]=a[size-i];
        int it=arr[newSize-i];  
        cout<<"pushing "<<a[i]<<"at position "<<i<<" to new array"<<"\n"; 
        }
  
   }
   
   
    for(int i=front+1;i<newSize-size+rear;i++)
    {
        int temp=i;
        arr[i]=defaultValue;
        cout<<"pushing "<<defaultValue<<"at position "<<i<<" to new array"<<"\n";
        cout<<" finished pushing default  "<<"\n";
    }
    
    this->a=arr;    
    this->size=newSize;
    front=-1;
    rear=front+1;
    }
    
} 

void Dequeue :: resize(){
    int newSize=size+200;
    int arr[newSize];
    if(front!=-1)
    {
    for(int i=0;i<=front;i++)
    {arr[i]=a[i];}
    }
   
    

    if(rear!=-1 && rear <=(size-1))
   {
        for(int i=1;i<=size-rear;i++)
        {
        arr[newSize-i]=a[size-i];
        cout<<"pushing "<<a[i]<<"at position "<<i<<" to new array"<<"\n"; 
        }
  
   }
    a=arr;
    size=newSize;
}
void Dequeue::showElements()
{

if(front!=-1)
    {
        for(int i=front;i>=0;i--)
        {
            cout<<"elements in order"<<a[i]<<"\t";

        }
         cout<<"rear done.."<<"\n";
        
    }
    if(rear!=-1){
        for(int i=rear;i<size;i++)
        {
            cout<<"elements in order"<<a[i]<<"\t";
            
        }
        cout<<"rear done.."<<"\n";
    }


    cout<<"All elements done";
    
   
}

int main() 
{ 
	Dequeue *dq = new Dequeue(); 
   
 
    dq->resize();
    dq->showElements();

	
	return 0; 
} 

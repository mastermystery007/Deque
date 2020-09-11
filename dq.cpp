// C++ implementation of De-queue using circular 
// array 
#include<iostream> 
using namespace std; 

// Maximum size of array or Dequeue 
#define MAX 100 

// A structure to represent a Deque 
class Deque 
{ 
	int *arr; 
	int front; 
	int rear; 
	int size; 

public : 
	Deque(int size,int defaultVal) 
	{ 
		front = -1; 
		rear = 0; 
		this->size = size; 
		arr = new int[size];  
		for(int i=0;i<size;i++){
			arr[i]=defaultVal;
		}
		
	} 
	Deque() 
	{ 
		front = -1; 
		rear = -1; 
		size=200;
		arr = new int[200];  
		
	} 

	// Operations on Deque: 
	void insertfront(int key); 
	void insertrear(int key); 
	int getFront(); 
	int getRear(); 
	bool isFull(); 
	bool isEmpty(); 
	int popFront(); 
	int popRear(); 
    //int D(int index); 
	int operator[] (int index);


    void showElements();
	void resize(int newSize,int defaultValue);
	void resize();
}; 

void Deque::showElements()
{
	cout<<"\n";
    cout<<"front is.."<<front<<"...and  ";
    cout <<"rear is.."<<rear<<"....";
	cout<<"\n";
    cout<<"size is.."<<size<<"\n";
  
   
	if(rear!=-1 )
	{
		for(int i=rear;i<=size-1;i++)
		{
		cout<<arr[i]<<"; ";
    	}
	cout<<"...";
	}
	
	if(front!=-1)
	{
		for(int i=0;i<=front;i++)
		{
        cout<<arr[i]<<"; ";
    	}
	cout<<"....";
	}
    	
	 cout<<"All elements done";
	
}

bool Deque::isFull() 
{ 
return ((front == size-1 && rear == -1)||front+1 == rear); 
} 


bool Deque::isEmpty () 
{ 
	return (front == -1 && rear==-1); 
} 


void Deque::insertfront(int key) 
{ 	cout<<"\n";
	cout<<"insert front called.. ";
	cout<< "front is "<<front << endl;
	if (isFull()) 
	{ 
	resize();	
	} 

	front++;
	arr[front] = key ; 
	cout << "front index  is "<<front << "...";
	cout << "rear index  is "<<rear << "...";
	cout << "value at front is "<<arr[front] << endl;
	cout<<"insert front finished.. ";

} 


void Deque ::insertrear(int key) 
{ 
	if (isFull()) 
	{ 
		resize(); 
	} 
	
	if (rear ==-1 && front!=size-1 ) {rear = size; }
	
	rear = rear-1; 
	
	arr[rear]= key ; 
	
	cout<<"rear index is "<< rear<<"\n";
} 

 
int Deque ::getFront() 
{ 
	 
	
 	if (front ==-1) 
	{
		cout << "No front elements exist" << endl; 
		return -1 ; 
	}		
	cout << " front elements is:" << endl; 
	cout<<arr[front];
	return arr[front];

} 

int Deque::getRear() 
{ 	
	
	if (rear==-1){ 
		cout << " rear is aldready empty" ; 
		return -1; } 
	else 
	{
		return arr[rear];
	}
	

	cout<<"value at rear after is"<<arr[rear]<<"\n";
} 


int Deque::popFront() 
{ 
	int fi=front;
	if (front==-1) 
	{ 
		cout << " No front elements exist" << endl; 
		return -1 ;}
	front--;
	cout << " returning" <<arr[fi]<< endl; 
	return arr[fi]; 
} 


int Deque::popRear() 
{ 
	int ri=rear;
	if(rear==-1 ) 
	{ 
		cout << " No rear elements exist" << endl; 
		return -1 ; 
	}

	if(rear==size-1)
	{	rear=-1;
		return arr[size-1];
	}
	rear++;
	cout<<"popping Rear";
	cout<<"rear value"<<rear<<"\n";
	cout << " returning" <<arr[ri]<< endl; 
	return arr[ri]; 
} 

int Deque::operator[] (int index)
{   int elements;
	if(rear==-1 && front==-1){elements=0;}
	else if(rear==-1){elements=front+1;}
	else if(front==-1){elements=size-rear;}
	else{elements=front+size-rear+1;}
  
  if(index<elements)
  {		
	  if(rear==-1 && front==-1)
	  {	cout<<"the DQ is empty ";
		  return -1;
	  }

	  else if(rear==-1)
	  {
		 
		  	cout<<"the index is"<<index<<" and the element is"<<arr[front-index];
			return arr[front-index];
            }
	else if(front==-1)
	{	cout<<"the index is"<<size-index-1<<" and the element is"<<arr[size-index-1];
		return arr[size-index-1];
	}

	else {
        if(index>(front)){
			cout<<arr[size-index+front]<<" is the element";
			return arr[size-index+front];}
        else{
			cout<<arr[front-index]<<" is the element";
			return arr[front-index];}
	 }
	
  }
  cout<<"\n"<<"not found..";
  return -1;
  }

void Deque::resize(int newSize,int defaultValue)
{   
    int *temp=new int [newSize];
	cout<<"\n"; 
    cout<<"front is.."<<front<<"\n";
    cout <<"rear is.."<<rear<<"\n";
	cout<<"size is.."<<size<<"\n";
    cout <<"new size is.."<<newSize<<"\n";
	int elements;
	if(rear==-1 && front==-1){elements=0;}
	else if(rear==-1){elements=front+1;}
	else if(front==-1){elements=size-rear;}
	else{elements=front+size-rear+1;}
    if(newSize>=elements)
	{
		for(int i=0;i<newSize;i++)
		{
			temp[i]=defaultValue;
		}	

	
		if(front>=0)
		{
    	for(int i=0;i<=(front);i++)
        {
        temp[i]=arr[i];
        cout<<"pushing "<<arr[i]<<"at position "<<i<<" to new array"<<"\n"; 
        }
    	cout<<" finished pushing front "<<"\n";
    	}

		if(rear>=0)
   		{   
		cout<<"pushing from rear to new array"<<"\n"; 
	   for(int i=1;i<=size-rear;i++)
        {
			temp[newSize-i]=arr[size-i];
			cout<<"pushing "<<arr[size-i]<<" at position "<<size-i<<" to new array "<<"\n"; 
		} 
		
		}

	arr=temp;    
	
    size=newSize;
	
    
    rear=front+1;
	cout<<" front is  "<<front<<"\n";
	cout<<" rear is  "<<rear<<"\n";
	
    }
	else if(newSize<elements)
	{cout<<"new size is less than elements";
		
		
		if(front!=-1 && rear ==-1)
		{
			for(int i=0;i<front;i++)
		{
			if(i<newSize){temp[i]=arr[i];}
		}

		}
		else if(front==-1 && rear!=-1)
		{
			for(int i=1;i<size-rear;i++)
			{
				
			if(newSize-i>=0){
			temp[newSize-i]=arr[size-i];
			cout<<"index"<<size-i<<"->"<<newSize-i<<" ";
			cout<<" ";	
			}
		}
		}
		else
		{
        for(int i=1;i<=size-rear;i++)
		{	
			if(i<newSize && newSize-i>front)
            {
            temp[newSize-i]=arr[size-i];
			cout<<"index"<<size-i<<"->"<<newSize-i<<" ";
			cout<<" ";
			}
		}

        for(int i=0;i<=front;i++)
		{
			if(i<newSize){temp[i]=arr[i];cout<<front<<"..front"<<arr[i]<<"..value";}
		}

		}
		
		
		arr=temp;    
		size=newSize;
		rear=front+1;
	}





} 

void Deque::resize()
{
	//when  we call this resize check for the rear pointer
	int newS=size+20;
 	int *temp=new int [newS];
	cout<<"\n"; 
    cout<<"front is.."<<front<<"\n";
    cout <<"rear is.."<<rear<<"\n";
	cout<<"size is.."<<size<<"\n";
    cout <<"new size is.."<<newS<<"\n";
   
			

	
		if(front!=-1)
		{
    	for(int i=0;i<=(front);i++)
        {
        temp[i]=arr[i];
        cout<<"pushing "<<arr[i]<<" at position "<<i<<" to new array"<<"\n"; 
        }
    	cout<<"..front.. "<<"\n";
    	}

		if(rear!=-1)
   		{   
	    cout<<"pushing from rear to new array"<<"\n"; 
	   for(int i=1;i<=size-rear;i++)
        {
			temp[newS-i]=arr[size-i];
			cout<<"pushing "<<arr[size-i]<<" at position "<<size-i<<" to new array "<<"\n"; 
		} 
		
		}

	arr=temp;    
	if(rear==-1){rear=-1;}
	else{rear=newS - size + rear;}

	
    size=newS;
	
    
    
	cout<<" front is  "<<front<<"& rear is  "<<rear<<"\n";
	cout<<" resizing complete"<<"\n";
}


int main() 
{ 
	Deque *dq = new Deque(); 
    dq->resize();
	dq->resize(5,3);
	dq->showElements();





	
	return 0; 
} 

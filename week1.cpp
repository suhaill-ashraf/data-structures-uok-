#include<iostream>
using namespace std;
class Array_Operations
{
	public:
void search(int arr[], int size)// function to search for a particular element
{
	
	int index,flag=0;
	int key;
	cout<<"Enter element to search"<<endl;
	cin>>key;

	for(int i=0;i<size;i++)
	{
		if(arr[i]==key)
		{
			flag=1;
			index=i;
			break;
		}
	}
	if(flag)
	{
	  cout<<"\n Element is present at index "<<index<<endl;
	}
	else
	{
	
		cout<<"Element not found"<<endl;
	}
}
void delete_element(int arr[], int &size) //function to delete any element
{
	 if (size == 0) {
        cout << "Array is empty!\n";
        return;
    }
	int position;
	cout<<"\n Enter the index you want to delete"<<endl;
	cin>>position;
	
	int key=arr[position];

	if(position<0 || position>size)
	{
		cout <<"invalid position"<<endl;
	}
	else
	{
		
		for(int i=position;i<size-1;i++)
		{
			arr[i]=arr[i+1];
			
		}
		size--;
		cout<<key<<" has been deleted"<<endl;
	
		
	}
	
	

	
}
void insert_element(int arr[], int &size)//function to insert at specific index
{
	int position,item;
	cout<<"\n Enter the index at which you want to insert the element"<<endl;
	cin>>position;
	cout<<"\n Enter teh element"<<endl;
	cin>>item;
	if(position<0 || position>size)
	{
		cout <<"invalid position"<<endl;
	}else
	{
		size++;
		for(int i=size;i>=position;i--)
		{
			arr[i]=arr[i-1];
		}
		arr[position]=item;
	}

	
}
void update(int arr[], int n)
{
	int index;
		cout<<"Enter the index"<<endl;
		cin>>index;
	if(index<0 || index>n)
	{
		cout<<"invalid index, Enter between (0 to "<<n<<")"<<endl;
		return;
	}
	else
	{
		int key;
		cout<<"Enter the element"<<endl;
		cin>>key;
		arr[index]=key;
	}
}




void display(int arr[], int size)
{
	cout<<"\n Elements of array are:"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<"\t "<<arr[i];
	}
}
};
int choice()
{
	int choice;
	cout<<"Enter 1 to search"<<endl;
	cout<<"Enter 2 to delete any element"<<endl;
	cout<<"Enter 3 to insert at any specific position"<<endl;
	cout<<"Enter 4 to to update any element"<<endl;
	cin>>choice;
	return choice; 
}
int main()
{
	int n;
	char ch;
	int arr[100];//maximum size is 100
	cout<<"Enter the size of array(less than  100)"<<endl;
	cin>>n;
	cout<<"\n Enter the elements of array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	Array_Operations obj; //creating object of Array_Operations class (obj)
	
	do{
		switch(choice()) // here choice() will be called which will return the operation specified by user 
		{
			case 1: obj.search(arr, n);
			break;
			
			case 2: obj.delete_element(arr,n);
				    obj.display(arr,n);
			break;
			
			case 3: obj.insert_element(arr,n);
					obj.display(arr,n);
			break;
			
			case 4: obj.update(arr,n);
			        obj.display(arr,n);
			break;
			
			default: cout<<"invalid operation"<<endl;
			break;
		}
		
		cout<<"\nwould you like to continue (Y/N)"<<endl;
		cin>> ch;
		
		   
	}while(ch=='Y' || ch=='y');
	
	
	
	
}
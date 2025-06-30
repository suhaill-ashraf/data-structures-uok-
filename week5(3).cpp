#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node* next;
		
		Node(int item)
		{
			next=nullptr;
			data=item;
		}
};

class stack
{
  private:
  	Node* top;

  public:
  	stack()
  	{
  		top=nullptr;
	}
	
	~stack()
	{
		while(top!=nullptr)
		{
			pop();
		}
	}
	
	void push()
	{
		int item;
		cout<<"Enter the element:"<<endl;
		cin>>item;
		Node* newnode=new Node(item);
		newnode->next=top;
		top=newnode;
		cout << item << " pushed onto the stack.\n";
		
		
	}
	void pop()
	{
		  if (top == nullptr)
		   {
            cout << "\nStack is empty. Cannot pop.\n";
            return;
           }
           
        Node* temp = top;
        cout << "\nDeleted element is: " << temp->data << endl;
        top = top->next;
        delete temp;
		  
	}
	
	  void peek() 
	  {
        if (top == nullptr) 
		{
            cout << "\nStack is empty. Nothing to peek.\n";
        } else
		{
            cout << "\nTop element is: " << top->data << endl;
        }
    }
    void show()
	 {
        if (top == nullptr) 
		{
            cout << "\nStack is empty.\n";
            return;
        }

        cout << "\nStack elements are:\n";
        Node* current = top;
        while (current != nullptr)
		{
            cout << current->data << endl;
            current = current->next;
        }
    }
  	
};
int main() 
{
    stack s;
    int option;

    do {
        cout << "\n----- Stack Menu -----";
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Display";
        cout << "\n4. Peek";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                s.push();
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.show();
                break;
            case 4:
                s.peek();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "\nInvalid choice. Enter a valid option.\n";
        }
    } while (option != 5);

    return 0;
}
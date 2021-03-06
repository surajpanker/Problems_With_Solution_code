Implement a Queue using Linked List.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer Q denoting the number of queries . 
A Query Q is of 2 Types
(i) 1 x   (a query of this type means  pushing 'x' into the queue)
(ii) 2     (a query of this type means to pop element from queue and print the poped element)
The second line of each test case contains Q queries seperated by space.

Output:
The output for each test case will  be space separated integers having -1 if the queue is empty else the element poped out from the queue . You are required to complete the two methods push which takes one argument an integer 'x' to be pushed into the quee  and pop which returns a integer poped out from othe queue.

Your Task:
Since this is a function problem, you don't need to take inputs. Just complete the provided functions. The printing is done automatically by the driver code.

Constraints:
1 <= T <= 100
1 <= Q <= 100
1 <= x <= 100

Example:
Input:
2
5
1 2 1 3 2 1 4 2
4
1 2 2 2 1 3  
Output:
2 3
2 -1

Explanation:
Testcase1: In the first testcase
1 2    the queue will be {2}
1 3    the queue will be {2 3}
2       poped element will be 2 the queue will be {3}
1 4    the queue will be {3 4}
2       poped element will be 3.
Testcase 2: In the second testcase 
1 2   the queue will be {2}
2      poped element will be {2} then the queue will be empty. 
2      the queue is empty and hence -1
1 3   the queue will be {3}.

/*
Note:The Input/Ouput format and Example given are used for system's internal purpose,
and should be used by a user for Expected Output only. As it is a function problem,
hence a user should not read any input from stdin/console. 
The task is to complete the function specified, and not to write the full code.

code approact :- 
mY approach is first we create node  Each time .then go contiously increasing rear;
then pop() method so logically if we cover some edge cases that 
first rear ==null then ans=null
second front = null rear =null <= this is my best case beacsue withour included it we get segmentstion fault
so lets implemet==>
*/
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};



int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        MyQueue *sq = new MyQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }
    }
    
    /*
    The :: (scope resolution) operator is used to get hidden names due to variable scopes so 
    that you can still use them. 
    
    for example=>
    #include <iostream>
using namespace std;
class X {
   public:
   static int count;
};
int X::count = 10;  // define static data member

int main () {
   int X = 0;   // hides class type X
   cout << X::count << endl;   // use static member of class X
}

You can also use the scope resolution operator to use class names or class member names. 
If a class member name is hidden, you can use it by prefixing it with its class name and the class scope operator
*/
    void MyQueue:: push(int x)
   {   
          
        QueueNode *newNode =new QueueNode(x);
        if(front==NULL)
          {
              rear=newNode;
              front=newNode;
              
          }
         else{
             rear->next=newNode;
             rear=newNode;
         }
        
        
}

/*The method pop which return the element
  poped out of the queue*/
int MyQueue :: pop()
{
       int ans; 
        
        if(rear==NULL)
           ans= -1;
          
         else{
             ans=front->data;
             front=front->next;
            } 
            if(front==NULL)
             rear=NULL;
             
           return ans;   
}




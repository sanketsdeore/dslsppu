#include <iostream>
using namespace std;
#define max 50

class Queue
{
    public:
        int arr[max];
        int start=-1;
        int end=-1;
        
        void enqueue(int x);
        int dequeue();
        void display();
};

void Queue::enqueue(int x)
{
    if (end==max-1)
    {
        cout<<"Queue Full!";
        return;
    }
    arr[++end]=x;
}

int Queue::dequeue()
{
    if (start==end)
    {
        cout<<"Queue Empty!";
    }
    return arr[++start];
}

void Queue::display()
{
    if (start==end)
    {
        cout<<"Queue Empty!";
        return;
    }
    cout<<"Job Queue: ";
    for(int i=start+1; i<=end; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void add_job(Queue &q, int job)
{
    q.enqueue(job);
}

void delete_job(Queue &q)
{
    q.dequeue();
}

int main()
{
    Queue job_line;
    add_job(job_line, 4);
    add_job(job_line, 5);
    add_job(job_line, 34);
    add_job(job_line, 43);
    add_job(job_line, 45);
    add_job(job_line, 63);
    add_job(job_line, 67);
    job_line.display();
    delete_job(job_line);
    delete_job(job_line);
    job_line.display();
    
    return 0;
}

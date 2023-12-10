#include<iostream>
using namespace std;

class CQueue{
public:
	const static int m = 5;
	int array[m];
	int front = -1;
	int rear =-1;

	bool isFull(){
		return (front == 0 and rear == m-1) || (rear == front -1);
	}

	bool isEmpty(){
		return (front == -1 and rear == -1);
	}

	void enqueue(int x){
		if(isFull()){
			cout << "CQueue Overflow" << endl;
			return;
		}

		if(front == -1){
			front = 0;
			rear = 0;
		}else{
			if(rear == m -1 ){
				rear = 0;
			}
			else{
				rear++;
			}

			// rear = (++rear) % m;
		}

		array[rear] = x;
		// cout << "Rear is " << rear << endl;
	}

	void dequeue(){
		if(isEmpty()){
			cout << "CQueue Underflow" << endl;
			return;
		}

		if(front == rear){
			front = -1;
			rear = -1;
		}else{
			if(front == m-1){
				front = 0;
			}else{
				front++;
			}
		}
	}

	void display(){
		if(isEmpty()){
			cout << "CQueue Underflow" << endl;
			return;
		}

		cout << "\nCQueue contains: ";

		if(front==rear){
			cout << array[front];
		}else if(front < rear){
			for(int i = front; i <= rear; i++){
				cout << array[i] << " ";
			}
		}else{
			for(int i = front; i < m; i++){
				cout << array[i] << " ";
			}
			for(int i = 0; i <= rear; i++){
				cout << array[i] << " ";
			}
		}
	}
};

int main(){
	CQueue cq;
	cq.enqueue(10);
	cq.enqueue(12);
	cq.enqueue(16);
	cq.enqueue(28);
	cq.enqueue(1);

	cq.dequeue();
	cq.dequeue();
	cq.dequeue();

	cq.enqueue(89);

	cq.display();
}

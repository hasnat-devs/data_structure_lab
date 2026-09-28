#include <iostream>
using namespace std;
int main()
{
	
int total,highest = 0 ,lowest = 1000;
float avg;
int arr[8];
cout <<"Enter Marks of 8 Students: "<<endl;
	for(int i = 0 ; i < 8 ; i++){
		cout <<"Enter marks of Student no " << i+1 <<": ";
		cin >> arr[i];
		total = total + arr[i];
		if(arr[i] > highest){
			highest = arr[i];
		}
		if(arr[i] < lowest){
			lowest = arr[i];
		}
	}
	
	cout<<"Details"<<endl;
	cout <<"Total Numbers of Students are : " <<total<<endl;
	cout<<"Average : " << total/8.0 << endl;
	cout << "Highest : " << highest<<endl;
	cout << "Lowest : " << lowest << endl;
	
	
return 0;
	
}

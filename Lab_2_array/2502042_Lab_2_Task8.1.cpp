#include <iostream>
using namespace std;
int main()
{
int n,position,value;
	
int arr[10];
cout <<"Enter number of Elements needed between 1 and 10: ";
cin >> n;
	for(int i = 0 ; i < n ; i++){
		cout << i+1 <<": ";
		cin >> arr[i];
	}
	
	cout<<"\nArray Elements!\n";
	for(int i = 0 ; i < n ; i++){
		cout << i <<" : "<<arr[i] <<endl;
		
	}
	cout << "enter index to update value: " ;
	cin >> position;
	if(position > 0 && position < n){
		cout << "Enter Value to Enter: ";
		cin >> value;
		arr[position] = value;
	
		
	}
	else{
		cout << "Invalid Position!";
	}
	
	cout<<"\nArray Elements after Updation !\n";
	for(int i = 0 ; i < n ; i++){
		cout << i <<" : "<<arr[i] <<endl;
		
	}
return 0;
	
}

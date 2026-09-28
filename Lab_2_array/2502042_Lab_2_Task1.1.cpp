#include <iostream>
using namespace std;
int main()
{
	
	
int arr[10];
cout <<"Enter 10 Elements: "<<endl;
	for(int i = 0 ; i < 10 ; i++){
		cout << i+1 <<": ";
		cin >> arr[i];
	}
	
	cout<<"\nArray Elements!\n";
	for(int i = 0 ; i < 10 ; i++){
		cout << i <<" : "<<arr[i] <<endl;
		
	}
	
return 0;
	
}


















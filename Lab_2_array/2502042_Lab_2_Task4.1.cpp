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
	
	cout<<"\nArray Elements in Forwant Direction!\n";
	for(int i = 0 ; i < 10 ; i++){
		cout <<arr[i] <<"\t";
		
	}
	cout << "\n\n";
	cout<<"\nArray Elements in Reverse Direction!\n";
	for(int i = 9 ; i >= 0 ; i--){
		cout <<arr[i] <<"\t";
		
	}
return 0;
	
}

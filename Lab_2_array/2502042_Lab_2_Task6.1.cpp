#include <iostream>
using namespace std;
int main()
{
int n,position;
	
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
	cout << "Enter index to delete: " ;
	cin >> position;
	if(position > 0 && position < n){
		for(int i = position; i< n; i++){
			arr[i] = arr[i+1];
			
		}
		n--;
	
	}
	else{
		cout << "Invalid Position!";
	}
	
	cout<<"\nArray Elements after Deletion !\n";
	for(int i = 0 ; i < n ; i++){
		cout << i <<" : "<<arr[i] <<endl;
		
	}
return 0;
	
}

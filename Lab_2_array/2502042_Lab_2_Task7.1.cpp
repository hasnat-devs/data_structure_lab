#include <iostream>
using namespace std;
int main()
{
int n,value,index;
bool found = false;
	
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
	cout << "Enter value to Search: " ;
	cin >> value;
	for(int i = 0; i<n ; i++){
		if(arr[i] == value){
			index = i;
			found = true;
			cout<< value << " is at " << index << " index";
			break;
		}
		else{
			"Value is not Found!";
		}
	}
return 0;
	
}

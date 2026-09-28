#include <iostream>
using namespace std;
int main()
{
int even = 0, odd = 0;
	
int arr[10];
cout <<"Enter 10 Elements: "<<endl;
	for(int i = 0 ; i < 10 ; i++){
		cout << i+1 <<": ";
		cin >> arr[i];
		if(arr[i] %2 == 0){
			even++;
		}
		else{
			odd++;
		}
	}
	
	cout<<"\nThere are " << even << " Evens and " <<odd <<" odds \n";

	
return 0;
	
}












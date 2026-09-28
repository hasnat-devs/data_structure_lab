#include <iostream>
using namespace std;
int main()
{
	
int length;
cout << "How many integers you want to Store? ";
cin >> length;
int *arr = new int[length];
cout <<"Enter " << length << " Elements: "<<endl;
	for(int i = 0 ; i < length ; i++){
		cout << i+1 <<": ";
		cin >> arr[i];
	}
	
	cout<<"\nArray Elements!\n";
	for(int i = 0 ; i < length ; i++){
		cout << i <<" : "<<arr[i] <<endl;
		
	}
	delete[] arr;
return 0;
	
}

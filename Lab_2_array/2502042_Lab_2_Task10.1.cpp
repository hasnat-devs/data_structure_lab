#include <iostream>
using namespace std;
int main()
{
int arr[2][2][2]; 



	for(int i = 0; i<2;i++){
		for(int j = 0; j<2; j++){
			for(int k = 0; k<2;k++){
				cout<<"enter value of Layer: "<< i+1 << " row: " << j+1 << " and column: " << k+1<<": ";
				cin >> arr[i][j][k];
			}
		}
		
	}

for(int i = 0; i<2;i++){
	cout << "\nLayer # " << i+1; 
		for(int j = 0; j<2; j++){
			cout << endl;
			for(int k = 0; k<2;k++){
				cout<<arr[i][j][k]<< "\t";
				
			}
		}
		
	}


return 0;
	
}

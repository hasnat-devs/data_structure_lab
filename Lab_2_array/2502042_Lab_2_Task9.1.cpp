#include <iostream>
using namespace std;
int main()
{
int sum = 0;
int arr[3][3] = {{1,2,3},
				{4,5,6},
				{7,8,9}};
				
	for(int i = 0; i<3;i++){
		for(int j = 0; j<3; j++){
			cout <<arr[i][j]<<"\t";
			sum = sum+arr[i][j];
		}
		cout << endl;
	}

cout << "\n The Sum of the matrix is: "<< sum;



return 0;
	
}

#include <bits/stdc++.h>
using namespace std;

void knap_sack(int max_weight, int weight[], int profit[], int n)
{
	int i, j;
	int arr[n+1][max_weight+1];
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= max_weight; j++) {
			if (i == 0 || j == 0)
				arr[i][j] = 0;
			else if (weight[i - 1] <= j)
				arr[i][j] = max(profit[i - 1]
								+ arr[i - 1][j - weight[i - 1]],
							arr[i - 1][j]);
			else
				arr[i][j] = arr[i - 1][j];
		}
	}

    for(int i = 0 ; i< n+1 ; i++){
        for (int j = 0 ; j<max_weight+1 ; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


	cout<<"Maximum profit is : " <<arr[n][max_weight]<<endl;

	i = n;
	j = max_weight;

	int op[n];
	int remaining_profit = arr[n][max_weight];

	while(i>0){
		if(arr[i][j] == arr[i][j-1]){			
			j--;
		}else{
			if(arr[i][j] == arr[i-1][j]){
				op[i-1] = 0;
				i--;
			}else{
				op[i-1] = 1;
				remaining_profit-=profit[i-1];								
				i--;
				for(int y= max_weight ; y>=0 ; y--){
					if(arr[i][y] == remaining_profit){
						j = y;
					}
				}
				if(remaining_profit ==0){
					break;
				}
			}
		}
	}

	while(i>0){
		op[i-1] = 0;
		i--;
	}

	for(int z = 0 ; z < n ; z++){
		cout<<op[z]<<" ";
	}


}

int main()
{
	int profit[] = {10,15,40};
	int weight[] = {1,2,3};
	int max_weight = 6;
	int n = sizeof(profit) / sizeof(profit[0]);

	knap_sack(max_weight, weight, profit, n);

	return 0;
}


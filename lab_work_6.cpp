//
// Created by ivan on 01.12.19.
//
#include<cassert>
#include <iostream>
#include <cmath>
#define minus false
#define plus true
using namespace std;



// prints from 1 to n
void print_compounds(int n)
{
	int cur_pos;

	for(int i =0; i < pow(2,n); i++)
	{
		cur_pos = i;

		for(int j = 1;j < n + 1; j++)
		{
			if((cur_pos & 1) == 1)
			{
				cout<<j<<" ";
			}
			cur_pos = cur_pos >> 1;
		}

		cout<<endl;
	}
}



int dp[100][100];
int f(int i,int j)
{
    if(dp[i][j] != 0)
    {
        return dp[i][j];
    }
    else if(j==0)
    {
        return dp[i][j] = 1;
    }
    else if(i==j)
    {
        return dp[i][j] = 1;
    }
    else
    {
        return dp[i][j] = f(i - 1,j) + f(i - 1,j - 1);
    }
}

void Newtons_binom(int power,bool sign = plus)
{
	for(int i =0;i<=power;i++)
	{
		f(power,i);

		if(sign == minus && i%2==1)
		{
			cout << " - " << dp[power][i] << " * a^" << power - i << "* b^" << i<<endl;
		}
		else
		{
			cout<< " + "<<dp[power ][i] << " * a^" << power - i << "* b^" << i<<endl;
		}
	}
}

int main()
{
  int n;
  cin>>n;
  print_compounds(n);
  cout<<endl;
  cout<<"Newtons bin :"<<endl;
  Newtons_binom(6,minus);

}

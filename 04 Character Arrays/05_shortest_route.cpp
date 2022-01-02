#include<bits/stdc++.h>
using namespace std;



int main(){

	char route[1000];
	cin.getline(route,1000);


	int x = 0;
	int y = 0;


	for(int i=0; route[i]!='\0'; i++){

		switch(route[i]){
			case 'N': x++;
					  break;

			case 'S': x--;
					 break;

			case 'E': y++;
					break;

			case 'W': y--;
					break;

		}
	}

	cout<<"Final x and y is "<<x<<","<<y<<"\n";
	
	
	if(x > 0)
	{
	    while(x != 0)
	    {
	        cout << 'N';
	        x--;
	    }
	}
	
	else if(x < 0)
	{
	    while(x != 0)
	    {
	        cout << 'S';
	        x++;
	    }
	}
	
	if(y > 0)
	{
	    while(y != 0)
	    {
	        cout << 'E';
	        y--;
	    }
	}
	
	else if(y < 0)
	{
	    while(y != 0)
	    {
	        cout << 'W';
	        y++;
	    }
	}
	

}

#include<bits/stdc++.h>

using namespace std;

vector<int> a, b, temp_a, temp_b, full_num;
int x, y, temp;

int main()
{
	int testcase,num;
	cin>>testcase;
	cin>>num;
	srand(time(NULL));
	for (int j=1;j<=testcase;j++)
	{
	full_num.clear();
	a.clear();
	b.clear();
	for(int i=1;i<=num;i++)
	{
		full_num.push_back(i);
	}
	cout<<full_num.size()<<endl;
	//system("pause");
	int flag = 0;
	x = rand() % num;
	temp = x;
	x = full_num.at(x);
	a.push_back(x);
	full_num.erase(full_num.begin()+temp);
	y = rand() % num;
	temp = y;
	y = full_num.at(y);
	a.push_back(y);
	b.push_back(y);
	full_num.erase(full_num.begin()+temp);
	cout<<x<<" "<<y<<endl;
	for(int i=1;i<num-1;i++)
	{
	x = rand() % a.size();
	x = a.at(x);
	y = rand() % full_num.size();
	temp = y;
	y = full_num.at(y);
	full_num.erase(full_num.begin()+temp);
	a.push_back(y);
	b.push_back(y);
	cout<<x<<" "<<y<<endl;
	}
	}	
	return 0;	
}

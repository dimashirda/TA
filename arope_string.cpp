#include <iostream>
using namespace std;

int main()
{
	string st;
	cin >> st;
	int Q, type;
	cin >> Q;
	while( Q-- ) {
		int x, y;
		cin >> type;
		if ( type == 3 ) {
			cin >> y;
			cout << st[y] << endl;
		} else {
			cin >> x;
			cin >> y;
			string str(st.begin()+x, st.begin()+y+1);
			st.erase(st.begin()+x, st.begin()+y+1);
			if ( type == 1 ) {
				st = str + st;
			} else {
				st = st + str;
			}
		}
	}
	return 0;
}
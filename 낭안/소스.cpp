#include <iostream>
#include <stack>
#include <queue>
using namespace std;


int main() {
	int a, b, c = 1, cc = 0, count = 0, ii = 0;
	cin >> a;
	bool asd = false;

	stack<int>s1;
	stack<int>s2;
	stack<int>s3;
	queue<char>f;

	if (a == 1) {
		cin >> a;
		cout << '+' << '\n' << '-';
	}

	for (int i = 0; i < a; i++) {
		cin >> b;
		s1.push(b);
	}
	for (int i = 0; i < a; i++) {
		s2.push(s1.top());
		s1.pop();
	}


	for (int i = 1; i <= a; i++) {
		if (ii != 1) {
			if (s2.top() != i) {
				s3.push(i);
				f.push('+');
			}
			else {
				f.push('+');
				f.push('-');

				s2.pop();
				do {
					if (s2.top() == i - c) {
						s2.pop();
						s3.pop();
						f.push('-');

						c++;
					}
					cc++;
				} while (c != cc);
				i--;
				ii = 1;
				c = 1;
				cc = 0;
			}
		}
		else {
			ii = 0;
		}	
	}
	
	for (int i = 0; i < s3.size(); i++) {
		f.push('-');
	}
	a = f.size();
	if (s3.size() != 0) {
		for (int i = 0; i < s3.size(); i++) {
			if (s3.top() != s2.top()) asd = true;
			s3.pop();
			s2.pop();
		}
	}
	if (asd != true) {
		
		for (int i = 0; i < a; i++) {
			cout << f.front() << '\n';
			f.pop();
		}
	}
	else cout << "NO";

	return 0;
}
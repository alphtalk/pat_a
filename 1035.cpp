/*

最初版本

#include<cstdio>
#include<cstring>
int main() {
	int n, count = 0,k=0;
	char p_id[1005][12];
	char p_pass[1005][12];
	scanf("%d", &n);
	char id[12],password[12];
	bool isModified = false;
	for (int i = 0; i < n; i++) {
		scanf("%s", id);
		scanf("%s", password);
		int len = strlen(password);
		for (int j = 0; j < len; j++) {
			if (password[j] == '0') {
				isModified = true;
				password[j] = '%';
			}
			if (password[j] == 'l') {
				isModified = true;
				password[j] = 'L';
			}
			if (password[j] == 'O') {
				isModified = true;
				password[j] = 'o';
			}
			if (password[j] == '1') {
				isModified = true;
				password[j] = '@';
			}
		}
	
		if (isModified) {
			count++;
			for (int j = 0; j < strlen(password); j++) {
				p_pass[k][j] = password[j];
			}
			for (int j = 0; j < strlen(id); j++) {
				p_id[k][j] = id[j];
			}
			k++;
		}
		isModified = false;
	}
	if (count != 0) {
		printf("%d\n", count);
		for (int i = 0; i < k; i++) {
			printf("%s %s\n", p_id[i], p_pass[i]);
		}
	}
	else {
		if(n==1)	printf("There is 1 account and no account is modified");
		else printf("There are %d accounts and no account is modified", n);
	}
	return 0;
}

*/


/*
优化：
*/
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string name, s;
		cin >> name >> s;
		int len = s.length();
		int flag = 0;
		for (int j = 0; j < len; j++) {
			switch (s[j]) {
			case '1': s[j] = '@'; flag = 1; break;
			case '0': s[j] = '%'; flag = 1; break;
			case 'l': s[j] = 'L'; flag = 1; break;
			case 'O': s[j] = 'o'; flag = 1; break;
			}
		}
		if (flag) {
			string temp = name + " " + s;
			v.push_back(temp);
		}
	}
	int cnt = v.size();
	if (cnt != 0) {
		printf("%d\n", cnt);
		for (int i = 0; i < cnt; i++) {
			cout << v[i] << endl;
		}
	}
	else if (n == 1) {
		printf("There is 1 account and no account is modified");
	}
	else {
		printf("There are %d accounts and no account is modified", n);
	}
	return 0;
}
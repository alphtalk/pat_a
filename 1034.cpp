#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;
const int MAX = 2005;
map<string, int> Gang;//团伙头目，该团伙人数
map<string, int> name_id;//姓名对应的编号用map保存
map<int, string> id_name;//姓名对应的编号用map保存
int G[MAX][MAX] = { 0 }, weight[MAX] = { 0 };//不要忘记赋初值
bool vis[MAX] = { false };

int  n, k = 0;		//total_relation大于k才被视为犯罪团伙
int id = 0;	//姓名对应的id，从0开始
int change(string str) {
	if (name_id.find(str) != name_id.end()) {
		return name_id[str];
	}
	else {
		name_id[str] = id;	//双向都要赋值
		id_name[id] = str;
		return id++;
	}
}
void DFS(int nowVisit,int &head,int &num_Member,int &toal_relation){
	num_Member++;
	vis[nowVisit] = true;
	if (weight[nowVisit] > weight[head]) {//更新头目
		head = nowVisit;
	}
	for (int i = 0; i < id; i++) {
		if (G[nowVisit][i] > 0) {	//如果从nowvisit能到达i
			toal_relation += G[nowVisit][i];
			G[nowVisit][i] = G[i][nowVisit] = 0;
			if (vis[i] == false)
				DFS(i, head, num_Member, toal_relation);
		}
	}
}
void DFSblock() {
	for (int i = 0; i < id; i++) {
		if (vis[i] == false) {
			int head = i, num_Member = 0, total_relation = 0;
			DFS(i, head, num_Member, total_relation);
			if (num_Member > 2 && total_relation > k) {
				Gang[id_name[head]] = num_Member;
			}
		}
	}
}
int main() {
	int w;
	string s1, s2;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		cin >> s1 >> s2 >> w;
		int id1 = change(s1);
		int id2 = change(s2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}
	DFSblock();
	cout << Gang.size()<<endl;;
	map<string, int>::iterator it;
	for (it = Gang.begin(); it != Gang.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}
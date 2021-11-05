#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct Person {
	int index;
	int age;
	int id;
	char sex;
}typedef Person;

struct compare1 {
	bool operator()(Person p1, Person p2) {
		if (p1.sex != p2.sex) return p1.sex < p2.sex;
		else return p1.index > p2.index;
	}
};
struct compare2 {
	bool operator()(Person p1, Person p2) {
		if (p1.sex != p2.sex) return p1.sex > p2.sex;
		else return p1.index > p2.index;
	}
};


int N;
int id, age;
char sex;
priority_queue < Person, vector<Person>,compare1> old;
queue < pair<char,int>> child;
priority_queue < Person, vector<Person>,compare2> adult;


int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> id >> age >> sex;
		Person per;
		per.index = i;
		per.age = age;
		per.sex = sex;
		per.id = id;
		if (age <= 15) {
			child.push(make_pair(sex,id));
		}
		else if (age > 15 && age <= 60) {
			adult.push(per);
		}
		else {
			old.push(per);
		}
	}
	while (!old.empty()) {
		cout << old.top().id << endl;
		old.pop();
	}
	while (!child.empty()) {
		cout << child.front().second  << endl;
		child.pop();
	}
	while (!adult.empty()) {
		cout << adult.top().id << endl;
		adult.pop();
	}
	

}
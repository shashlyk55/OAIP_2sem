#include<iostream>
#include<list>
using namespace std;



struct node {
	node* next;
	node* prev;
	int elem;
};

void circle(int n, int k) {
	std::list<int> people;
	for (int i = 1; i <= n; i++) {
		people.push_back(i);
	}
	auto current = people.begin();
	while (people.size() > 1) {
		for (int i = 1; i < k; i++) {
			current++;
			if (current == people.end()) {
				current = people.begin();
			}
		}
		std::cout << "Removed person: " << *current << std::endl;
		current = people.erase(current);
		if (current == people.end()) {
			current = people.begin();
		}
	}
	std::cout << "Last person remaining: " << people.front() << std::endl;
}

void main() {
	node* head = NULL;
	node* last = NULL;
	setlocale(LC_ALL, "ru");
	int n, k;
	node* q;
	head = new(node);
	
	cout << "n = ";
	cin >> n;
	cout << "k = ";
	cin >> k;
	q = head;
	head->next = NULL;
	head->prev = NULL;
	for (int i = 1; i <= n; i++) {
		q->next = new(node);
		((q)->next)->prev = q;
		q = q->next;
		q->next = NULL;
		q->elem = i;
	}
	if (head->next != NULL) {
		(head->next)->prev = q;
		q->next = head->next;
	}
	else
		cout << "List is empty\n";


	if (head->next != NULL) {
		cout << (head->next)->elem << " ";
		q = (head->next)->next;

		while (q != head->next) {
			cout << q->elem << " ";
			q = q->next;
		}
	}
	else
		cout << "List is empty\n";

	if (head->next != NULL) {
		q = (head->next)->next;
		for (int i = 1;; i++) {
			if (i % k == 0) {
				(q->next)->prev = q->prev;//соедин€ем элемент после удал€емого звена и элемент перед удал€емым звеном
				(q->prev)->next = q->next;//соедин€ем элемент перед удал€емым звеном и элемент после удал€емого звена
				if (head->next == q)//если указанное звено находитс€ сразу после начала списка
					// ”дал€ем "первое" звено кольца.
					head->next = q->next;//удал€ем первое звено списка
				delete q;//удал€ем звено
			}


			q = q->next;
		}
	}
	else
		cout << "List is empty\n";

}
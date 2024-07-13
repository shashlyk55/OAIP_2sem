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
				(q->next)->prev = q->prev;//��������� ������� ����� ���������� ����� � ������� ����� ��������� ������
				(q->prev)->next = q->next;//��������� ������� ����� ��������� ������ � ������� ����� ���������� �����
				if (head->next == q)//���� ��������� ����� ��������� ����� ����� ������ ������
					// ������� "������" ����� ������.
					head->next = q->next;//������� ������ ����� ������
				delete q;//������� �����
			}


			q = q->next;
		}
	}
	else
		cout << "List is empty\n";

}
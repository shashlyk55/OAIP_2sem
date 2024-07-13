#include "Hash.h"
#include <iostream>
int HashFunction(int key, int size, int p)    //Хеш-функция
{
	srand(time(NULL));
	int f = key % 3;
	switch (f) {
	case 0:
		return (key + p) % size;
		break;
	case 1:
		return (int)(5 * ((0.6180339887499 * key) - int((0.6180339887499 * key))) + p) % size;
		break;
	case 2:
		return (key * (key + 1) + p) % size;
		break;
	}
}
//-------------------------------
int Next_hash(int hash, int size, int p)
{
	return (hash + 5 * p + 3 * p * p) % size;
}
//-------------------------------
Object create(int size, int(*getkey)(void*))
{
	return *(new Object(size, getkey));
}
//-------------------------------
Object::Object(int size, int(*getkey)(void*))
{
	N = 0;
	this->size = size;
	this->getKey = getkey;
	this->data = new AAA* [size];
	for (int i = 0; i < size; ++i)
		data[i] = NULL;
}
//-------------------------------
bool Object::insert(AAA* d)
{
	bool b = false;
	if (N != size) {
		
		for (int i = 0, t = getKey(d), j = HashFunction(t, size, 0);
			i != size && !b;  j = Next_hash(j, size, ++i)) {
			if (i == 0) {
				int j;
				switch (d->key % 3) {
				case 0:
					j = (d->key + i) % size;
					break;
				case 1:
					j = (int)(5 * ((0.6180339887499 * d->key) - int((0.6180339887499 * d->key))) + i) % size;
					break;
				case 2:
					j = (d->key * (d->key + 1) + i) % size;
					break;
				}
			}
			if (data[j] == NULL || data[j] == DEL)
			{
				data[j] = d;
				N++;
				b = true;
			}
		}
	}
	return b;
}
//-------------------------------
int Object::searchInd(int key)
{
	int t = -1;
	bool b = false;
	if (N != 0) {
		int j;
		switch (key % 3) {
		case 0:
			j = key % size;
			break;
		case 1:
			j = (int)(5 * ((0.6180339887499 * key) - int((0.6180339887499 * key)))) % size;
			break;
		case 2:
			j = (key * (key + 1)) % size;
			break;
		}
		for (int i = 0; data[j] != NULL && i != size && !b;) {
			if (i == 0) {
				
				switch (key % 3) {
				case 0:
					j = (key + i) % size;
					break;
				case 1:
					j = (int)(5 * ((0.6180339887499 * key) - int((0.6180339887499 * key))) + i) % size;
					break;
				case 2:
					j = (key * (key + 1) + i) % size;
					break;
				}
			}

			if (data[j] != DEL)
				if (getKey(data[j]) == key)
				{
					t = j; b = true;
				}
		}
	}
	return t;
}
//-------------------------------
void* Object::search(int key)
{
	int t = searchInd(key);
	return(t >= 0) ? (data[t]) : (NULL);
}
//-------------------------------
void* Object::deleteByKey(int key)
{
	int i = searchInd(key);
	AAA* t = data[i];
	if (t != NULL)
	{
		data[i] = DEL;
		N--;
	}
	return t;
}
//-------------------------------
bool Object::deleteByValue(void* d)
{
	return(deleteByKey(getKey(d)) != NULL);
}
//-------------------------------
void Object::scan(void(*f)(void*))
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << " Элемент" << i;
		if ((this->data)[i] == NULL)
			std::cout << "  пусто" << std::endl;
		else
			if ((this->data)[i] == DEL)
				std::cout << "  удален" << std::endl;
			else
				f((this->data)[i]);
	}
}
void Object::scan()
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << " Элемент" << i;
		if ((this->data)[i] == NULL)
			std::cout << "  пусто" << std::endl;
		else
			if ((this->data)[i] == DEL)
				std::cout << "  удален" << std::endl;
			else
				std::cout << " ключ " << ((AAA*)(this->data)[i])->key << " - " << ((AAA*)(this->data)[i])->mas << std::endl;

	}
}

void Object::resize() {
	for (int i = 0; i < this->size; i++)
	{
		std::cout << " Элемент" << i;
		if ((this->data)[i] == NULL)
			std::cout << "  пусто" << std::endl;
		else
			if ((this->data)[i] == DEL)
				std::cout << "  удален" << std::endl;
			else
				std::cout << " ключ " << ((AAA*)(this->data)[i])->key << " - " << ((AAA*)(this->data)[i])->mas << std::endl;

	}
}


#include <iostream>
#include <list>

using namespace std;

template<class T>
class lista{
private:
	list<T>* v;
public:
	lista(T *c,T *f){
		v = new list<T>(c,f);
	}
	~lista(){
		delete v;
	}

	T operator[](int e){
		typename list<T>::iterator it = v->begin();
		for(int i = 0; i < e; i++) it++;
		return *it;
	}

	T front(){
		return v->front();
	}
	T back(){
		return v->back();
	}
};

int main(){
	int vet[] = {1,2,3,4,5,6,7,8,9,10};
	lista<int> l(vet,vet+10);
	cout << l[3] << endl;
	return 0;
}

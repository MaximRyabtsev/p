#include <iostream>

struct String{
private:

	friend void test();

	int size;
	int capasity;
	char* str;

	void swap_(String& oth){
		std::swap(size, oth.size);
		std::swap(capasity, oth.capasity);
		std::swap(str, oth.str);
	}
public:

	String():
		size(0)
		,capasity(0)
		,str(nullptr)
	{}

	String(char* cstyle):
		size(0)
		,capasity(0)
	{
		for(; cstyle[size] != '\0'; ++size);
		str = new char[size];
		for(;capasity < size; str[capasity] = cstyle[capasity], ++capasity); 
	}

	String(const String& other):
		size(other.size)
		,capasity(other.capasity)
		,str(new char[capasity])
	{
		for(int i = 0; i < size; str[i] = other.str[i], ++i);
	}


	~String(){
		delete[] str;
	}

	void p() const{
		for(int i = 0; i < size; std::cout << str[i], ++i);
		std::cout << "\n";
	}

	bool operator<(const String& oth) const{
		if(oth.str == nullptr){
			if(str == nullptr) return 0;
			return 1;
		}
		for(int i = 0;i < oth.size;++i){
			if(size <= i) return 1;
			if(str[i] < oth.str[i]) return 1;
		}
		return 0;
	}

	bool operator==(const String& oth) const{
		if(size != oth.size) return 0;
		for(int i = 0; i < size; ++i){
			if(str[i] != oth.str[i]) return 0;
		}
		return 1;
	}

	String& operator=(const String& oth){
		String oth_(oth);
		if(!(oth_ == *this)) swap_(oth_);
		return *this;
	}

};

template <typename T>
void qs(T* arr, int size){
	if(size < 2) return;
	if(size == 2){
		if(arr[1] < arr[0]){
			T t = arr[0];
			arr[0] = arr[1];
			arr[1] = t;
		}
		return;
	}
	T bigger[size], smaller[size], mid = arr[size/2];
	int bsize = 0, ssize = 0;
	for(int i = 0; i < size; ++i){
		if(arr[i] < mid || arr[i] == mid){
			smaller[ssize] = arr[i];
			++ssize;
			continue;
		}
		bigger[bsize] = arr[i];
		++bsize;
	}
	qs(bigger, bsize); qs(smaller, ssize);
	for(int i = 0; i < ssize; ++i){
		arr[i] = smaller[i];
	}
	for(int i = 0; i < bsize; ++i){
		arr[i + ssize] = bigger[i];
	}
}

char bf(){

}

int main(){
	String d[5] = {"b", "c", "d", "a", "f"};
	qs(d, 5);
	for(int i = 0; i < 5; ++i){
		d[i].p();
	}
}

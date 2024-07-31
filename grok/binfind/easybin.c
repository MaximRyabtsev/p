#include <stdio.h>

char find(int* ptr, int size, int value, int* pos){
--size;
for(int i = 0, mid = (i + size)/2; i <= size; mid = (i+size)/2){
	if(ptr[mid] == value){
		*pos = ++ptr[mid];
		return 1;
	}
	if (ptr[mid] > value){
		size = --mid;
	}else if (ptr[mid] < value){
		i = ++mid;
	}
}
return 0;
}

int main(){
	int b[5] = {1,2,3,4,5};
	int pos;
	if(find(b,5,6,&pos) == 0) printf("1 - work\n");
	if(find(b,5,3,&pos) == 1) printf("2 - work\n");
}

#include <stdio.h>

void qs(int* ptr, int size){
	
	if(size < 2) return;
	int mid = ptr[size/2]; 
	int a[size], b[size-1], asize = 0, bsize = 0;
	for(int i = 0; i < size; ++i){
		if(mid > ptr[i]){
			a[asize] = ptr[i];
			++asize;
		}else if(mid < ptr[i]){
			b[bsize] = ptr[i];
			++bsize;
		}
		//при повторении чисел будут баги
	}
	qs(a, asize); qs(b, bsize);
	for(int i = 0; i < asize; ++i){
		ptr[i] = a[i];
	}
	ptr[asize] = mid;
	for(int i = 0; i < bsize; ++i){
		ptr[i + asize + 1] = b[i];
	}
}


int main(){
	int b[8] = {12,42,63,400,45, 0, 1, 2};
	qs(b,8);
	for(int i = 0; i < 8; ++i){
		printf("%d ",b[i]);
	}
}

/*************************************************************************
 > File Name: ans4.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Tue 02 Jul 2019 07:13:36 AM PDT
 ************************************************************************/

#include<iostream>
using std::cout;
using std::endl;
#define SWAP(a,b) {int temp; temp = a;a=b;b=temp;}
template<class T,class Compare = std::less<T>>
class HeapSort{
public:
	HeapSort(T *p,int size)
	:m_pdata(new T[size]())
	,m_size(size){
		for(int i = 0;i<size;++i){
			m_pdata[i] = p[i];
		}
	}
	void heapAdjust(int,int);
	void sort();
	void buildHeap();
	void print(){
		for(int i = 0;i<m_size;++i){
			cout << m_pdata[i] << " ";
		}
		cout << endl;
	}
private:
	T *m_pdata;
	int m_size;
};
template<class T,class Compare>
void HeapSort<T,Compare>::heapAdjust(int pos,int len){
	//head从0开始
	int dad = pos;
	int son = dad*2+1;
	while(son < len){
		if(son < len -1 && m_pdata[son] < m_pdata[son+1]){
			son++;
		}
		if(m_pdata[dad]>m_pdata[son]){
			break;
		}else{
			SWAP(m_pdata[son],m_pdata[dad]);
			dad = son;
			son = dad*2+1;
		}
	}
}

template<class T,class Compare>
void HeapSort<T,Compare>::buildHeap(){
	for(int i = m_size/2-1;i>=0;--i){
		heapAdjust(i,m_size);
	}
}
template<class T,class Compare>
void HeapSort<T,Compare>::sort(){
	buildHeap();
	for(int i = m_size-1;i>0;--i){
		SWAP(m_pdata[0],m_pdata[i]);
		heapAdjust(0,i);
	}
}
int main(int argc,char* argv[]){
	int a[5] = {2,4,1,5,3};
	HeapSort<int> hs(a,5);
	hs.buildHeap();
	hs.print();
	hs.sort();
	hs.print();
}


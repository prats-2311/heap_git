#include<iostream>
#include<vector>
//#include<array>

void insertMaxHeap(std::vector<int>&,int,int);
int delMaxHeap(std::vector<int>&,int);
void adjust(std::vector<int>&,int,int);

void adjust(std::vector<int>& a,int i,int n)
{
  int j=2*i;
  int item=a[i];
  while(j<=n)
  {
    if(j<n && a[j]<a[j+1])
    j=j+1;
    if(a[j]<=item)
    break;
    a[j/2]=a[j];
    j=2*j;
  }
  a[j/2]=item;

}

void insertMaxHeap(std::vector<int>& a,int n,int x)
{
  int i=n;
  int item=x;
  int value;
  a.resize(a.size()+1);

  while(i>1 && a[i/2] <item)
  {
    a[i]=a[i/2];
    i/=2;
  }
  a[i]=item;
}
int delMaxHeap(std::vector<int>& a,int n )
{
  int maxElem=a[1];
  a[1]=a[n];
  adjust(a,1,n-1);
  return maxElem;
}
int main()
{
  std::vector<int> max_heap={-1,35, 33, 42, 10, 14, 19, 27, 44, 26, 31};

  int size=max_heap.size();
  std::cout<<"Size of internal nodes: "<<(size-1)/2<<std::endl;
  for(int i=(size-1)/2;i>=1;i--)
  {
    adjust(max_heap,i,max_heap.size());
  }
  insertMaxHeap(max_heap,max_heap.size(),99);
  for(int i=1;i<max_heap.size();i++)
  std::cout<<max_heap[i]<<" ";

 return 0;
}
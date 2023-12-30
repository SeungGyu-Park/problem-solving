#include <iostream>
using namespace std;
int main(void) {
int x,a=0,i=0;cin>>x;for(;i<7;++i)a+=(x&(1L<<i))!=0;cout<<a;return 0;}
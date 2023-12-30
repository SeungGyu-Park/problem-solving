#include<iostream>
int main(){int x,a=0,i=0;std::cin>>x;for(;i<7;++i)a+=(x&(1<<i))!=0;std::cout<<a;}
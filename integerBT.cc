#include<stdio.h>
#include<conio.h>

using namespace std;
struct node
 {
  int data;
  struct node *left, *right;
 };

 void func(struct node *p2)
 {
  int i1,i;
  node *p1[10];
  p1[0]=p2;
  i1=i=0;
  int even=p1[0]->data, odd = 0;
  while(i1<5)

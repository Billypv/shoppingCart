#include<iostream>
#include "Product.h"

using namespace std;
Product::Product(double price, int catId,string pname):price(price),catId(catId),pname(pname){
	static int nextNo = 0;
	pid = nextNo;
	nextNo++;
};
int Product::getPid() const{
	return pid;
}
double Product::getPrice(){
	return price;
}

int Product::getCatId(){
	return catId;
}
string Product::getPname(){
	return pname;
}
void Product::display(){
    cout<<"Name: "<<pname<<endl;
    cout<<"ID: "<< pid<<endl;
    cout<<"Price: £ "<<price<<endl;
}
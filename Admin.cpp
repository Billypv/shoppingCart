#include<iostream>
#include<vector>
#include "Admin.h"
using namespace std;

vector<Category*> Admin::getCatagories(){
	return categories;
};
void Admin::addCategory(int catId, string catName, string description){
	for(auto &c:categories){
		if(c->getCatName() == catName){
			cout<<"there is already a category with the name: "<< catName<<endl;
			return;
		}
		if(c->getCatId() == catId){
			cout<<"there is already a category with the ID: "<< catId<<endl;
			return;
		}		
	}
	categories.push_back(new Category(catId, catName, description));
};

 
void Admin::addProduct(double price,string pname,  int catId){
	for(auto &c:categories){
		if(c->getCatId() == catId){
			for(auto &p:c->getProducts()){
				if(pname == p->getPname()){
					cout<<"This product already exists";
					return;
				}
			}
			c->addProduct(new Product(price,catId,pname));
			return;
		}
	}	
};

void Admin::getRecord(string catName){
	for(auto &c:categories){
		if(c->getCatName() == catName){
			cout<<"Category ID: "<<c->getCatId()<<"\t Category Name: "<< c->getCatName()<<"\t Category Description: "<<c->getCatDescription()<<endl;
			cout<<"Products in the category:\n";
			for(auto &p:c->getProducts()){
            	cout << "Product ID: "<<p->getPid()<<"\tProduct Name: "<< p->getPname()<<"\tPrice: "<<p->getPrice() << endl;
        	}
		}
	}
};
void Admin::getRecord(double lowerBound, double upperBound){
	for(auto &c:categories){
		for(auto &p:c->getProducts()){
			if(p->getPrice()>=lowerBound && p->getPrice()<=upperBound){
            cout << "Product ID: "<<p->getPid()<<"\tProduct Name: "<< p->getPname()<<"\tPrice: "<<p->getPrice() << endl;
        	}
		}
	}	
};

void Admin::getAllRecords(){
	for(auto &c:categories){
		for(auto &p:c->getProducts()){
			cout<< "Product ID: "<<p->getPid()<<"\tProduct Name: "<< p->getPname()<<"\tPrice: "<<p->getPrice() <<
				"\tCategory Id: "<< c->getCatId()<<"\tCategory Name: "<< c->getCatName()<<"\tCategory Description: "<< c->getCatDescription()<<endl;
		}
	}
}
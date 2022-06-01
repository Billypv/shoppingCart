#include<iostream>
#include "BasketProduct.h"


BasketProduct::BasketProduct(Product *p): Product(p->getPrice(), p->getCatId(),  p->getPname()){};

void BasketProduct::changeQuantity(int amount){
	quantity += amount;
};
double BasketProduct::calculatePrice(){
	price = static_cast<double>(getQuantity()) * Product::getPrice() ;
	return price;
};

int BasketProduct::getQuantity(){
	return quantity;
};

double BasketProduct::getPrice(){
	return price;
}
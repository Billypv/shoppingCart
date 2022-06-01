#include<iostream>
using namespace std;

class Product{
    private:
        int catId, pid;
        double price;
        string pname;
    public:
        Product(double price, int catId,string pname);
        void display();
		int getPid() const;
		double getPrice();
		string getPname();
		int getCatId();
	};

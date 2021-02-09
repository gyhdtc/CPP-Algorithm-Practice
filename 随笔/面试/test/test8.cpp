#include <string>
#include <iostream>
using namespace std;

class Person {
    public:
    Person() = default;
    Person(const std::string &name, const std::string &add) : name(name), address(add) {}
    Person(std::istream &is) { read(is, *this); }
    std::string const& getname() const { return name; }
    std::string const& getaddress() const { return address; }
    
    std::string name;
    std::string address;
};
std::istream &read(std::istream &is, Person &person)
{
	return is >> person.name >> person.address;
}
std::ostream &print(std::ostream &os, const Person &person)
{
	return os << person.name << " " << person.address;
}

class Sales_data {
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
    public:
    // 构造函数
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) :
                bookNo(s), units_sold(n), revenue(p) {}
    //
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}
std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

int main() {

    return 0;
}
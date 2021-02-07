#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <initializer_list>
#include <exception>
using std::vector; using std::string;

class strBlob
{
public:
    using size_type = vector<string>::size_type;
    
    strBlob() : data(std::make_shared<vector<string>>()) {}
    strBlob(std::initializer_list<string> il) : data(std::make_shared<vector<string>>(il)) {}
    
    size_type size() { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string &t) { data->push_back(t); }
    void pop_back() {
        check(0, "front on empty strBlob");
        return data->pop_back();
    }

    string& front() {
        check(0, "front on empty strBlob");
        return data->front();
    }
    string& back() {
        check(0, "front on empty strBlob");
        return data->back();
    }
	const string& front() const
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}
	const string& back() const
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}
    strBlob* fun() { return this; }
private:
    std::shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const {
        if (i >= data->size())
            throw std::out_of_range(msg);
    }
};
int main() {
    strBlob a;
    return 0;
}
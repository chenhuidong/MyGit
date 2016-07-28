#include <boost/lexical_cast.hpp>
#include <boost/fusion/include/for_each.hpp>
#include <cassert>
#include <boost/fusion/adapted/boost_tuple.hpp>
#include <boost/fusion/adapted/std_pair.hpp>

struct stringize_functor {
private:
	std::string& result;
public:
	explicit stringize_functor(std::string& res)
	: result(res)
	{}
template <class T>
	void operator()(const T& v) const {
		result += boost::lexical_cast<std::string>(v);
	}
};

template <class Sequence>
std::string stringize(const Sequence& seq) {
	std::string result;
	boost::fusion::for_each(seq, stringize_functor(result));
	return result;
}


int main() {
	boost::tuple<char, int, char, int> decim('-', 10, 'e', 5);
	assert(stringize(decim) == "-10e5");
	std::pair<short, std::string> value_and_type(270, "Kelvin");
	assert(stringize(value_and_type) == "270Kelvin");
}

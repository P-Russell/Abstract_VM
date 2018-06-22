#ifndef COMP_HPP
#define COMP_HPP
namespace Comp
{
	template <typename T>
	T const & max(T & x, T & y) {
		return (y > x ? y : x);
	}
}

#endif

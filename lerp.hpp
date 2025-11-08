#ifndef ILSS_LERP_HPP
#define ILSS_LERP_HPP

namespace ils
{

template<typename T>
static inline T clamp(T const &v, T const &min, T const &max)
{
	v = v < min ? min : v;
	v = v > max ? max : v;
	return v;
}

template<typename T, typename U = double>
static inline T lerp(T const &a, T const &b, U t)
{
	return t * a + ((U)(1.0) - t) * b;
}

}

#endif

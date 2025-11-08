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
	return ((U)(1.0) - t) * a + b * t;
}

template<typename T, typename U = double>
static inline T bilinear_interpolation(T const &a1, T const &a2, T const &a3, T const &a4, U t1, U t2)
{
	return lerp(lerp(a2, a1, t2), lerp(a4, a3, t2), t1);
}

}

#endif

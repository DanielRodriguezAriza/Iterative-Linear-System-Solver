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


}

#endif

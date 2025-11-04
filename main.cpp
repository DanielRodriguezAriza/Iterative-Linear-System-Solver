#include <cstddef>
#include <ostream>
#include <iostream>

// TODO : Implement checks to see if the system can be solved or not before attempting to solve it
// Maybe also wrap it all up within a namespace like ILS (iterative linear solver) or whatever, and
// a struct with static methods or a subnamespace for separation between methods. For now tho, this is ok.

template<typename T, std::size_t M, std::size_t N>
struct Mat
{
    T c[M * N];

    inline T const &operator()(std::size_t i, std::size_t j) const { return c[_index(i, j)]; }
    inline T const &operator()(std::size_t i) const { return c[_index(i, 0)]; }
    inline T &operator()(std::size_t i, std::size_t j) { return c[_index(i, j)]; }
    inline T &operator()(std::size_t i) { return c[_index(i, 0)]; }

    inline std::size_t _index(std::size_t i, std::size_t j) const { return i * N + j; }
	
	inline void zero()
	{
		for(std::size_t i = 0; i < M * N; ++i)
		{
			c[i] = 0;
		}
	}
};

template<typename T, std::size_t M, std::size_t N>
std::ostream &operator<<(std::ostream &os, Mat<T, M, N> const &m)
{
    os << "[\n";
    for(std::size_t i = 0; i < M; ++i)
    {
        os << "  ";
        for(std::size_t j = 0; j < N; ++j)
        {
            os << /*"a[" << i << ", " << j << "](" << m._index(i, j) << ")" <<*/ m(i, j) << " ";
        }
        os << "\n";
    }
    os << "]";
    return os;
}

template<typename T, size_t M>
bool exit_condition(Mat<T, M, 1> const &x_curr, Mat<T, M, 1> const &x_prev, T const &t)
{
    for(std::size_t i = 0; i < M; ++i)
    {
        T ei = std::abs(x_curr(i) - x_prev(i));
        if(ei > t)
        {
            return false;
        }
    }
    return true;
}

template<typename T, size_t M, size_t N>
Mat<T, M, 1> jacobi(Mat<T, M, N> const &A, Mat<T, M, 1> const &b, T const &t)
{
    Mat<T, M, 1> x_curr, x_prev;
	x_curr.zero();
	x_prev.zero();

	int numitrs = 0;
    do
    {
        x_prev = x_curr;
        for(std::size_t i = 0; i < N; ++i)
        {
            T temp = 0;
            for(std::size_t j = 0; j < M; ++j)
            {
                if(i == j) continue;
                temp += A(i, j) * x_prev(j);
            }
            x_curr(i) = (b(i) - temp) / A(i, i);
        }
		++numitrs;
    }
    while(!exit_condition(x_curr, x_prev, t));
	std::cout << "NUM ITRS REQUIRED : " << numitrs << "\n";
    return x_curr;
}

int main()
{
    Mat<double, 4, 4> A = {
        5,2,-1,1,
        1,7,3,-1,
        -1,4,9,2,
        1,-1,1,4
    };
    
    Mat<double, 4, 1> b = { 12, 2, 1, 3 };
    
    double t = 0.01;

    auto x = jacobi(A, b, t);
    
    std::cout << x << "\n";

    return 0;
}

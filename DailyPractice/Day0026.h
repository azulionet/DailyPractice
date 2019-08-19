#pragma once


#include <boost/array.hpp>

template<typename T, size_t X, size_t Y>
class Matrix
{
public:
	Matrix() = default;
	Matrix(Matrix&& val) : Arr(std::move(val.Arr)) { }

	Matrix<T, Y, X> Rotate()
	{
		Matrix<T, Y, X> val;

		for (int y = 0; y < Y; ++y)
		{
			for (int x = 0; x < X; ++x)
			{
				val[x][y] = Arr[y][x];
			}
		}

		return val;
	}

	void Print()
	{
		for (int i = 0; i < Y; ++i)
		{
			cout << "I Line : " + i;

			for (int j = 0; j < X; ++j)
			{
				cout << Arr[i][j] << " ";
			}

			cout << endl;
		}
	}

	boost::array<T, X>& operator[](size_t index)
	{
		return Arr[index];
	}

	boost::array<boost::array<T, X>, Y> Arr;
};
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CS_DailyPractice.Practice
{
	class Day5
	{
		
		static int differentValues(int[] a, int d)
		{
			int r = -1, z = a.Length, i=0, j=0;

			for (; i <z-1; ++i)
			{
				for (j = i + 1; j < z; ++j)
				{
					int c = System.Math.Abs(a[i] - a[j]);

					if( c == d ) { return c; }

					r = (c<=d && c>r ? c: r);					
				}
			}

			return r;
		}

	}
}

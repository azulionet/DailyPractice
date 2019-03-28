using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using CS_DailyPractice.Day4;

namespace CS_DailyPractice
{
	class Program
	{
		static void Main(string[] args)
		{
			Maze.Update();

			Maze.FindRoute();

			int a = 10;

			// a>10 ?: Console.Write("a");



			Console.WriteLine();

			Console.Read();

		}
	}
}

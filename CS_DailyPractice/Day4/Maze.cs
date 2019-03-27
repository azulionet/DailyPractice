using System.Collections.Generic;
using System.Windows;
using System;
using System.Threading;

namespace CS_DailyPractice.Day4
{
	[System.Flags]
	public enum eDir
	{
		None	= 0,
		Left	= 1 << 0, // 1
		Top		= 1 << 1, // 2
		Right	= 1 << 2, // 4
		Bottom	= 1 << 3, // 8
	}

	enum eMap
	{
		Empty	= 0,
		Wall	= 1,
		Start	= 2,
		End		= 3,
	}

	// 맵에서 사용하는 데이터 세팅 ( static 생성자에서 모두 생성 )
	static partial class Maze
	{
		// 딕셔너리가 아니라 배열을 쓰면 되지만 보기 좋으라고 딕셔너리 사용	
		private static Dictionary<eDir, char> mapCharacter = null;
		private static Dictionary<eDir, char> mapCharacter2 = null;
		
		
		static Maze()
		{
			_InitTextData();
			_TestMapSetting();
			_MapSetting();

			return;

			void _InitTextData()
			{
				if (mapCharacter == null)
				{
					mapCharacter = new Dictionary<eDir, char>()
					{
						[eDir.None]											= ' ',

						// 1~5
						[eDir.Left]											= (char)9473, // ━ 9473
						[eDir.Top]											= (char)9475, // ┃ 9475
						[eDir.Left | eDir.Top]								= (char)9499, // ┛ 9499
						[eDir.Right]										= (char)9473, // ━ 9473
						[eDir.Left | eDir.Right]							= (char)9473, // ━ 9473

						// 6~10
						[eDir.Top | eDir.Right]								= (char)9495, // ┗ 9495
						[eDir.Left | eDir.Top | eDir.Right]					= (char)9531, // ┻ 9531
						[eDir.Bottom]										= (char)9475, // ┃ 9475
						[eDir.Left | eDir.Bottom]							= (char)9491, // ┓ 9491  
						[eDir.Top | eDir.Bottom]							= (char)9475, // ┃ 9475

						// 11~15
						[eDir.Left | eDir.Top | eDir.Bottom]				= (char)9515, // ┫ 9515
						[eDir.Right | eDir.Bottom]							= (char)9487, // ┏ 9487
						[eDir.Left | eDir.Right | eDir.Bottom]				= (char)9523, // ┳ 9523
						[eDir.Top | eDir.Right | eDir.Bottom]				= (char)9507, // ┣ 9507
						[eDir.Left | eDir.Top | eDir.Right | eDir.Bottom]	= (char)9547, // ╋ 9547
					};

					mapCharacter2 = new Dictionary<eDir, char>()
					{
						[(eDir)0]	= ' ',

						// 1~5
						[(eDir)1]	= (char)9473, // ━ 9473
						[(eDir)2]	= (char)9475, // ┃ 9475
						[(eDir)3]	= (char)9499, // ┛ 9499
						[(eDir)4]	= (char)9473, // ━ 9473
						[(eDir)5]	= (char)9473, // ━ 9473

						// 6~10
						[(eDir)6]	= (char)9495, // ┗ 9495
						[(eDir)7]	= (char)9531, // ┻ 9531
						[(eDir)8]	= (char)9475, // ┃ 9475
						[(eDir)9]	= (char)9491, // ┓ 9491  
						[(eDir)10]	= (char)9475, // ┃ 9475

						// 11~15
						[(eDir)11]	= (char)9515, // ┫ 9515
						[(eDir)12]	= (char)9487, // ┏ 9487
						[(eDir)13]	= (char)9523, // ┳ 9523
						[(eDir)14]	= (char)9507, // ┣ 9507
						[(eDir)15]	= (char)9547, // ╋ 9547
					};
				}
			}
			void _TestMapSetting()
			{
				m_MapOriginData = new int[nHeight, nWidth]
				{
					{1, 3, 1, 1, 1, 1, 1, 1, 1, 1},
					{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
					{1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
					{1, 0, 1, 0, 0, 0, 1, 1, 0, 1},
					{1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
					{1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
					{1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
					{1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
					{1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
					{1, 1, 1, 1, 1, 2, 1, 1, 1, 1},
				};
			}
			void _MapSetting()
			{
				m_Map = new char[nHeight, nWidth];

				for (int i = 0; i < nHeight; ++i)
				{
					for (int j = 0; j < nWidth; ++j)
					{
						m_Map[i, j] = __GetWallText(m_MapOriginData, i, j);
					}
				}

				return;

				char __GetWallText(int[,] map, int y, int x)
				{
					if (x < 0 || x >= nWidth ||
						y < 0 || y >= nHeight)
					{
						System.Diagnostics.Debug.Assert(false, "Arg error");
						return 'X';
					}

					int nData = map[y, x];
					char cReturn = ' ';

					switch ((eMap)nData)						
					{
						case eMap.Empty: { cReturn = ' '; } break;
						case eMap.Wall:
						{
							eDir eDir = eDir.None;

							try
							{
								if (x > 0 && map[y, x - 1] == (int)eMap.Wall)
								{
									eDir |= eDir.Left;
								}

								if (x < (nWidth-1) && map[y, x + 1] == (int)eMap.Wall)
								{
									eDir |= eDir.Right;
								}

								if (y > 0 && map[y - 1, x] == (int)eMap.Wall)
								{
									eDir |= eDir.Top;
								}

								if (y < (nHeight-1) && map[y + 1, x] == (int)eMap.Wall)
								{
									eDir |= eDir.Bottom;
								}
							}
							catch
							{
								Console.WriteLine("error {0}, {1}", x, y);
							}

							try
							{
								cReturn = mapCharacter[eDir];
							}
							catch
							{
								Console.WriteLine("error {0}", eDir);
							}

							if(cReturn == ' ')
							{
								Console.WriteLine("Error!!!!! {0}, {1}", x, y);
								// System.Diagnostics.Debug.Assert(false, "logic error  - 2개 이상의 스타트 포인트");
							}
						} break;
						case eMap.Start:
						{
							cReturn = ' ';

							if( StartPos != null )
							{
								System.Diagnostics.Debug.Assert(false, "logic error  - 2개 이상의 스타트 포인트");
							}

							StartPos = new Point(x, y);
						} break;
						case eMap.End:
						{
							cReturn = ' ';
							
							if (GoalPos != null)
							{
								System.Diagnostics.Debug.Assert(false, "logic error  - 2개 이상의 골 포인트");
							}

							GoalPos = new Point(x, y);
						} break;
						default:
							System.Diagnostics.Debug.Assert(false, "logic error");
							break;
					}

					return cReturn;
				}
			}
		}
	}

	// 실제 미로
	static partial class Maze
	{
		const int				nWidth = 10;
		const int				nHeight = 10;
		static char[,]			m_Map = null;
		static int[,]			m_MapOriginData = null;

		// 참조에 WindowBase DLL추가해야 struct Point 사용 가능
		static public Point?	StartPos = null;
		static public Point?	GoalPos = null;

		static public Point		MyPos;
		static public eDir		myDir = eDir.Left;

		public static List<Point> m_liRoute = new List<Point>();
		
		static public void FindRoute()
		{
			MyPos = StartPos.Value;

			m_liRoute.Add(MyPos);

			_PrintMyPosUI();

			// m_liRoute.FindIndex((a) => { return a.X == pt.X && a.Y == pt.Y; } );

			Console.ReadKey();

			while (_RoutePeek() != GoalPos.Value)
			{
				// Console.ReadKey();

				Thread.Sleep(100);

				_RenewRoute();
			}

			Thread.Sleep(100);
			_OptimizeRoute();

			Console.SetCursorPosition(0, 12);
			Console.WriteLine("도착! 최적화 ㄱㄱ");

			MyPos = StartPos.Value;
			int nIndex = 0;
			_PrintMyPosUI();

			while (MyPos != GoalPos.Value)
			{
				_ClearMyPosUI();
				MyPos = m_liRoute[++nIndex];
				_PrintMyPosUI();
				
				Thread.Sleep(100);
			}

			Console.SetCursorPosition(0, 13);
			Console.WriteLine("도착 루트 : " + m_liRoute.Count);

			return;			
		}

		static void _RenewRoute()
		{
			int nTurnCount = 0;

			Point? pt = null;

			while (nTurnCount < 4)
			{
				// 오른쪽에 길이 있지 않거나, 바로 이전칸에 움직인 곳이라면 null리턴
				pt = _CheckRight();

				if (pt == null)
				{
					_TurnLeft();
				}
				else
				{
					break;
				}

				++nTurnCount;
			}

			_ClearMyPosUI();

			if (pt == null)
			{
				// 이전에 왔었던 길로 이동 & 방향 세팅

				Point? before = _RouteBeforeEnd();

				if( before != null )
				{
					m_liRoute.Add(before.Value);

					// 2번 움직이면 돌아왔던 방향
					_TurnLeft();
					_TurnLeft();

					MyPos = _RoutePeek(); // 현재 위치를 이 위치로 갱신
				}				
			}
			else
			{
				m_liRoute.Add(pt.Value);
				MyPos = pt.Value;
			}

			_PrintMyPosUI();
		}

		static Point? _CheckRight()
		{
			int x = (int)MyPos.X;
			int y = (int)MyPos.Y;
			Point? pt = null;

			int n = ((int)myDir << 1);
			if( n >= 16 ) { n = 1; }

			eDir temp = (eDir)n;

			switch (temp)
			{
				case eDir.Left:
					if (x > 0 && _IsWalkable(m_MapOriginData[y, x - 1]) == true)
					{
						pt = new Point(x - 1, y);
					}
					break;
				case eDir.Top:
					if (y > 0 && _IsWalkable(m_MapOriginData[y - 1, x]) == true)
					{
						pt = new Point(x, y - 1);
					}
					break;
				case eDir.Right:
					if (x < (nWidth-1) && _IsWalkable(m_MapOriginData[y, x + 1]) == true)
					{
						pt = new Point(x + 1, y);
					}
					break;
				case eDir.Bottom:
					if (y < (nHeight-1) && _IsWalkable(m_MapOriginData[y + 1, x]) == true)
					{
						pt = new Point(x, y + 1);
					}
					break;
				default:
				{
					System.Diagnostics.Debug.Assert(false, "logic error");
				}
				break;
			}

			if (pt != null ) // 전전 위치랑 같다면 == 바로 이전에 갔던 길이라면
			{
				Point? before = _RouteBeforeEnd();

				if(before != null && pt.Value == before.Value )
				{
					pt = null;
				}				
			}

			if( pt != null )
			{
				myDir = temp; // 방향 변경
			}

			return pt;
		}

		static void _TurnLeft()
		{
			int n = (int)myDir;

			n >>= 1;

			// 방향 최종 합이 15까지라 넘어서지 않도록 자름
			if( n == 0 )
			{
				n = (int)(eDir.Bottom);
			}

			myDir = (eDir)n;
		}

		static bool _IsWalkable(int nData)
		{
			return (nData != (int)eMap.Wall);
		}

		static public void Update()
		{			
			_DrawMap();

			return;

			void _DrawMap()
			{
				for (int i = 0; i < nHeight; ++i)
				{
					for (int j = 0; j < nWidth; ++j)
					{
						Console.Write(m_Map[i, j]);
					}

					Console.WriteLine();
				}
			}
		}

		static void _ClearMyPosUI()
		{
			Console.SetCursorPosition((int)MyPos.X, (int)MyPos.Y);
			Console.Write(" ");
		}

		static void _PrintMyPosUI()
		{
			Console.SetCursorPosition((int)MyPos.X, (int)MyPos.Y);
			Console.Write("@");
		}


		static Point _RoutePeek()
		{
			return m_liRoute[m_liRoute.Count-1];
		}

		static Point? _RouteBeforeEnd()
		{
			if(m_liRoute.Count <= 2)
			{
				return null;
			}

			return m_liRoute[m_liRoute.Count - 2];
		}

		static void _OptimizeRoute()
		{
			int nCount = m_liRoute.Count;
			for ( int i=0; i< nCount; ++i )
			{
				var li = m_liRoute.FindAll((a) => { return m_liRoute[i] == a; });

				if( li.Count >= 2 )
				{
					nCount -= _RemoveRoute(m_liRoute[i]);
				}
			}
			
			return;

			int _RemoveRoute(Point pt)
			{
				Predicate<Point> fpFindPt = (a) => { return a == pt; };

				int nFirst = m_liRoute.FindIndex(fpFindPt);
				int nSecond = m_liRoute.FindIndex(nFirst+1, fpFindPt);

				m_liRoute.RemoveRange(nFirst + 1, nSecond - nFirst);
				return nSecond - nFirst;
			}

		}
	}
}

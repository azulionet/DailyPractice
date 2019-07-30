#pragma once

#define T(Num) void TEST##0019_## Num () {
#define Test(Num) TEST##0019_## Num()
#define END }


T(0)

	cout << "Hi" << endl;

END




T(1)

cout << "0019 2" << endl;

END
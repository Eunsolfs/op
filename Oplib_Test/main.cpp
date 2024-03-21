

#include <fstream>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
#include <time.h>
#include <chrono>
#include <filesystem>

#include "op_test.h"

#include <libop.h>

#pragma warning(disable : 4996)

using namespace std;


int main(int argc, char* argv[]) {
	locale loc("chs");
	wcout.imbue(loc);


	// test_shared();
	//test_unique();
	//test_invoke();
	//test_com();


	//test* ptest = new test;
	//ptest->do_test();
	//delete ptest;
	//ptest = nullptr;


	//test_paddle();


	auto op = libop();

	wcout << op.Ver() << endl;

	system("pause");
	return 0;
}

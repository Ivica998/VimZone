#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include "utils.cpp"
#include "task.cpp"

int main(int argc, char *argv[]) {
	cout << "argc:" << argc << endl;
	
	if (argc < 2) { cout << "need input file\n"; return -1; }
	std::ifstream file(argv[1]); string lines[4]; int cnt = 1;
	Solution s; 
	string res;
	while (std::getline(file, lines[0])
	 && std::getline(file, lines[1])
/* 	 && std::getline(file, lines[1])
	 && std::getline(file, lines[3]) */
/* 	) { */
	 ) {
		cout << "pass - " << cnt++ << endl;
		cout << "input:" << lines[0] << endl;
		vector<int> in = cin_vec_int(lines[0]);
		vector<int> in2 = cin_vec_int(lines[1]);
/* 		string in2 = cin_str(lines[1]); */
		res = s.findMedianSortedArrays(in, in2);
		cout << "res: "<< res << endl;
/* 		cout << "res: "; print_list(res); cout << endl; */
		cout << "--------------------------" << endl;
	}
	return 0;
}

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <unordered_set>
#include <unordered_map>
using namespace std;

template <typename T>
T lexical_cast(const std::string& s) {
    std::stringstream ss(s);
    T result;
    if ((ss >> result).fail() || !(ss >> std::ws).eof()) {
        throw std::bad_cast();
    }
    return result;
}

template <typename T>
bool lexical_cast(const std::string& s, T& t) {
    try {
        t = lexical_cast<T>(s);
        return true;
    }
    catch (const std::bad_cast& e) {
        return false;
    }
}

template <class T>
std::ostream &operator<<(std::ostream &os, vector<T> &v) {
	if(v.size() == 0) {
		os << "[]";
		return os;
	}
	os << "[";
	auto iter = v.begin();
	auto end = --v.end();
	while (iter != end){
		os << *iter++ << ",";
	}
	os << *iter << "]";
	return os;
}

int getDigs(int x) { int cnt = 0; while (x > 0) { x = x / 10; cnt++; } return cnt; }

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print_list(ListNode* head){
	 while(head) {
		std::cout << head->val << ' ';
		head = head->next;
	 }
}

void print_vec(std::vector<int>& vec){
	for(int c : vec)
		std::cout << c << ' ';
}

int cin_int(std::string in){
	int ret;
	stringstream ss(in);
	ss >> ret;
	return ret;
}

class st_branch {
	public:
	string name;
	unordered_set<char> skipmap;
	unordered_map<char,int> cmap;
};

vector<st_branch> state {
		{ "begin", {' '}, {{'[', 1}}},
		{ "arrin", {' '}, {{'"', 3}}},
		{ "arrnx", {' '}, {{',', 1}}},
		{ "valin", {}, {{'"', 2}}},
	};

string cin_str(std::string in) {
	string ret = "";
	return in.substr(1,in.size()-2);	
}
std::vector<string> cin_vec_str(std::string in){
	std::vector<string> ret;
	string tmp; char c;
	bool isval = false , done = false;
	for(int i = 0; i < in.length(); ++i){
		c = in[i];
		if(isval){
			if(c == '"') {
					isval = false;
					ret.push_back(tmp);
					tmp = "";
				}
			else tmp += c;
			continue;
		}
		else { 
			switch (c) {
			case '"': isval = true; break;
			case ' ': continue;	
			case ']': done = true; break;	
			case '[': done = false; break;	// +
			default: break;
			}
		}
		if(done) break;	
	}	
	return ret;
}

class tree_data : public std::vector<std::shared_ptr<int>> {
	public:
	~tree_data(){
		for(auto iter = begin(); iter != end(); ++iter) {
			//delete *iter;
		}
	}
};

tree_data cin_vec_intptr(std::string in){
	tree_data ret; string tmp; char c;
	bool isval = false , done = true;
	for(int i = 0; i < in.length(); ++i){
		c = in[i];
		if(isval){
			if (c == ',' || c == ']') {
				std::shared_ptr<int> tmp3 = nullptr;
				try {
					int tmp2 = stoi(tmp);
					tmp3 = std::make_shared<int>(tmp2);
				}
				catch (const std::exception &e) {
					if (tmp == "null") tmp3 = nullptr;
				}
				ret.push_back(tmp3);
				tmp = "";
			}
			else tmp += c; 
			continue;
		}
		else { 
			switch (c) {
			case ',': isval = true; break;
			case ' ': continue;	
			case ']': done = true; break;	
			case '[': done = false; isval = true; break;
			default: break; } }
		if(done) break;	}	
	return ret;
}


std::vector<int> cin_vec_int(std::string in){
	std::vector<int> ret;
	int tmp;
	stringstream ss(in);
	ss.get();
	while(ss.peek() != ']' && !ss.eof()){
		ss >> tmp;
		ret.push_back(tmp);
		if(ss.peek() == ',') ss.get();
	}
	return ret;
}

ListNode* cin_list_int(string in) {
	ListNode* head = nullptr;
	auto vec = cin_vec_int(in);
	for(int i = vec.size() - 1; i >= 0; i--){
		ListNode* node = new ListNode(vec[i], head);
		head = node;
	}
	return head;
} 

TreeNode* cin_tree_int_step(tree_data& data) {
	if(data.size() == 0) return nullptr; 
	auto obj = data[0];
	data.erase(data.begin());
	if(obj == nullptr) return nullptr;
	int val = obj.get()[0]; 
	TreeNode* node = new TreeNode(val);
	node->left = cin_tree_int_step(data);
	node->right = cin_tree_int_step(data);
	return node;
}

TreeNode* cin_tree_int(string in) {
	TreeNode* root = nullptr;
	auto data = cin_vec_intptr(in);
	root = cin_tree_int_step(data);
	return root;
}

void foo(std::istream& stream) {
	std::string line, line2;
	while (std::getline(stream, line) && std::getline(stream, line2)) {
		vector<int> nums;
		size_t target = 0;
		stringstream l1(line);
		stringstream l2(line2);
		l1.get();
		while (l1.peek() != ']') {
			int tmp;
			l1 >> tmp;
			nums.push_back(tmp);
			if(l1.peek() == ',')
				l1.get();
		}
		l1.get();
		l2 >> target;
		print_vec(nums);
		cout << endl;
		cout << target << endl;
	}
}

template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) { 
    os << "[";
    for (int i = 0; i < v.size(); ++i) { 
        os << v[i]; if (i != v.size() - 1) os << ", "; }
    os << "]\n"; return os; }

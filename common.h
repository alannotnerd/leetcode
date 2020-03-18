#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct Put{
  template<typename T>
  void operator() (const T& t){};

  template<typename T>
  void operator() (const vector<T, allocator<T>>& vec){
    for(auto i: vec){
      cout << i << " ";
    }
    cout << endl;
  }
};

Put put;
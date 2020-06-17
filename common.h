#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <climits>
#include <string>
using namespace std;

struct Put{
  template<typename T>
  void operator() (const T& t){
    cout << t << endl;
  };

  template<typename T>
  void operator() (const vector<T, allocator<T>>& vec){
    for(auto i: vec){
      cout << i << " ";
    }
    cout << endl;
  }
};

Put put;
#define TEST
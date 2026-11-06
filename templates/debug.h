#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V> void __print(const pair<T, V> &x);
template <typename T> void __print(const stack<T> &x);
template <typename T> void __print(const queue<T> &x);
template <typename T> void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x)
    cerr << (f++ ? ", " : ""), __print(i);
  cerr << "}";
}
template <typename T, typename V> void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T> void __print(const stack<T> &x) {
  vector<T> v;
  for (auto s = x; !s.empty(); s.pop())
    v.push_back(s.top());
  __print(v);
} // top first
template <typename T> void __print(const queue<T> &x) {
  vector<T> v;
  for (auto q = x; !q.empty(); q.pop())
    v.push_back(q.front());
  __print(v);
} // front first
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}

void __print_sdtin(int x, ostream &in) { in << x; }
void __print_sdtin(long x, ostream &in) { in << x; }
void __print_sdtin(long long x, ostream &in) { in << x; }
void __print_sdtin(unsigned x, ostream &in) { in << x; }
void __print_sdtin(unsigned long x, ostream &in) { in << x; }
void __print_sdtin(unsigned long long x, ostream &in) { in << x; }
void __print_sdtin(float x, ostream &in) { in << x; }
void __print_sdtin(double x, ostream &in) { in << x; }
void __print_sdtin(long double x, ostream &in) { in << x; }
void __print_sdtin(char x, ostream &in) { in << '\'' << x << '\''; }
void __print_sdtin(const char *x, ostream &in) { in << '\"' << x << '\"'; }
void __print_sdtin(const string &x, ostream &in) { in << '\"' << x << '\"'; }
void __print_sdtin(bool x, ostream &in) { in << (x ? "true" : "false"); }
template <typename T, typename V> void __print_sdtin(const pair<T, V> &x);
template <typename T> void __print_sdtin(const stack<T> &x, ostream &in);
template <typename T> void __print_sdtin(const queue<T> &x, ostream &in);
template <typename T> void __print_sdtin(const T &x, ostream &in) {
  int f = 0;
  in << '{';
  for (auto &i : x)
    in << (f++ ? ", " : ""), __print_sdtin(i, in);
  in << "}";
}
template <typename T, typename V>
void __print_sdtin(const pair<T, V> &x, ostream &in) {
  in << '{';
  __print_sdtin(x.first, in);
  in << ", ";
  __print_sdtin(x.second, in);
  in << '}';
}
template <typename T> void __print_sdtin(const stack<T> &x, ostream &in) {
  vector<T> v;
  for (auto s = x; !s.empty(); s.pop())
    v.push_back(s.top());
  __print_sdtin(v, in);
} // top first
template <typename T> void __print_sdtin(const queue<T> &x, ostream &in) {
  vector<T> v;
  for (auto q = x; !q.empty(); q.pop())
    v.push_back(q.front());
  __print_sdtin(v, in);
} // front first
void _print_stdin(ostream &in) { in << "]\n"; }
template <typename T, typename... V>
void _print_stdin(T t, V... v, ostream &in) {
  __print_sdtin(t, in);
  if (sizeof...(v))
    in << ", ";
  _print_stdin(v..., in);
}

#define dbg(x...)                                                              \
  cerr << __func__ << ":" << __LINE__ << " [" << #x << "] = [";                \
  _print(x);

// port of paruma/atcoder_rust lg::table! — gray band header, per-column widths,
// centered row labels
template <typename T, typename = void> struct __is_range : false_type {};
template <typename T>
struct __is_range<T, void_t<decltype(begin(declval<const T &>()))>>
    : true_type {};
template <typename T> void __table(const char *name, int line, const T &x) {
  if (x.empty()) {
    cerr << "(empty)\n";
    return;
  }
  vector<vector<string>> cells;
  size_t W = 0;
  if constexpr (__is_range<decay_t<decltype(*x.begin())>>::value) {
    for (auto &r : x) {
      vector<string> rc;
      for (auto &c : r) {
        ostringstream ss;
        _print_stdin(c, ss);
        string c_ = ss.str();
        c_.pop_back(); // _print_stdin closes with ']'; that bracket is the
                       // table
        rc.push_back(c_);
      }
      W = max(W, rc.size());
      cells.push_back(std::move(rc));
    }
  } else { // 1D range: single horizontal row
    vector<string> rc;
    for (auto &c : x) {
      ostringstream ss;
      _print_stdin(c, ss);
      string c_ = ss.str();
      c_.pop_back();
      rc.push_back(c_);
    }
    W = rc.size();
    cells.push_back(std::move(rc));
  }
  vector<size_t> vw(W);
  for (size_t j = 0; j < W; j++)
    vw[j] = to_string(j).size();
  for (auto &rc : cells)
    for (size_t j = 0; j < rc.size(); j++)
      vw[j] = max(vw[j], rc[j].size());
  string label = to_string(line) + "> " + name;
  size_t lw = label.size();
  for (size_t i = 0; i < cells.size(); i++)
    lw = max(lw, to_string(i).size());
  cerr << "\x1b[30;48;2;127;127;127m" << left << setw((int)lw) << label << right
       << " |";
  for (size_t j = 0; j < W; j++) {
    if (j && vw[j] <= 1)
      cerr << ' ';
    cerr << ' ' << setw((int)vw[j]) << j;
  }
  cerr << ' ' << "\x1b[0m\n";
  for (size_t i = 0; i < cells.size(); i++) {
    string s = to_string(i), pad(lw - s.size(), ' ');
    cerr << string(pad.size() / 2, ' ') << s
         << string(pad.size() - pad.size() / 2, ' ') << " |";
    for (size_t j = 0; j < W; j++) {
      if (j && vw[j] <= 1)
        cerr << ' ';
      if (j < cells[i].size())
        cerr << ' ' << setw((int)vw[j]) << cells[i][j];
      else
        cerr << string(vw[j] + 1, ' ');
    }
    cerr << '\n';
  }
}
void _tables(const char *, int) {}
template <typename T, typename... V>
void _tables(const char *name, int line, const T &t, V... v) {
  __table(name, line, t);
  if (sizeof...(v))
    cerr << '\n';
  _tables(name, line, v...);
}
#define table(...)                                                             \
  do {                                                                         \
    _tables(#__VA_ARGS__, __LINE__, __VA_ARGS__);                              \
  } while (0);

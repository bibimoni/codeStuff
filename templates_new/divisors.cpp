const int N = int(1e6 + 5);
vector<vector<int>> divs(N);
for (int i = 1; i <= N; i++) {
  for (int mul = 1; mul * i < N; mul++) {
    divs[mul * i].push_back(i);
  }
}

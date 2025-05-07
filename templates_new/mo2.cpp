vector<Query> Q(m);
for (int i = 0; i < m; i++) {
  int l, r;
  cin >> l >> r;
  l--;
  r--;
  Q[i] = Query(l, r, i);
}
sort(all(Q));
vector<int> res(m);
int l = 0, r = -1;
for (Query q : Q) {
  while (r < q.r) {
    r++;
    add(r);
  }
  while (l > q.l) {
    l--;
    add(l);
  }
  while (r > q.r) {
    remove(r);
    r--;
  }
  while (l < q.l) {
    remove(l);
    l++;
  }
  res[q.idx] = ans;
}
for (int i = 0; i < m; i++) {
  cout << res[i] << "\n";
}

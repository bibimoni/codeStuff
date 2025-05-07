struct Query {
  int l, r, idx;

  Query() {}
  Query(int l_, int r_, int idx_) {
    l = l_;
    r = r_;
    idx = idx_;
  }
  pi toPair() const { return make_pair(l / S, ((l / S) & 1) ? -r : r); }
};

bool operator<(const Query &L, const Query &R) {
  return L.toPair() < R.toPair();
}

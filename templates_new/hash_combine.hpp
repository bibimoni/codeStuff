/*
  Hash node for hashing modification in segment tree
*/
struct Hash {
  int fwd, bwd, pwr, base, mod;
  bool is_trash;

  Hash() { is_trash = true; }
  Hash(int _base, int _mod) : base(_base), mod(_mod) {
    fwd = 0, bwd = 0, pwr = base;
    is_trash = false;
  }
  int convert(char c) {
    if ('0' <= c && c <= '9') {
      return c - '0';
    } else if ('a' <= c && c <= 'z') {
      return c - 'a';
    } else {
      return c - 'A';
    }
  }
  /*
    update a character for this Hash node
    **warning: must be the leaf node**
  */
  void update(char c) {
    fwd = convert(c);
    bwd = convert(c);
    is_trash = false;
  }

  /*
    This hashing function works like this
      fwd(S) = sum(S[i] * base^(|S| - i)) % mod p (1 <= i <= |S|, base < p)
      bwd(S) = sum(S[i] * base^(i - 1)) % mod p (1 <= i <= |S|, base < p)
    Combine 2 hash
      fwd(S + T) = fwd(S) * T.base + fwd(T)
      bwd(S + T) = bwd(S) + bwd(T) * S.base
    Query a hash
      fwd(S[a..b]) = fwd(S[1..b]) - fwd(S[1..a-1]) * base^(b - a + 1)
  */
  Hash operator+(Hash const &o) {
    if (is_trash) {
      return o;
    } else if (o.is_trash) {
      return *this;
    }
    Hash ret = Hash(base, mod);
    ret.fwd = (o.pwr * fwd + o.fwd) % mod;
    ret.bwd = (bwd + pwr * o.bwd) % mod;
    ret.pwr = (pwr * o.pwr) % mod;
    return ret;
  }

  friend ostream &operator<<(ostream &out, const Hash &o) {
    return out << "[fwd: " << o.fwd << ", bwd: " << o.bwd << ", pwr: " << o.pwr
               << "]\n";
  }
};

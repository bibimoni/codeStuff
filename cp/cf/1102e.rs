use std::collections::BTreeSet;
use std::collections::HashMap;
#[allow(unused_imports)]
use std::cmp::{min,max};
use std::io::{BufWriter, stdin, stdout, Write};
const BITS: usize = 19;
 
#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn main() {
  // let tests = read_i32();
  let mut scan = Scanner::default();
  let out = &mut BufWriter::new(stdout());
  let tests = 1;
  for _test in 0..tests {
    let n = scan.next::<usize>();
    let a : Vec<i64> = (0..n).map(|_| scan.next()).collect();
    let MOD = 998244353;
    let mut f : HashMap<i64, i32> = HashMap::new();
    for x in &a {
      *f.entry(*x).or_insert(0) += 1;
    }
    let mut s = BTreeSet::new();
    let (mut cnt, mut ans) : (i64, i64) = (0 as i64, 1 as i64);
    for x in &a {
      *f.get_mut(x).unwrap() -= 1;
      s.insert(x);
      if f[x] == 0 {
        s.remove(x);
      }
      if(s.is_empty()) {
        cnt += 1;
      }
      if cnt >= 2 && s.is_empty() {
        ans *= 2;
        ans %= MOD;
      } 
    }
    println!("{ans}");
  }
}
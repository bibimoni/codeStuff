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
  let mut scan = Scanner::default();
  let out = &mut BufWriter::new(stdout());
  
  // let tests = read_i32();
  let tests = 1;
  for _test in 0..tests {
    let n = scan.next::<usize>();
    let a : Vec<f64> = (0..n).map(|_| scan.next::<f64>()).collect();
    let p : Vec<f64> = (0..n).map(|_| 0.0).collect();
    let p1 : Vec<f64> = (0..n).map(|_| 1.0).collect();
    a.sort_by(|c d| )
  }
}
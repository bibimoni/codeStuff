#[allow(unused_imports)]
use std::collections::BTreeSet;
use std::collections::HashMap;
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
    let r = scan.next::<i32>();
    let mut coords : Vec<f64> = Vec::with_capacity(n);
    let a : Vec<i32> = (0..n).map(|_| scan.next::<i32>()).collect();
    let mut ans : Vec<f64> = Vec::with_capacity(n);
    for i in 0..n {
      // println!("START");
      coords.push(bs(&coords, &a, a[i], r));
      print!("{:.11} ", coords[i]);
    }
    println!("");
  }
}

fn bs (coords : &Vec<f64>, a : &Vec<i32>, x : i32, radius : i32) -> f64 {
  let mut ans = radius as f64;
  for i in 0..coords.len() {
    if (a[i] - x).abs() <= radius * 2 {
      let dx : f64 = (a[i] - x).abs().into();
      if ans < ((4 * radius * radius) as f64 - dx * dx).sqrt() + coords[i] {
        ans = ((4 * radius * radius) as f64 - dx * dx).sqrt() + coords[i];
      }
    }
  }
  ans
}
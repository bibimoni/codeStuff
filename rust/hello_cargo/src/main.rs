fn main() {
  /*
  //example of compound variables

  //tuples
  let tup : (u8, char, f32)  = (10, 'a', 10.5);
  let first = tup.0;
  println!("{}", first); 
  
  //arrays
  let arr = [10, 20, 30];
  let num1 = arr[0];
  println!("{}", num1);
  */
  
  // let (mut c, mut d) : (i128, i128) = (10, 10);
  // println!("{}", add(c, d));
  
  //control flow
  
  //if else
  // let x = 5;
  // if x == 5 {
  //   println!("x is 5");
  // }
  // if x != 5 {
  //   println!("x is not 5");
  // }
  
  // //while loop
  // let mut x = 0;
  // let result = loop {
  //   x += 1;
  //   println!("x = {}", x);
  //   if x == 3 {
  //     break x * 2;
  //   }
  // };
  // println!("result = {}", result);
  // x = 0;
  // while x < 3 {
  //   x += 1;
  //   if x == 3 {
  //     break;
  //   }
  // }
  // println!("x = {}", x);
  
  // //for loop
  // let arr = [10, 20, 30, 40, 50, 60, 70, 80];
  // for item in arr.iter() {
  //   println!("value = {}", item);
  // }
  
  // let x: i32 = 10;
  // let y = 5.0;
  // println!("x + y = {}", (x as f64) + y);
  
  //ownerships
  
  // let s = String::from18("distiled");
  // let t = s;
  // println!("s = {}", s);
  // println!("t = {}", t);
  
  let s = String::from("distile is good");
  let w1 = get_last(&s);
  println!("w1 = {}", w1);
}

fn get_last(s : &String) -> &str {
  return &s[s.len() - 1..];
}

// fn add(mut a : i128, mut b : i128) -> i128 {
//   a + b
// }
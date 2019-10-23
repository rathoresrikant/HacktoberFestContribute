use std::io;

fn main() {
    println!("Enter number value: ");
    let mut input = String::new();
    io::stdin().read_line(&mut input).ok().expect("failed to read line");
    let val: u64 = input.trim().parse().expect("Please type a number");
    println!("Catalan number is: {}", catalan(val));
}

fn catalan(n: u64) -> u64 {
    if n == 0 || n == 1 {
        return 1;
    }    

    let mut catalan_list = Vec::new();
    catalan_list.push(1);
    catalan_list.push(1);

    for index in 2..(n+1) {
        catalan_list.push(0);
        for other_index in 0..index {
            catalan_list[index as usize] = catalan_list[index as usize] 
            + catalan_list[other_index  as usize] * catalan_list[(index - other_index - 1)  as usize];
        }
    }
    return catalan_list[n as usize];
}
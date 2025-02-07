use std::io::{self, BufRead};

fn compute_cycle_length(mut n: i32) -> i32 {
    let mut cycle_length = 1;

    while n != 1 {
        n = if n & 1 == 0 { n >> 1 } else { n * 3 + 1 };
        cycle_length += 1;
    }

    cycle_length
}

fn main() {
    let stdin = io::stdin();
    let handle = stdin.lock();

    for line in handle.lines() {
        let line = line.unwrap();
        let parts: Vec<i32> = line
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();
        let start = parts[0];
        let stop = parts[1];
        let mut max = 0;

        for i in start..stop {
            let len = compute_cycle_length(i);
            if len > max {
                max = len;
            }
        }

        println!("{} {} {}", start, stop, max);
    }
}

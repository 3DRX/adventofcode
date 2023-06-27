use std::{fs::File, io::{BufReader, BufRead}};

mod day4;

fn main() {
    day4::phase_2(read_input("io/in.txt"));
}

fn read_input(file_path: &str) -> Vec<String> {
    let file = File::open(file_path).expect("File not found");
    let reader = BufReader::new(file);
    let mut lines: Vec<String> = vec![];
    for line in reader.lines() {
        lines.push(line.unwrap());
    }
    return lines;
}

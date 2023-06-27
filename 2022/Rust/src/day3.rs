use std::{collections::HashSet, vec};

pub fn phase_1(lines: Vec<String>) {
    let mut chars: Vec<char> = vec![];
    let mut first_half_set: HashSet<char> = HashSet::new();
    for line in lines {
        let first_half: &str = &line[0..line.len() / 2];
        let second_half: &str = &line[line.len() / 2..line.len()];
        for char in first_half.chars() {
            first_half_set.insert(char);
        }
        for char in second_half.chars(){
            if first_half_set.contains(&char) {
                chars.push(char);
                first_half_set.clear();
                break;
            }
        }
    }
    let mut result: u32 = 0;
    for char in chars {
        if char.is_lowercase(){
            result += char.to_ascii_lowercase() as u32 - char::from('a') as u32 + 1;
        }
        else{
            result += char.to_ascii_uppercase() as u32 - char::from('A') as u32 + 27;
        }
    }
    println!("result: {}", result);
}

pub fn phase_2(lines: Vec<String>) {
    let mut divided_lines: Vec<[&String; 3]> = vec![];
    for i in 0..lines.len() / 3 {
        divided_lines.push([
                           &lines[i * 3],
                           &lines[i * 3 + 1],
                           &lines[i * 3 + 2],
        ]);
    }
    let mut chars: Vec<char> = vec![];
    let mut set_1: HashSet<char> = HashSet::new();
    let mut set_2: HashSet<char> = HashSet::new();
    for group in divided_lines{
        for char in group[0].chars(){
            set_1.insert(char);
        }
        for char in group[1].chars(){
            set_2.insert(char);
        }
        for char in group[2].chars(){
            if set_1.contains(&char) && set_2.contains(&char){
                chars.push(char);
                set_1.clear();
                set_2.clear();
                break;
            }
        }
    }
    let mut result: u32 = 0;
    for char in chars {
        if char.is_lowercase(){
            result += char.to_ascii_lowercase() as u32 - char::from('a') as u32 + 1;
        }
        else{
            result += char.to_ascii_uppercase() as u32 - char::from('A') as u32 + 27;
        }
    }
    println!("result: {}", result);
}

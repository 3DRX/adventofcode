pub fn phase_1(lines: Vec<String>) {
    let mut total: u32 = 0;
    for i in 0..lines.len() {
        let parsed_line: Vec<char> = lines[i]
            .split(" ")
            .map(|x| x.chars().collect::<Vec<char>>()[0])
            .collect();
        total += parsed_line[1].to_ascii_uppercase() as u32 - char::from('X') as u32 + 1;
        total += match_result_1(parsed_line[0], parsed_line[1]);
    }
    println!("Total: {}", total);
}

fn match_result_1(a: char, b: char) -> u32 {
    if a == 'A' {
        if b == 'X' {
            return 3;
        } else if b == 'Y' {
            return 6;
        } else {
            return 0;
        }
    } else if a == 'B' {
        if b == 'X' {
            return 0;
        } else if b == 'Y' {
            return 3;
        } else {
            return 6;
        }
    } else {
        if b == 'X' {
            return 6;
        } else if b == 'Y' {
            return 0;
        } else {
            return 3;
        }
    }
}

pub fn phase_2(lines: Vec<String>) {
    let mut total: u32 = 0;
    for i in 0..lines.len() {
        let parsed_line: Vec<char> = lines[i]
            .split(" ")
            .map(|x| x.chars().collect::<Vec<char>>()[0])
            .collect();
        total += 3 * (parsed_line[1].to_ascii_uppercase() as u32 - char::from('X') as u32);
        total += get_choice(parsed_line[0], parsed_line[1]).to_ascii_uppercase() as u32 - char::from('A') as u32 + 1;
    }
    println!("Total: {}", total);
}

fn get_choice(a: char, b: char) -> char {
    if a == 'A' {
        if b == 'X' {
            return 'C';
        } else if b == 'Y' {
            return 'A';
        } else {
            return 'B';
        }
    } else if a == 'B' {
        if b == 'X' {
            return 'A';
        } else if b == 'Y' {
            return 'B';
        } else {
            return 'C';
        }
    } else {
        if b == 'X' {
            return 'B';
        } else if b == 'Y' {
            return 'C';
        } else {
            return 'A';
        }
    }
}

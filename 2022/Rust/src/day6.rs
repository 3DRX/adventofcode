pub fn phase_1(lines: Vec<String>) {
    assert!(lines.len() == 1);
    let mut pairs: Vec<(char, u32)> = vec![];
    for i in 0..4 {
        let char = lines[0].chars().nth(i).unwrap();
        let mut contains: bool = false;
        for pair in &mut pairs {
            if pair.0 == char {
                pair.1 += 1;
                contains = true;
            }
        }
        if !contains {
            pairs.push((char, 1));
        }
    }
    if pairs.len() == 4 {
        println!("ans: {}", 5);
        return;
    }
    for i in 4..lines[0].chars().count() {
        // println!("i: {}", i);
        let char = lines[0].chars().nth(i).unwrap();
        let mut contains: bool = false;
        for pair in &mut pairs {
            if pair.0 == char {
                pair.1 += 1;
                contains = true;
            }
        }
        if !contains {
            pairs.push((char, 1));
        }
        let out_of_window_char = lines[0].chars().nth(i - 4).unwrap();
        // println!("out_of_window_char: {}", out_of_window_char);
        let mut j: u32 = 0;
        loop {
            if j >= pairs.len() as u32 {
                break;
            }
            let pair = &mut pairs[j as usize];
            if pair.0 == out_of_window_char {
                if pair.1 >= 2 {
                    pair.1 -= 1;
                } else {
                    pairs.remove(j as usize);
                }
            }
            j += 1;
        }
        // println!("pairs: {:?}", pairs);
        if pairs.len() == 4 {
            println!("ans: {}", i + 1);
            break;
        }
    }
}

pub fn phase_2(lines: Vec<String>) {
    assert!(lines.len() == 1);
    let mut pairs: Vec<(char, u32)> = vec![];
    for i in 0..14 {
        let char = lines[0].chars().nth(i).unwrap();
        let mut contains: bool = false;
        for pair in &mut pairs {
            if pair.0 == char {
                pair.1 += 1;
                contains = true;
            }
        }
        if !contains {
            pairs.push((char, 1));
        }
    }
    if pairs.len() == 14 {
        println!("ans: {}", 15);
        return;
    }
    for i in 14..lines[0].chars().count() {
        // println!("i: {}", i);
        let char = lines[0].chars().nth(i).unwrap();
        let mut contains: bool = false;
        for pair in &mut pairs {
            if pair.0 == char {
                pair.1 += 1;
                contains = true;
            }
        }
        if !contains {
            pairs.push((char, 1));
        }
        let out_of_window_char = lines[0].chars().nth(i - 14).unwrap();
        // println!("out_of_window_char: {}", out_of_window_char);
        let mut j: u32 = 0;
        loop {
            if j >= pairs.len() as u32 {
                break;
            }
            let pair = &mut pairs[j as usize];
            if pair.0 == out_of_window_char {
                if pair.1 >= 2 {
                    pair.1 -= 1;
                } else {
                    pairs.remove(j as usize);
                }
            }
            j += 1;
        }
        // println!("pairs: {:?}", pairs);
        if pairs.len() == 14 {
            println!("ans: {}", i + 1);
            break;
        }
    }
}

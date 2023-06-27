pub fn phase_1(lines: Vec<String>) {
    // read column size n
    let mut blank_line_index: usize = 0;
    for i in 0..lines.len() {
        if lines[i] == "" {
            blank_line_index = i;
            break;
        }
    }
    let n: u32 = (lines[blank_line_index - 2].len() as u32 + 1) / 4;
    assert!(n == 9 || n == 3);
    // read data of each column
    let mut crane: Crane = Crane { data: vec![] };
    for _ in 0..n {
        crane.data.push(vec![]);
    }
    for i in 0..(blank_line_index - 1) {
        Crane::add_from_line(&mut crane, &lines[i]);
    }
    // read and execute commands
    for i in (blank_line_index + 1)..lines.len() {
        let splitted: Vec<&str> = lines[i].trim().split(" ").collect();
        let move_n: u32 = splitted[1].parse().unwrap();
        let from: u32 = splitted[3].parse().unwrap();
        let to: u32 = splitted[5].parse().unwrap();
        for _ in 0..move_n {
            let temp = crane.data[from as usize - 1].pop().unwrap();
            crane.data[to as usize - 1].push(temp);
        }
    }
    // output result
    let res: String = crane.data.into_iter().map(|x| x[x.len() - 1]).collect();
    println!("result: {}", res);
}

pub fn phase_2(lines: Vec<String>) {
    // read column size n
    let mut blank_line_index: usize = 0;
    for i in 0..lines.len() {
        if lines[i] == "" {
            blank_line_index = i;
            break;
        }
    }
    let n: u32 = (lines[blank_line_index - 2].len() as u32 + 1) / 4;
    assert!(n == 9 || n == 3);
    // read data of each column
    let mut crane: Crane = Crane { data: vec![] };
    for _ in 0..n {
        crane.data.push(vec![]);
    }
    for i in 0..(blank_line_index - 1) {
        Crane::add_from_line(&mut crane, &lines[i]);
    }
    // read and execute commands
    for i in (blank_line_index + 1)..lines.len() {
        let splitted: Vec<&str> = lines[i].trim().split(" ").collect();
        let move_n: u32 = splitted[1].parse().unwrap();
        let from: u32 = splitted[3].parse().unwrap();
        let to: u32 = splitted[5].parse().unwrap();
        let mut stack: Vec<char> = vec![];
        for _ in 0..move_n {
            stack.push(crane.data[from as usize - 1].pop().unwrap());
        }
        while !stack.is_empty() {
            crane.data[to as usize - 1].push(stack.pop().unwrap());
        }
    }
    // output result
    let res: String = crane.data.into_iter().map(|x| x[x.len() - 1]).collect();
    println!("result: {}", res);
}

struct Crane {
    data: Vec<Vec<char>>,
}

impl Crane {
    fn add_from_line(crane: &mut Crane, line: &String) {
        for i in 0..crane.data.len() {
            let line_index = Crane::_get_line_index(i + 1);
            let the_char = line.chars().nth(line_index).unwrap();
            if the_char == ' ' {
                continue;
            }
            crane.data[i].insert(0, the_char);
        }
    }

    fn _get_line_index(col_index: usize) -> usize {
        1 + 4 * (col_index - 1)
    }
}

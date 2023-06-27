pub fn phase_1(lines: Vec<String>) {
    let mut pairs: Vec<[Elf; 2]> = vec![];
    for line in lines {
        let temp: Vec<&str> = line.split(",").collect::<Vec<&str>>();
        let first_half: Vec<u32> = temp[0]
            .split("-")
            .map(|x| x.parse::<u32>().unwrap())
            .collect::<Vec<u32>>();
        let second_half: Vec<u32> = temp[1]
            .split("-")
            .map(|x| x.parse::<u32>().unwrap())
            .collect::<Vec<u32>>();
        pairs.push([
            Elf {
                low: first_half[0],
                high: first_half[1],
            },
            Elf {
                low: second_half[0],
                high: second_half[1],
            },
        ])
    }
    let res = pairs
        .into_iter()
        .filter(|x| x[0].contains(&x[1]) || x[1].contains(&x[0]))
        .count();
    println!("result: {}", res);
}

pub fn phase_2(lines: Vec<String>) {
    let mut pairs: Vec<[Elf; 2]> = vec![];
    for line in lines {
        let temp: Vec<&str> = line.split(",").collect::<Vec<&str>>();
        let first_half: Vec<u32> = temp[0]
            .split("-")
            .map(|x| x.parse::<u32>().unwrap())
            .collect::<Vec<u32>>();
        let second_half: Vec<u32> = temp[1]
            .split("-")
            .map(|x| x.parse::<u32>().unwrap())
            .collect::<Vec<u32>>();
        pairs.push([
            Elf {
                low: first_half[0],
                high: first_half[1],
            },
            Elf {
                low: second_half[0],
                high: second_half[1],
            },
        ])
    }
    let res = pairs.into_iter().filter(|x| x[0].overlaps(&x[1])).count();
    println!("result: {}", res);
}

struct Elf {
    low: u32,
    high: u32,
}

impl Elf {
    fn overlaps(&self, other: &Elf) -> bool {
        return self.low <= other.high && self.high >= other.low;
    }

    fn contains(&self, other: &Elf) -> bool {
        return self.low <= other.low && self.high >= other.high;
    }
}

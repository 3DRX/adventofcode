
pub fn phase_2(line: Vec<String>) {
    let mut top_three: Vec<u32> = vec![0, 0, 0];
    let mut cal: u32 = 0;
    for i in 0..line.len() {
        if line[i] == ""{
            for j in 0..3 {
                if cal > top_three[j] {
                    top_three.insert(j, cal);
                    top_three.pop();
                    break;
                }
            }
            cal = 0;
        }
        else{
            cal += line[i].parse::<u32>().unwrap();
        }
    }
    println!("Max cal: {}", top_three[0] + top_three[1] + top_three[2]);
}

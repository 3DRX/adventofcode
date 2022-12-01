const fs = require('fs');
const lines = fs.readFileSync('../input.io', {encoding: 'utf-8'}).split('\n');

var oxygen = [[]];
var co2 = [[]];
for (let line of lines) {
    oxygen[0].push(line);
    co2[0].push(line);
}

for (let i = 0; i < lines[0].length; i++) {
    let one = 0;
    let zero = 0;
    for (let line of oxygen[oxygen.length - 1]) {
        if (line[i] === '0') {
            zero++;
        } else {
            one++;
        }
    }
    if (one === zero) {
        let temp = [];
        for (let line of oxygen[oxygen.length - 1]) {
            if (line[i] === '1') {
                temp.push(line);
            }
        }
        oxygen.push(temp);
    } else if (one + zero === 1) {
        break;
    } else if (one > zero) {
        let temp = [];
        for (let line of oxygen[oxygen.length - 1]) {
            if (line[i] === '1') {
                temp.push(line);
            }
        }
        oxygen.push(temp);
    } else {
        let temp = [];
        for (let line of oxygen[oxygen.length - 1]) {
            if (line[i] === '0') {
                temp.push(line);
            }
        }
        oxygen.push(temp);
    }
}
for (let i = 0; i < lines[0].length; i++) {
    let one = 0;
    let zero = 0;
    for (let line of co2[co2.length - 1]) {
        if (line[i] === '0') {
            zero++;
        } else {
            one++;
        }
    }
    if (one === zero) {
        let temp = [];
        for (let line of co2[co2.length - 1]) {
            if (line[i] === '0') {
                temp.push(line);
            }
        }
        console.log('temp:' + temp);
        co2.push(temp);
    } else if (one + zero === 1) {
        break;
    } else if (one < zero) {
        let temp = [];
        for (let line of co2[co2.length - 1]) {
            if (line[i] === '1') {
                temp.push(line);
            }
        }
        co2.push(temp);
    } else {
        let temp = [];
        for (let line of co2[co2.length - 1]) {
            if (line[i] === '0') {
                temp.push(line);
            }
        }
        co2.push(temp);
    }
}

console.log(
    parseInt(oxygen[oxygen.length - 1][0], 2) *
        parseInt(co2[co2.length - 1][0], 2)
);

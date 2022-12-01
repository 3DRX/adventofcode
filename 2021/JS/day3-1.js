const fs = require('fs');
const lines = fs.readFileSync('../input.io', {encoding: 'utf-8'}).split('\n');

var gamma = '';
var epsilon = '';

for (let i = 0; i < lines[0].length; i++) {
    let one = 0;
    let zero = 0;
    for (let line of lines) {
        if (line[i] === '0') {
            zero++;
        } else {
            one++;
        }
    }
    if (one > zero) {
        gamma += '1';
        epsilon += '0';
    } else {
        gamma += '0';
        epsilon += '1';
    }
}

console.log(parseInt(gamma, 2) * parseInt(epsilon, 2));

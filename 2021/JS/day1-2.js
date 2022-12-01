const fs = require('fs');
const lines = fs.readFileSync('../input.io', {encoding: 'utf-8'}).split('\n');

var count = 0;
var buff = [parseInt(lines[0]), parseInt(lines[0]), parseInt(lines[0])];

for (var i = 3; i < 2000; i++) {
    if (buff[0] < parseInt(lines[i])) {
        count++;
    }
    buff.shift();
    buff[2] = parseInt(lines[i]);
}

console.log(count);

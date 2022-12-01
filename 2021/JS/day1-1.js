const fs = require('fs');

const lines = fs.readFileSync('../input.io', {encoding: 'utf-8'}).split('\n');

console.log(lines);

var count = 0;

var lastNumber = -1;

lines.forEach(function (line) {
    if (lastNumber != -1 && parseInt(line) > lastNumber) {
        count++;
    }
    lastNumber = parseInt(line);
});

console.log(count);

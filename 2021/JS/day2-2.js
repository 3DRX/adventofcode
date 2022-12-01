const fs = require('fs');
const lines = fs.readFileSync('../input.io', {encoding: 'utf-8'}).split('\n');

const commands = [];
for (let line of lines) {
    commands.push({
        command: line.split(' ')[0],
        number: parseInt(line.split(' ')[1])
    });
}

var horizontal_position = 0;
var depth = 0;
var aim = 0;

for (let command of commands) {
    if (command.command === 'forward') {
        horizontal_position += command.number;
        depth += aim * command.number;
    } else if (command.command === 'down') {
        aim += command.number;
    } else if (command.command === 'up') {
        aim -= command.number;
    }
}

console.log(horizontal_position * depth);

const fs = require('fs');
const lines = fs.readFileSync('../input.io', { encoding: 'utf-8' }).split('\n');

const inputs = [
    79, 9, 13, 43, 53, 51, 40, 47, 56, 27, 0, 14, 33, 60, 61, 36, 72, 48, 83, 42, 10, 86, 41, 75, 16, 80, 15, 93, 95, 45, 68, 96, 84, 11, 85, 63, 18, 31, 35, 74, 71, 91, 39, 88, 55, 6, 21, 12, 58, 29, 69, 37, 44, 98, 89, 78, 17, 64, 59, 76, 54, 30, 65, 82, 28, 50, 32, 77, 66, 24, 1, 70, 92, 23, 8, 49, 38, 73, 94, 26, 22, 34, 97, 25, 87, 19, 57, 7, 2, 3, 46, 67, 90, 62, 20, 5, 52, 99, 81, 4
]

var grids = []
var iptgrid = []

for (var line of lines) {
    var numLine = []
    if (line === '') {
        grids.push(iptgrid);
        iptgrid = []
    }
    else {
        for (var number of line.split(' ')) {
            if (number !== '') {
                numLine.push({
                    number: parseInt(number),
                    isLit: false
                });
            }
        }
        iptgrid.push(numLine)
    }
}

grids.pop()

const bingo = () => {
    for (var grid of grids) {
        for (var i = 0; i < 5; i++) {
            if (grid[i][0].isLit && grid[i][1].isLit && grid[i][2].isLit && grid[i][3].isLit && grid[i][4].isLit) {
                return grid;
            }
        }
        for (var i = 0; i < 5; i++) {
            if (grid[0][i].isLit && grid[1][i].isLit && grid[2][i].isLit && grid[3][i].isLit && grid[4][i].isLit) {
                return grid;
            }
        }
    }
    return null;
}

for (var ipt of inputs) {
    for (var grid of grids) {
        for (var line of grid) {
            for (var item of line) {
                if (item.number === ipt) {
                    item.isLit = true;
                }
            }
        }
    }
    var theGrid = bingo()
    var ans = 0
    if (theGrid !== null) {
        for (var line of theGrid) {
            for (num of line) {
                if (num.isLit === false) {
                    ans += num.number
                }
            }
        }
        console.log(ans * ipt)
        break
    }
}


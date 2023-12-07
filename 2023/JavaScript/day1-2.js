const isnum = (c) => c >= "0" && c <= "9";
const numwords = [
  "one",
  "two",
  "three",
  "four",
  "five",
  "six",
  "seven",
  "eight",
  "nine",
];
console.log(
  require("node:fs")
    .readFileSync("./in", "utf8")
    .slice(0, -1)
    .split("\n")
    .map((line) => {
      let first_char = line.charAt(0);
      let last_char = first_char;
      line.split("").forEach((char) => {
        if (isnum(char)) {
          if (!isnum(first_char)) {
            first_char = char;
          }
          last_char = char;
        }
      });
      return parseInt(`${first_char}${last_char}`);
    })
    .reduce((a, b) => a + b, 0),
);

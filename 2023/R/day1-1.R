lines <- readLines("./in")

isnum <- function(x) return(!is.na(as.numeric(x)))

sum <- 0

for (line in lines) {
  chars <- strsplit(line, "")[[1]]
  first_char <- chars[1]
  last_char <- chars[1]
  for (char in chars) {
    if (isnum(char)) {
      if (!isnum(first_char)) {
        first_char <- char
      }
      last_char <- char
    }
  }
  sum <- sum + as.numeric(paste(first_char, last_char, sep = ""))
}

print(sum)

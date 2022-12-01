import fileinput

def main():
    prev = -1
    total = 0
    data = []
    for line in fileinput.input(files="../input.io"):
        if line == '\n':
            # skip
            continue
        else:
            # save input in list
            data.append(int(line))
            pass
        pass
    for index in range(0, 1998):
        newSum = data[index] + data[index+1] + data[index+2]
        if prev == -1:
            pass
        elif newSum > prev:
            total += 1
            pass
        prev = newSum
        pass
    print(total)
    pass

if __name__ == '__main__':
    main()
    pass

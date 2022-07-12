import fileinput

def strategy(ins:str, X:int):
    global depth
    global horizontal_position
    global aim
    if ins == 'forward':
        horizontal_position += X
        depth += aim * X
        pass
    elif ins == 'down':
        aim += X
        pass
    else:
        aim -= X
        pass
    pass

def main():
    global depth
    global horizontal_position
    global aim
    depth = int(0)
    horizontal_position = int(0)
    aim = int(0)
    for line in fileinput.input(files="../input.io"):
        # trim the '\n'
        line = line[:len(line)-1]
        instruction, X = line.split(' ')[0], int(line.split(' ')[1])
        strategy(instruction, X)
        pass
    print('ans: ', depth * horizontal_position)
    pass

if __name__ == "__main__":
    main()
    pass

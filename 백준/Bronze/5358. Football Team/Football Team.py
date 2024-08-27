import sys

lines = sys.stdin.read().splitlines()

for line in lines :
    line = line.replace('e','#').replace('i','e').replace('#','i')
    line = line.replace('E','#').replace('I','E').replace('#','I')

    print(line)
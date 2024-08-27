T = int(input())

for _ in range(T) :
    equation = list(input().split())
    result = float(equation[0])
    for i in range(len(equation)) :
        if equation[i] == '@' :
            result *= 3
        elif equation[i] == '%' :
            result += 5
        elif equation[i] == '#' :
            result -= 7
    print("{:.2f}".format(result))        

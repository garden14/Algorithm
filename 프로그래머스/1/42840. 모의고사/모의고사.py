def solution(answers):
    answer = []
    result = [0] * 3
    first = [ 1, 2, 3, 4, 5 ]
    second = [ 2, 1, 2, 3, 2, 4, 2, 5 ]
    third = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5 ]
    
    for i in range(len(answers)) : 
        if answers[i] == first[i%5] :
            result[0] += 1
        if answers[i] == second[i%8] :
            result[1] += 1
        if answers[i] == third[i%10] :
            result[2] += 1
    
    for i, num in enumerate(result) :
        if num == max(result) :
            answer.append(i + 1)
    
    return answer
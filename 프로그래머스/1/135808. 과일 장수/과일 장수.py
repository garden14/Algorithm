
def solution(k, m, score):
    answer = 0
    i = 0
    
    score.sort(reverse = True)
            
    while (i + m <= len(score) ) :        
        answer += (min(score[i : i + m]) * m)
        i += m   
    
    return answer
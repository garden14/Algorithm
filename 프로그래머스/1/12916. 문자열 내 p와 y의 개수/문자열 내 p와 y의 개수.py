def solution(s):
    answer = True
    s = s.upper()
    countP = s.count('P')
    countY = s.count('Y')

    return True if countP == countY else False
def solution(s):
    st = []
    
    for a in s :
        if a == '(' :
            st.append(a)
        else :
            if len(st) == 0 :
                return False
            else :
                st.pop()  
    if len(st) != 0 :
        return False
    return True